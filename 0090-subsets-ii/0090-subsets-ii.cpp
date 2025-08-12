class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> final_subset;
        sort(nums.begin(), nums.end());
        solve(nums, 0, subset, final_subset);
        return final_subset;
    }

    void solve(vector<int> &nums, int idx, vector<int>&subset, vector<vector<int>>&ans){
        
        if(idx>=nums.size()){
            ans.push_back(subset);
            return;
        }


        //Option 1 Pick
        subset.push_back(nums[idx]);
        solve(nums, idx+1, subset, ans);
        subset.pop_back();

        //Option 2 not pick
        while(idx<nums.size()-1 and nums[idx]==nums[idx+1]) idx++;
        solve(nums, idx+1, subset, ans);
        return;
    }


};
