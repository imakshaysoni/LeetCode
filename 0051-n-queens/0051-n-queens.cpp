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
                
    int isValid(vector<string> &Q, int row, int col){
        
        
//         Check Columns
        for(int i=row;i>=0;--i)
            if(Q[i][col] == 'Q') return false;
        
//         Check left diagone
        for(int i=row,j=col; i>=0 && j>=0 ; i--, j--){
            if(Q[i][j]=='Q') return false;
        }
//         Check right diagonal
        for(int i=row,j=col; i>=0 && j<Q.size() ;i--,j++){
            if(Q[i][j]=='Q') return false;
        }
        
        return true;
        
        }    
};