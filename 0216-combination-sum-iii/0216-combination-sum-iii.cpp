class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        solve(1, n, k, subset, ans);
        return ans;
        
        
    }
    void solve(int start, int n, int k, vector<int> &subset, vector<vector<int>> &ans){
        
        if(subset.size()==k){
            int sum=0;
            for(auto it: subset){
                sum+=it;
            }
            if(sum==n){
                ans.push_back(subset);
                return;
            }
            return;
        }
        if(start>9) return;        
//         Pick
        subset.push_back(start);
        solve(start+1, n, k, subset, ans);
        subset.pop_back();
        solve(start+1, n, k, subset, ans);      
    }
};