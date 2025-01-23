class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int total = 0;
        for(auto it: cardPoints) total+=it;
        
        if(cardPoints.size()==k) return total;
        int right=0, left=0;
        int sum = 0;
        int ans = 0;
        while(right<cardPoints.size()){


            sum += cardPoints[right];
            if(right-left+1 == cardPoints.size()-k)
            {
                ans = max(ans, total-sum);
                sum-=cardPoints[left];
                left++;
            }
            right++;
        }

    return ans;
    }
};