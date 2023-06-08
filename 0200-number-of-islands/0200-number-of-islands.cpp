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
                    // dfs(grid, i, j); // DFS Approch
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    void bfs1(vector<vector<char>> &grid, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '#';
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                if (abs(delcol) == abs(delrow))
                    continue; // Ignoring diagonals

                int nrow = it.first + delrow;
                int mcol = it.second + delcol;

                if (nrow < 0 || mcol < 0 || nrow >= grid.size() || mcol >= grid[0].size())
                    continue;

                if (grid[nrow][mcol] == '1') {
                    q.push({nrow, mcol});
                    grid[nrow][mcol] = '#';
                }
            }
        }
    }
}

    
    void bfs(vector<vector<char>> &grid, int i, int j){
        
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j]='#';
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){         
            for(int delcol=-1;delcol<=1;delcol++){
                if(abs(delcol)==abs(delrow)) continue; // Ingoring diagonals
                
                int nrow = it.first+delrow;
                int mcol = it.second+delcol;
                if (nrow < 0 || mcol < 0 || nrow >= grid.size() || mcol >= grid[0].size())
                    continue;
                
                if(grid[nrow][mcol]=='1'){
                    q.push({nrow,mcol});
                    grid[nrow][mcol]='#';
                }
            }      
        }
        }
        
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