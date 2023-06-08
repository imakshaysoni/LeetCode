//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int ans=0;
    int numProvinces(vector<vector<int>> isConnected, int n) {
        // code here
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                // dfs(i, vis, adj); //DFS approch
                bfs(i, vis, adj); // BFS Approch
        }
        }
        return ans;
    }
    
    void bfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it: adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
        }
        
    }
    
    
    
    
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        
        vis[node]=1;
        for(auto n: adj[node]){
            if(vis[n]==0){
                dfs(n, vis, adj);
            }
        }
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends