class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
         vector<vector<int>> visi(n, vector<int> (m, 0));
        
        
        // FirstRow Boundary
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' and visi[0][j]==0){
                // bfs(mat, 0 , j, visi);
                dfs(mat, 0 , j, visi);
            }
        }
        
        // FirstColBoundary
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' and visi[i][0]==0){
                // bfs(mat, i, 0, visi);
                dfs(mat, i, 0, visi);
            }
        }
        
        // lastRowBoundary
        for(int j=0;j<m;j++){
            if(mat[n-1][j]=='O' and visi[n-1][j]==0){
                // bfs(mat, n-1, j, visi);
                dfs(mat, n-1, j, visi);
            }
        }
        
        // lastColBoundary
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O' and visi[i][m-1]==0){
                // bfs(mat, i, m-1, visi);
                dfs(mat, i, m-1, visi);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and visi[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
        
        return;
    }
    
    void bfs(vector<vector<char>> &mat, int i, int j, vector<vector<int>> &visi){
        
        queue<pair<int, int>> q;
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
            
            if(delrow>=0 && delcol >=0 and delrow<mat.size() and delcol<mat[0].size() and visi[delrow][delcol]==0 and mat[delrow][delcol]=='O'){
                q.push({delrow,delcol});
            }
            
            
        }
            
            
            
        }
        
        return;
        
    }
    
     void dfs(vector<vector<char>> &mat, int i, int j, vector<vector<int>> &visi){
        visi[i][j]=1;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        for(int index=0;index<4;index++){
            int delrow = i + dx[index];
            int delcol = j + dy[index];
            
            if(delrow>=0 && delcol >=0 and delrow<mat.size() and delcol<mat[0].size() and visi[delrow][delcol]==0 and mat[delrow][delcol]=='O'){
                dfs(mat, delrow, delcol, visi);
            }
            
            
        }
        return;
        
        
    }
};