//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> result = image;
        bfs(result, sr, sc, newColor);
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

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends