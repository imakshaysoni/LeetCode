class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        // int base_color = image[sr][sc];
        // helper(image, sr,sc, color, base_color);
        // return image;
        // BFS Approch
        vector<vector<int>> result = image;
        bfs(result, sr, sc, color);
        return result;
        
    }
    
     void bfs(vector<vector<int>>& grid, int i, int j, int newColor) {
        int color = grid[i][j];
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto it = q.front(); q.pop();
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};
            
            grid[it.first][it.second]=newColor;
            
            for(int index=0; index<4; index++){
                int nrow = it.first + dx[index];
                int mcol = it.second + dy[index];
                if(nrow<0 || mcol<0 || nrow>=grid.size() || mcol>=grid[0].size() || grid[nrow][mcol]==newColor)
                    continue;
                if(grid[nrow][mcol]==color){
                    grid[nrow][mcol] = newColor;
                    q.push({nrow, mcol});
                }
            }
        }
    }
    
    
    
    void helper(vector<vector<int>> & image, int sr, int sc, int color, int base_color){
        
        
        
        
        
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc]!=base_color || image[sr][sc]==color) return;
        
        
        image[sr][sc] = color;
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1, -1, 0, 0};
        for(int index=0;index<4;index++){
            helper(image, sr+dx[index], sc+dy[index], color, base_color);
        }
        
        return;
        
        
    }
};