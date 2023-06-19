//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];

for(auto it: roads){
    adj[it[0]].push_back({it[1],it[2]});
    adj[it[1]].push_back({it[0],it[2]});
}

vector<long long> dist(n,LONG_MAX);
vector<long long> ways(n, 0);
priority_queue<pair<long long,long long>,
    vector<pair<long long,long long>>,
    greater<pair<long long,long long>>> q;

dist[0] = 0;
ways[0] = 1;
long long mod = 1e9 + 7;
q.push({0,0});

while(!q.empty()){
    auto it = q.top(); q.pop();
    long long time = it.first;
    long long node = it.second;

    for(auto it: adj[node]){
        long long neighbor_node = it.first;
        long long neighbor_time = it.second;

        if(time + neighbor_time < dist[neighbor_node]){
            dist[neighbor_node] = time + neighbor_time;
            ways[neighbor_node] = ways[node];
            q.push({dist[neighbor_node], neighbor_node});
        }
        else if(time + neighbor_time == dist[neighbor_node]){
            ways[neighbor_node] = (ways[neighbor_node] + ways[node])%mod;
        }
    }
}

return ways[n-1] % mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends