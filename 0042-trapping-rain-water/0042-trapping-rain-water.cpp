class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int leftMax = 0;
        int rightMax = 0;
        
        vector<int> left;
        vector<int> right;
        
        for(int i=0;i<n;i++){
            leftMax = max(leftMax, h[i]);
            left.push_back(leftMax);
        }
        for(int i=n-1;i>=0;i--){
            rightMax = max(rightMax, h[i]);
            right.push_back(rightMax);
        }        
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(right[n-i-1], left[i]) - h[i];
        }
        
        
        return ans;
        
    }
};