class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols,0));
//         First Col/Last Col
        for(int row=0;row<rows;row++){
            if(grid[row][0]==1){
                dfs(grid, row, 0, visited);
            }
            if(grid[row][cols-1]==1){
                dfs(grid, row, cols-1, visited);
            }
        }
        
//         First Row/Last Row
        for(int col=0;col<cols;col++){
            if(grid[0][col]==1){
                dfs(grid, 0, col, visited);
            }
            if(grid[rows-1][col]==1){
                dfs(grid, rows-1, col, visited);
            }
        }
        int count=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(visited[row][col]==0 && grid[row][col]==1){
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&visited){
        visited[row][col]=1;
        
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(abs(dx)==abs(dy)) continue;
                int new_row = row + dx;
                int new_col = col + dy;
                if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size()
                  && visited[new_row][new_col]==0 && grid[new_row][new_col]==1){
                    dfs(grid, new_row, new_col, visited);
                }
            }
        }
        
        
        
    }
};