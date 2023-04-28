class Solution {
public:
    int rob(vector<int>& nums) {
        
       int n = nums.size();
        if(n==1) return nums[0];
        // if(n==2) return max(nums[0],nums[1]);
        // if(n==3) return max(nums[0],max(nums[1],nums[2]));
        vector<int> dp1(nums.size()+1, -1);
        vector<int> dp2(nums.size()+1, -1);
        
        int op1 = helper(nums,1,nums.size(), dp1);
        int op2 = helper(nums,0,nums.size()-1,dp2);
        // cout<<op1<<" "<<op2;
        
        return max(op1,op2);
        
//         vector<int> dp(nums.size()+2,0);
//         for(int i=nums.size()-1;i>=0;i--){
//             int op1 = nums[i]+dp[i+2];
//             int op2 = dp[i+1];
//             dp[i] = max(op1,op2);
//         }
        
//         return dp[0];
    }
    
//     Recursive
    int helper(vector<int> &nums, int i, int n, vector<int> &dp){
       
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int op1, op2;
        op1 = nums[i] + helper(nums, i+2, n, dp);
        op2 = helper(nums,i+1, n, dp);
        dp[i] = max(op1,op2);
        
        return dp[i];      
        
    }
    
};