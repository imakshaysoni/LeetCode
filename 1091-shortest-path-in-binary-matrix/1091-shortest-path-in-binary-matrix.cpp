class Solution {
public:
    int final_ans = INT_MAX;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;
//         BFS Approch
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]!=0) return -1;
        
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},0});
        int final_ans = INT_MAX;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i=it.first.first;
            int j=it.first.second;
            int dist = it.second;
            if(i==n-1 && j==m-1){
                final_ans = min(final_ans, dist);
            }
            for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                 int new_i = i + delrow;
                int new_j = j + delcol;
                
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 0) {
                    q.push({{new_i, new_j}, dist + 1});
                    grid[new_i][new_j] = 1; // Mark the visited cell to avoid revisiting
                }
            }   
        }
        }
    
    if(final_ans==INT_MAX) return -1;
        
    return final_ans+1;
        
        
//         DFS Apprch Giving TLE, even after optimization
        // return dfsApproch(grid);     
    }
    
    
    int dfsApproch(vector<vector<int>>&grid){
        if(grid[0][0]!=0) return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]!=0) return -1;
        vector<vector<int>> visi(n, vector<int> (m,0));
        
        solve(grid, 0, 0, visi, 1);
        if(final_ans==INT_MAX) return -1;
        return final_ans;
    }
//     DFS Approch, TLE
    void solve(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&visi, int ans){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==1 || visi[i][j]==1 || ans >= final_ans) return;
        visi[i][j]=1;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            final_ans = min(final_ans, ans);
        }
        
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                if (delrow == 0 && delcol == 0)
                    continue;
                solve(grid, i+delrow, j+delcol, visi, ans+1);
            }
        }
        visi[i][j]=0;        
        return;
        
    }
};