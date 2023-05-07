class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        // Recursive 
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return helper(word1, word2, m-1, n-1, dp);
        
//         Converting into bottom up DP
        // int DP2 = bottom_up_2D(word1, word2);
        // return DP2;
        
//        1D 2 Array Space Optimized
        int DP1 = bottom_up_1D(word1, word2);
        return DP1;
        
        
    }
    
// Recursive Approch
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        
//         Base Case
//         If S1 Get Exsaust
        if(i<0) return j+1;
//         If S2 Get Exsaust
        if(j<0) return i+1;      
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) {
            int op = helper(s1,s2,i-1,j-1, dp);
            return dp[i][j] = op;
            }
            else{
            
//             Option1 Insert   
                int op1 = 1 + helper(s1,s2,i,j-1, dp);
            
//             Option2 Delete
            int op2 = 1 + helper(s1,s2,i-1, j, dp);
            
            
//             Option3 Replace
            int op3 = 1 + helper(s1,s2,i-1,j-1, dp);
            
            return dp[i][j] = min(op1, min(op2,op3));
        }
        
        
    }
    
    
//     2D Array
    int bottom_up_2D(string &word1, string &word2){
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        
        for(int j=0;j<=n;j++) dp[0][j] = j;
        for(int i=0;i<=m;i++) dp[i][0] = i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] =  1 + min(dp[i][j-1],
                                   min(dp[i-1][j],
                                       dp[i-1][j-1]));
                }
            }
        }
        
        return dp[m][n];
    }
    
        
//     1D Array More Space Optimized
    int bottom_up_1D(string &word1, string &word2){
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        
        for(int j=0;j<=n;j++) prev[j] = j;
        // for(int i=0;i<=m;i++) dp[i][0] = i; Not Required
        
        for(int i=1;i<=m;i++){
            curr[0] = i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] =  1 + min(curr[j-1],
                                   min(prev[j],
                                       prev[j-1]));
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }
};