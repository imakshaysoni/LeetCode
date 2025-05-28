class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> st;
        solve(1, n, st, k);
        return res;
    }

    void solve(int i, int n, vector<int> &st, int k){
            if(st.size()==k) {
                res.push_back(st);
                return;
            }
            if(i>n) return;
            
            // pick
            st.push_back(i);
            solve(i+1, n, st, k);
            // not pick
            st.pop_back();
            solve(i+1, n, st, k);
    }
};