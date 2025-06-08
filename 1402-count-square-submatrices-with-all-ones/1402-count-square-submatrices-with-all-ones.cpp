class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        for(int row=0;row<rows;row++){
            for(int col =0;col<cols;col++){
                if(matrix[row][col]==1){
                    ans += solve(matrix, row, col, rows, cols);
                }
            }
        }
        return ans;
        
    }

    int solve(vector<vector<int>> &matrix, int row, int col, int rows, int cols){
        if(row<0 || row>=rows || col<0 || col>=cols || matrix[row][col]==0) return 0;

        int op1 = 1 + solve(matrix, row, col+1, rows, cols);
        int op2 = 1 + solve(matrix, row+1, col, rows, cols);
        int op3 = 1 + solve(matrix, row+1, col+1, rows, cols);
        
        return min(op1, min(op2, op3));

    }
};