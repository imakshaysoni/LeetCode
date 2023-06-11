//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visi(V, 0);
        vector<int> path(V, 0);
        for(int i=0;i<V;i++){
            if(visi[i]==0){
                if(checkDfs(adj, i, visi, path)==true) return true;
            }
        }
        
        return false;
        
    }
    
    bool checkDfs(vector<int> adj[], int start, vector<int> &visi, vector<int> &path){
    
        visi[start]=1;
        path[start]=1;
        
        for(int i: adj[start]){
            if(visi[i]==1 and path[i]==1) return true;
            else if(visi[i]==0) {
                    if(checkDfs(adj, i, visi, path)==true) return true;
                }
        }
        path[start]=0;
        return false;
        
    }
    
    bool check(vector<int> adj[], int start, vector<int> &visi, vector<int> &path){
        queue<int> q;
        visi[start]=1;
        path[start]=1;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int n : adj[node]){
                if(visi[n]==1) return true;
                visi[n]=1;
                q.push(n);
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends