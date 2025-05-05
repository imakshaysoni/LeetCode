class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c, vector<int>(c,-1)));
        return dfs(grid, r, c, 0, 0, c-1, dp);
    }
    
    int dfs(vector<vector<int>>&grid, int rows, int cols, int row, int col1, int col2, vector<vector<vector<int>>> &dp){
    if(col1<0 || col1>=cols || col2<0 || col2>=cols) return -1e8;
    if(row==rows-1){
        if(col1==col2) return grid[row][col1];
        else return grid[row][col1]+grid[row][col2];
    }

    if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
    int maxi=0;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int result=0;
            if(col1==col2){
                result = grid[row][col1] + dfs(grid, rows, cols, row+1, col1+dx, col2+dy, dp);
            }
            else{
                result = grid[row][col1] + grid[row][col2] + dfs(grid, rows, cols, row+1, col1+dx, col2+dy, dp);
            }            
            maxi = max(maxi, result);
            dp[row][col1][col2] = maxi;
        }
    }

    return dp[row][col1][col2];    
}
};