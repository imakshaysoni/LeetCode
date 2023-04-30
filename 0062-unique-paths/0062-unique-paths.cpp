class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> board(m,vector<int>(n,0));
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = helper(board, 0, 0, dp);
        // helper(board,0,0);
        return ans;
    }
    
    int helper(vector<vector<int>> &board, int i, int j, vector<vector<int>> &dp){
        int m = board.size();
        int n = board[0].size();
        
        if(i>=m || j>=n) return 0;
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        if(dp[i][j]!=0) return dp[i][j];
        
        dp[i+1][j] = helper(board, i+1,j, dp);
        dp[i][j+1] = helper(board, i, j+1, dp);
        
        return dp[i+1][j] + dp[i][j+1];
        
    }
};