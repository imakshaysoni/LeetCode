class Solution {
public:
    bool canPartition(vector<int>& nums) {
     
        int sum=0;
        vector<int> subset;
        for(auto x: nums){
            sum+=x;
        }
        if(sum%2 & 1) return false;
        int target = sum/2;
        
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        
        return helper(nums,target,0, dp);
        
    }
    
    
    
    bool helper(vector<int> &nums,int target, int i, vector<vector<int>> &dp){
        
        if(target==0) return true;
        if(target<0) return false;
        
        if(i>=nums.size()) return false;
//          Include ith term
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool op1 = helper(nums,target-nums[i],i+1, dp);
        bool op2 = helper(nums, target,i+1, dp);        
        dp[i][target] = op1 || op2;
        return op1 || op2;                 
        
        
           
    }
    
};