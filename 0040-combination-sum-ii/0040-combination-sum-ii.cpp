class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> subset;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, subset, ans);
        return ans;

    }

    void solve(vector<int> &can, int i, int target, vector<int> &subset, vector<vector<int>> &ans){

        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(target < 0 ) return;
        if(i>=can.size()) return;

        // pick
        subset.push_back(can[i]);
        solve(can, i+1, target-can[i], subset, ans);

        subset.pop_back();
        while(i+1 < can.size() and can[i]==can[i+1]) i++;
        solve(can, i+1, target, subset, ans);


    }
};