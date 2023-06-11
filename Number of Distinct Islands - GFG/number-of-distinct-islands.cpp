//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};


class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int count=0;
        int n  =grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> visi(n, vector<int> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                    if(grid[i][j]==1 && visi[i][j]==0){
                        // vector<pair<int,int>> p = bfs(grid, i, j, visi);
                        vector<pair<int,int>> v;
                        v.push_back({i,j});
                        dfs(grid, i, j, visi, v);
                        v.erase(v.begin());
                        if(s.find(v)==s.end()){
                            count++;
                            s.insert(v);
                        }
                        
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visi, vector<pair<int,int>> &v){
        // vector<pair<int,int>> v;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visi[i][j]==1 || grid[i][j]==0) return;
        
        visi[i][j]=1;
        v.push_back({i-v[0].first, j-v[0].second});
        vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1,0, -1};
            for(int index=0;index<4;index++){
                
                int delrow = i + dx[index];
                int delcol = j + dy[index];
                dfs(grid, delrow, delcol, visi, v);
            }
        return;
        
    }
    
    vector<pair<int,int>> bfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visi){
        
        int n  =grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> v;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            v.push_back({row-i, col-j});
            // cout<<p.first<<"--"<<p.second<<endl;
            visi[row][col]=1;
            
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1,0, -1};
            for(int index=0;index<4;index++){
                
                int delrow = row + dx[index];
                int delcol = col + dy[index];
                if(delrow>=0 && delcol >=0 && delrow <n && delcol <m && grid[delrow][delcol]==1 && visi[delrow][delcol]==0){
                    q.push({delrow,delcol});
                }
            }
        }
        return v;
    }
        
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends