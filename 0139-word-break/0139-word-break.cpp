class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;
        for(auto it: wordDict) st.insert(it);
        vector<int> dp(s.size(), -1);
        return solve(s, st, 0, dp);
        
    }

    bool solve(string s, unordered_set<string> st, int idx, vector<int> &dp){

        if(idx>=s.size()) return true;

        if(dp[idx]!=-1) return dp[idx];

        string word = "";
        for(int index=idx; index<s.size();index++){
            word += s[index];
            if(st.find(word)!=st.end()){
                if(solve(s, st, index+1, dp)) return true;
            }
        }
        return dp[idx] = false;
    }
};