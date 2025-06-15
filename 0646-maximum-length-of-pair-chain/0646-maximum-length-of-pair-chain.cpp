class Solution {
public:

    bool static comp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int n = pairs.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        return solve(pairs, 0, -1, dp);
    }

    int solve(vector<vector<int>> &pairs, int idx, int prev, vector<vector<int>> &dp){
        
        if(idx >= pairs.size()) return 0;
        if(prev!=-1 and dp[idx][prev]!=-1) return dp[idx][prev];
        int take = 0;
        if(prev==-1 or pairs[idx][0] > pairs[prev][1]){
            take = 1 + solve(pairs, idx+1, idx, dp);
        }
        int skip = solve(pairs, idx+1, prev, dp);
        if(prev!=-1) return dp[idx][prev] = max(take, skip);
        return max(take, skip);



    }
};