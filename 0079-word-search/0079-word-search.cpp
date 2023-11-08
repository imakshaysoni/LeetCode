class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(board[row][col]==word[0]){
                    if(solve(board, row, col, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool solve(vector<vector<char>>&b, int row, int col, string word, int w_idx){
        if(w_idx>=word.size()) return true;
        if(row>=b.size() || row<0 || col>=b[0].size() || col<0 || b[row][col]=='#') return false;
        if(word[w_idx]!=b[row][col]) return false;
        
        b[row][col] = '#';
        bool exist = false;    
    
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(abs(dx)==abs(dy)) continue; //Ignore diagonals
                exist = exist || solve(b, row+dx, col+dy, word, w_idx+1);
            }
        }
        b[row][col]=word[w_idx];
        return exist;
        
        
    }
};