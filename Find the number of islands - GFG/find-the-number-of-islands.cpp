//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
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
        vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};
        for(int index=0;index<8;index++){
            dfs(grid, i+dx[index], j+dy[index]);
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends