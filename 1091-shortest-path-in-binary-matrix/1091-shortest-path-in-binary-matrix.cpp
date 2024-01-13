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
                return final_ans = min(final_ans, dist) + 1;
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
        
    return -1;
        
        
//         DFS Apprch Giving TLE, even after optimization
        // return dfsApproch(grid);     
    }
    
};