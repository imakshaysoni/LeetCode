class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        solve(nums, target, 0, 0, ans);
        return ans;
    }

    void solve(vector<int> &nums, int target, int idx, int sum, int &ans){

        if(idx == nums.size()){
            if(sum == target)
                ans++;
            return;
        }

        //op1
        solve(nums, target, idx+1, sum + nums[idx], ans);
        
        //op2
        solve(nums, target, idx+1, sum - nums[idx], ans);

        return;

    }
};