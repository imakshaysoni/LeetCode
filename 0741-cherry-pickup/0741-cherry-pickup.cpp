class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(
    vector<vector<vector<int>>>(
        rows,
        vector<vector<int>>(
            rows,
            vector<int>(cols, -1)
        )
    )
);
        return max(0,solve(grid, rows, cols, 0, 0, 0, dp));
    }

    int solve(vector<vector<int>> & grid, int rows, int cols, int r1, int c1, int r2,
    vector<vector<vector<int>>> &dp){
        // r1+c1 == r2+c2
        int c2 = r1+c1-r2;
        if(r1<0 || r1 >=rows || r2<0 || r2>=rows ||
            c1<0 || c1>=cols || c2<0 || c2>=cols ||
            grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==rows-1 and r2==rows-1 and c2==cols-1 and c1==cols-1) {
            return grid[r1][c1];
        }
        if(dp[r1][r2][c1]!=-1) return dp[r1][r2][c1];
        //Option
        int cherries = 0;
        if(r1==r2 and c1==c2) cherries = grid[r1][c1];
        else{
            cherries = grid[r1][c1]+grid[r2][c2];
        }

        int op1 = solve(grid, rows,cols, r1, c1+1, r2, dp) + cherries; // h h
        int op2 = solve(grid,  rows, cols, r1, c1+1, r2+1, dp) + cherries; // h v
        int op3 = solve(grid, rows,cols, r1+1, c1, r2+1, dp) + cherries; // h h
        int op4 = solve(grid,  rows, cols, r1+1, c1, r2, dp) + cherries; // h v
        
        return dp[r1][r2][c1] = max(max(op1, op2), max(op3, op4));
    }
};