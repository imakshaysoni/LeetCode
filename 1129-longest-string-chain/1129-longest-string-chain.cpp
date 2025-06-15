class Solution {
public:

    bool static comp(string s1, string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        for(auto it: words) cout<<it.size()<<" ";
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        return solve(words, 0, -1, dp);
        
    }

    bool isPossible(string curr, string prev){

        int n1 = curr.size();
        int n2 = prev.size();
        int first = 0;
        int second = 0;
        while(first < n2 and second < n1){
            if(prev[first]==curr[second]){
                first++;
                second++;
            }
            else{
                second++;
            }
        }
        if(first==n2) return true;
        return false;
    }

    int solve(vector<string> &words, int idx, int prev, vector<vector<int>> &dp){
        
        if(idx >= words.size()) return 0;
        if(prev!=-1 and dp[idx][prev]!=-1) return dp[idx][prev];
        int take = 0;
        if(prev==-1 or words[idx].size() == words[prev].size()+1 and isPossible(words[idx], words[prev])){
            take = 1 + solve(words, idx+1, idx, dp);
        }
        int skip = solve(words, idx+1, prev, dp);
        if(prev!=-1) return dp[idx][prev] = max(take, skip);
        return max(take, skip);
    }
}; 