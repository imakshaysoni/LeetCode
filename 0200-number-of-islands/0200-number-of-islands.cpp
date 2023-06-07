class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]=='0' || grid[i][j]=='#') return;
        grid[i][j]='#';
        // vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
        // vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};
        for(int delrow=-1;delrow<=1;delrow++){         
            for(int delcol=-1;delcol<=1;delcol++){
                if(abs(delcol)==abs(delrow)) continue; // Ingoring diagonals
                dfs(grid, i+delrow, j+delcol);
            }      
        }     
    }
};