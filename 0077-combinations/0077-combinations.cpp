class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> stt;
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<int> st;
        // for(int i=0;i<nums.size();i++) {
        //     st.clear();
        //     solve(nums, i, st, k);
        // }
        solve(nums, 0, st, k);
        return res;
    }

    void solve(vector<int> &nums, int i, vector<int> &st, int k){
            if(st.size()==k) {
                res.push_back(st);
                return;
            }
            if(i>=nums.size()) return;
            

            // pick
            st.push_back(nums[i]);
            solve(nums, i+1, st, k);
            // not pick
            st.pop_back();
            solve(nums, i+1, st, k);
    }
};