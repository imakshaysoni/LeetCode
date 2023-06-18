class Solution {
public:
    int final_ans = INT_MAX;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        if (grid[0][0] != 0)
            return -1;

        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1},
                                                {0, -1},           {0, 1},
                                                {1, -1},  {1, 0},  {1, 1}};
        
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, std::numeric_limits<int>::max()));
        dist[0][0] = 1;
        
        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int currX = curr.first;
            int currY = curr.second;
            
            for (const auto& dir : directions) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0) {
                    if (dist[newX][newY] > dist[currX][currY] + 1) {
                        dist[newX][newY] = dist[currX][currY] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        
        return (dist[n - 1][m - 1] == std::numeric_limits<int>::max()) ? -1 : dist[n - 1][m - 1];
        
//         if(grid[0][0]!=0) return -1;
        
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> visi(n, vector<int> (m,0));
        
//         solve(grid, 0, 0, visi, 1);
//         if(final_ans==INT_MAX) return -1;
//         return final_ans;
        
    }
    
    void solve(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&visi, int ans){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==1 || visi[i][j]==1) return;
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