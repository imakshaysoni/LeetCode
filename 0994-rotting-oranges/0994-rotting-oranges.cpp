class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1) vis[i][j]=1;
            }
        }
        
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int t = it.second;
            time = max(time,  t);
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            
            for(int index=0;index<4;index++){
                int delrow = row + dx[index];
                int delcol = col + dy[index];
                
                if( delrow<0 || delrow>=grid.size() || delcol<0 || delcol>=grid[0].size() ) continue;
                if(grid[delrow][delcol]==0 || vis[delrow][delcol]==2) continue;
                vis[delrow][delcol]=2;
                q.push({{delrow,delcol}, t+1});
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1) return -1;
            }
        }
        
        return time;
    }
};