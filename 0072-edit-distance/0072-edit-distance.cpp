class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(word1, word2, n, m, dp);
        
        // return tabulation(word1, word2, n, m);
        return spaceOptimized(word1, word2, n, m);
    }
    
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
        
        if(j==0) return i;
        if(i==0) return j;        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(w1[i-1]==w2[j-1]){
            return dp[i][j] = solve(w1, w2, i-1, j-1, dp);
        }
        else{            
//             Insert            
            int insert_op = 1 + solve(w1, w2, i, j-1, dp);
//             Replace
            int replace_op =  1 + solve(w1, w2, i-1, j-1, dp);
//             Delete
            int delete_op = 1 + solve(w1, w2, i-1, j, dp);
            
            return dp[i][j] = min(insert_op, min(replace_op, delete_op));            
        }
    }
    
    int tabulation(string &word1, string &word2, int n, int m){
        //         Tabulation
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
//         base case
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
    
    int spaceOptimized(string &word1, string &word2, int n, int m){
        //         Tabulation
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
//         base case
        // for(int i=0;i<=n;i++) curr[0]=i;
        for(int j=0;j<=m;j++) prev[j]=j;
        // curr[0]=1;
        
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1 + min(prev[j-1], min(curr[j-1], prev[j]));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};


