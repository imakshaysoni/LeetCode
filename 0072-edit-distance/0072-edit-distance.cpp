class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(word1, word2, m-1, n-1, dp);
        
    }
    

    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        
//         Base Case
//         If S1 Get Exsaust
        if(i<0) return j+1;
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
};