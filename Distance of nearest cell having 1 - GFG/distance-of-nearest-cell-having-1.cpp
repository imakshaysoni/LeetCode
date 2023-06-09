//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	     queue<pair<pair<int, int>, int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> output(n, vector<int> (m, 0));
        vector<vector<int>> visi(mat.size(), vector<int> (mat[0].size(), 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    visi[i][j]=1;
                    q.push({{i,j}, 0});
                }
            }
        }
        
       
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty())
        {   
            // count++;
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            output[row][col]=step;
            for(int index=0;index<4;index++)
            {
                int delrow = row + dx[index];
                int delcol = col + dy[index];
                if(delrow<0 || delcol<0 || delrow>=mat.size() || delcol>=mat[0].size()) continue;
            
                if(visi[delrow][delcol]==1)
                    continue;
                visi[delrow][delcol]=1;
                q.push({{delrow,delcol}, step+1});
            }
        }
        return output;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends