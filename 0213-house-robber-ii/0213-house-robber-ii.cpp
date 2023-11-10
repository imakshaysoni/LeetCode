class Solution {
public:
    int rob(vector<int>& nums) {
        
        
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
        
        int op2 = robber(0, n-1, nums, dp1);
        int op1 = robber(1, n, nums, dp2);
        return max(op1, op2);
    }
    
    int robber(int index, int n, vector<int> nums, vector<int> &dp){
        
        if(index>=n) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        int op1 = robber(index+1, n, nums, dp);
        int op2 = nums[index] + robber(index+2, n, nums, dp);
        dp[index]=max(op1,op2);
        return dp[index];
    }
};