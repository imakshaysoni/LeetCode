class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int rows= grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp (
            rows, vector<vector<int>> (
                cols, vector<int>(cols, -1)
            )
        );
        return solve(grid, rows, cols, 0, 0, cols-1, dp);
    }

    int solve(vector<vector<int>>&grid, int rows, int cols, int r1, int c1, int c2, vector<vector<vector<int>>> &dp){
        int r2 = r1;
        if(r1>=rows || r1<0 || r2>=rows || r2<0 ||
        c1>=cols || c2>=cols || c1<0 || c2<0 ) return 0;

        if(r1==rows-1 and r2==rows-1){
            if(c1==c2) return grid[r1][c1];
            return grid[r1][c1]+grid[r2][c2];
        }

        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];

        int cherries = 0;
        if(r1==r2 and c1==c2) cherries = grid[r1][c1];
        else cherries = grid[r1][c1]+grid[r2][c2];
        int maxi = 0;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                maxi = max(maxi, 
                solve(grid, rows, cols, r1+1, c1+dx, c2+dy, dp)
                + cherries
                );
                
            }
        }
        return dp[r1][c1][c2] = maxi;


    }
};