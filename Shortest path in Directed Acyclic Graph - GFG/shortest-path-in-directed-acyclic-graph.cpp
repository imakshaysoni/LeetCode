//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    vector<int> topoSort(vector<pair<int,int>> adj[], int N, int M){
        
        vector<int> indegree(N, 0);
        queue<int> q;
        for(int i=0;i<N;i++){
            for(auto x: adj[i]){
                indegree[x.first]++;
            }
        }
        
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);            
            for(auto x: adj[node]){
                indegree[x.first]--;
                if(indegree[x.first]==0) q.push(x.first);
            }
        }
        
        return topo;
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v,d});
        }
        
        vector<int> topo = topoSort(adj, N, M);
        // for(int x: topo) cout<<x<<" ";
        // cout<<endl;
        vector<int> dist(N, 1e9);
        dist[0]=0;
        for(int node: topo){
            for(auto n: adj[node]){
                int adjN = n.first;
                int dis = n.second;
                if(dist[adjN] > dis + dist[node]){
                    dist[adjN] = dis + dist[node];
                }
            }
            
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends