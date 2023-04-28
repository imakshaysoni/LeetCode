class Solution {
public:
    int rob(vector<int>& nums) {
        
       
        // vector<int> dp(nums.size()+1, -1);
        // int ans = helper(nums,0, dp);
        // return ans;
        
        vector<int> dp(nums.size()+2,0);
        for(int i=nums.size()-1;i>=0;i--){
            int op1 = nums[i]+dp[i+2];
            int op2 = dp[i+1];
            dp[i] = max(op1,op2);
        }
        
        return dp[0];
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