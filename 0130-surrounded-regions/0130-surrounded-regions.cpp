class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;
        
        for(int col=0;col<cols;col++){
            if(board[0][col]=='O') q.push({0, col});
            if(board[rows-1][col]=='O') q.push({rows-1,col});
        }
        for(int row=0;row<rows;row++){
            if(board[row][0]=='O') q.push({row, 0});
            if(board[row][cols-1]=='O') q.push({row, cols-1});
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            board[row][col]='#';
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(abs(dx)==abs(dy)) continue;
                    int new_row = row+dx;
                    int new_col = col + dy;
                    if(new_row>=0 and new_row<rows && new_col>=0 && new_col<cols
                       && board[new_row][new_col]=='O'){
                        board[new_row][new_col]='#';
                        q.push({new_row,new_col});
                    }
                }
            }
        }
        
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(board[row][col]=='O') board[row][col]='X';
                if(board[row][col]=='#') board[row][col] = 'O';
            }
        }
        return;
        
    }
};