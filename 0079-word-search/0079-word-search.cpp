class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(board[row][col]==word[0]){
                    bool ans = solve(row, col, rows, cols, word, 0, board);
                    if(ans==true) return true;
                }
            }
        }
        return false;
    }

    bool solve(int row, int col, int rows, int cols, string &word, int idx, vector<vector<char>>&board){

        if(row>=rows or row<0
            or col>=cols or col<0
            or board[row][col]!=word[idx]) return false;
        
        if(idx==word.size()-1) return true;
        board[row][col]='#';


        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(abs(dx)==abs(dy)) continue;
                bool ans = solve(row+dx, col+dy, rows, cols, word, idx+1, board);
                if(ans) return true;
            }
        }
        board[row][col] = word[idx];

        return false;



    }
};
