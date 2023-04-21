//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
            vector<string> ans;    
            string temp="";
            helper(m, n, 0, 0, ans, temp);  
            return ans;
    }
    
    
    void helper(vector<vector<int>> &m, int n, int row, int col, vector<string> &ans, string &temp){
        if(row < 0 || col < 0  || row >= n || col >= n || m[row][col]==0 ) return;
        if(row==n-1 && col == n-1){
          ans.push_back(temp);
          return;
        }
        vector<int> dx = {0,0, 1, -1};
        vector<int> dy = {1,-1,0,0};
        vector<string> sample = {"R", "L", "D", "U"};
        for(int index=0;index<4;index++){
            temp= temp + sample[index];
            m[row][col]=0;
            helper(m,n, row+dx[index], col+dy[index], ans, temp);
            temp.pop_back();
            m[row][col]=1;
        }
        
        
    }
    
    
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends