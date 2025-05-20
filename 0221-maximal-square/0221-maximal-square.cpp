class Solution {
public:
    int maxArea = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        // int maxArea = -1e9;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(matrix[row][col]=='1'){
                    solve(matrix, row, col, rows, cols, dp);
                    //maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;

    }

    int solve(vector<vector<char>> &matrix, int row, int col, int rows, int cols
    , vector<vector<int>>&dp){

            //base conditions
            if(row < 0 || row>=rows ||
            col < 0 || col >=cols || matrix[row][col]=='0') return 0;

            if(dp[row][col]!=-1) return dp[row][col];
            // Options
            int op1 = 1 + solve(matrix, row, col+1, rows, cols, dp);
            int op2 = 1 + solve(matrix, row+1, col, rows, cols, dp);
            int op3 = 1 + solve(matrix, row+1, col+1, rows, cols, dp);

            int mini = min(op1, min(op2, op3));
            dp[row][col] = mini;
            maxArea = max(maxArea, mini*mini);
            
            return mini;


    }
};