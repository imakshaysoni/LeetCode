class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
    
    bool solve(vector<int>&nums, int idx, vector<int>&dp){
        if(idx==nums.size()-1) return true;
        if(idx>=nums.size()) return false;
        if(nums[idx]==0) return false;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int steps = nums[idx];
        for(int i=1;i<=steps;i++){
            bool op1 = solve(nums, idx+i, dp);
            if(op1) return dp[idx] = true;
        }
        
        return dp[idx]=false;
    }
};