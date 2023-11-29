class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp (m, vector<int>(n,0));
        return solve(dp, 0, 0);
    }
    
    int solve(vector<vector<int>> &dp, int i, int j){
        if(i<0 || i>=dp.size() || j<0 || j>=dp[0].size()) return 0;
        if(i==dp.size()-1 and j==dp[0].size()-1) return 1;
        if(dp[i][j]!=0) return dp[i][j];
        int op1 = solve(dp,i+1,j); // move down
        int op2 = solve(dp, i, j+1); // Move Right
        dp[i][j] = op1 + op2;
        return dp[i][j];
    }
};