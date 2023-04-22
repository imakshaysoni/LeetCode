class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return helper(nums, target, 0, dp);
        
    }
    
    bool helper(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
        
        
        if(i>=nums.size() || target < 0) return false;
        if(target==0) return true;
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        
//         Take one element
        bool op1 = helper(nums, target-nums[i], i+1, dp);
        bool op2 = helper(nums, target, i+1, dp);
        dp[i][target] = op1 || op2;
        return dp[i][target];
        
        
        
    }
};