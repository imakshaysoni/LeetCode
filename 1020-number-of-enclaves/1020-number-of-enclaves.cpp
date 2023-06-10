class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visi(n, vector<int> (m,0));
//         firstRow
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 and visi[0][j]==0){
                // bfs(grid, 0, j, visi);
                dfs(grid, 0, j, visi);
                
            }
        }
        
//         FirstCol
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 and visi[i][0]==0){
                // bfs(grid, i, 0, visi);
                dfs(grid, i, 0, visi);
            }
        }
        
//         lstRpw
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1 and visi[n-1][j]==0){
                // bfs(grid, n-1, j,visi);
                dfs(grid, n-1, j,visi);
            }
        }
        
//         lastCol
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 and visi[i][m-1]==0){
                // bfs(grid, i, m-1,visi);
                dfs(grid, i, m-1,visi);
            }
        }
        
        int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visi[i][j]==0) count++;
        }
    }
    
    return count;
        
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visi){
    
        visi[i][j]=1;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};
            
            for(int index=0;index<4;index++){
                int delrow = i + dx[index];
                int delcol = j + dy[index];
                
                if(delrow>=0 && delcol >=0 && delrow<n && delcol < m && visi[delrow][delcol]==0 && grid[delrow][delcol]==1){
                    dfs(grid, delrow, delcol, visi);
                }
            }     
        
    }
    
    void bfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visi){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            visi[row][col]=1;
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};
            
            for(int index=0;index<4;index++){
                int delrow = row + dx[index];
                int delcol = col + dy[index];
                
                if(delrow>=0 && delcol >=0 && delrow<n && delcol < m && visi[delrow][delcol]==0 && grid[delrow][delcol]==1){
                    q.push({delrow,delcol});
                }
            }            
            
            
        }
        
    }
    
};