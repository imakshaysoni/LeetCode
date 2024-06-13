class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int l1 = text1.size();
        int l2 = text2.size();
        
        // vector<vector<int>> dp(l1, vector<int>(l2, -1));
        // return lcs(text1, text2, l1-1, l2-1, dp);
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // int op1 = dp[i-1][j-1];
                    int op2 = dp[i-1][j];
                    int op3 = dp[i][j-1];
                    dp[i][j] = max(op2, op3);
                }
            }
        }
        return dp[l1][l2];
        
        
    }
    int lcs(string text1, string text2, int l1, int l2, vector<vector<int>> &dp){
        
        if(l2<0 or l1<0) return 0;
        
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        
        //Option1
        if(text1[l1]==text2[l2]){
            return dp[l1][l2] = 1 + lcs(text1, text2, l1-1, l2-1, dp);
        }
        else{
            int op1 = lcs(text1, text2, l1-1, l2-1, dp);
            int op2 = lcs(text1, text2, l1-1, l2, dp);
            int op3 = lcs(text1, text2, l1, l2-1, dp);
            return dp[l1][l2] = max(op1, max(op2, op3));
        }
        
        
        
    }
};