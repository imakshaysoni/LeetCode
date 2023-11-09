class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         vector<int> dp(s.size()+1,-1);
        unordered_set<string> dict;
        for(auto it: wordDict){
            dict.insert(it);
        }
        return solve(s, dict, 0, dp);
        
    }    
    bool solve(string s, unordered_set<string> &dict, int index, vector<int> &dp){
    
        if(index>=s.size())
        {
            dp[index]=1;
            return dp[index];
        };
        if(dp[index]!=-1) return dp[index];
        string word = "";
        for(int i=index;i<s.size();i++){
            word += s[i];
            if(dict.find(word)!=dict.end()){
                if(solve(s, dict, i+1, dp)){
                  dp[index]=1;
                    return dp[index];
                } 
            }
        }
        dp[index]=0;
        return dp[index];
    }
};