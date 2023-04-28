class Solution {
public:
    int rob(vector<int>& nums) {
        
       
        vector<int> dp(nums.size()+1, -1);
        int ans = helper(nums,0, dp);
        return ans;
        
    }
    
    int helper(vector<int> &nums, int i, vector<int> &dp){
        
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int op1, op2;
        
        op1 = nums[i] + helper(nums, i+2, dp);
        op2 = helper(nums,i+1, dp);
        dp[i] = max(op1,op2);
        return dp[i];      
        
    }
};