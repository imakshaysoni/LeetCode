class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totSum = 0;
        for(auto it: cardPoints) totSum+=it;
        int n = cardPoints.size();
        int left = 0;
        int right = 0;
        int sum = 0;     
        int ans = 0;
        while(right<n){
            sum += cardPoints[right];
            
            if(right-left+1 == n-k){
                ans = max(totSum-sum, ans);
                sum -= cardPoints[left];
                left++;
            }
            right++;
            
        }
        if(ans==0) return totSum;
        return ans;
    }
};