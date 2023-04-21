class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        /*
        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        std::vector<int> flag(5 * n - 2, 1);
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
    }
};

// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
        
//         vector<vector<string>> ans;
//         int row = 0;
//         vector<string> Q(n, string(n,'.'));
//         helper(Q, row, ans);
//         return ans;
        
//     }
    
    
//     void helper(vector<string> &Q, int row, vector<vector<string>> &ans){
        
//         if(row == Q.size()) return ans.push_back(Q);
        
    
//         for (int col =0;col<Q.size();col++){
//             if(isValid(Q, row, col)){
//                Q[row][col] = 'Q';
//                 helper(Q,row+1, ans);
//                 Q[row][col] = '.';
//             }
//         }
            
            
//         }
                
//     int isValid(vector<string> &Q, int row, int col){
        
        
// //         Check Columns
//         for(int i=row;i>=0;--i)
//             if(Q[i][col] == 'Q') return false;
        
// //         Check left diagone
//         for(int i=row,j=col; i>=0 && j>=0 ; i--, j--){
//             if(Q[i][j]=='Q') return false;
//         }
// //         Check right diagonal
//         for(int i=row,j=col; i>=0 && j<Q.size() ;i--,j++){
//             if(Q[i][j]=='Q') return false;
//         }
        
//         return true;
        
//         }    
// };