class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        int row = 0;
        vector<string> Q(n, string(n,'.'));
        helper(Q, row, ans);
        return ans;
        
    }
    
    
    void helper(vector<string> &Q, int row, vector<vector<string>> &ans){
        
        if(row == Q.size()) return ans.push_back(Q);
        
    
        for (int col =0;col<Q.size();col++){
            if(isValid(Q, row, col)){
               Q[row][col] = 'Q';
                helper(Q,row+1, ans);
                Q[row][col] = '.';
            }
        }
            
            
        }
                
    int isValid(vector<string> &board, int row, int col){
         for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;      
        }    
};