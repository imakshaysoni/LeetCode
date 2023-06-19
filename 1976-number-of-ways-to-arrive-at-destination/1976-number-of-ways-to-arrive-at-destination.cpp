class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];

for(auto it: roads){
    adj[it[0]].push_back({it[1],it[2]});
    adj[it[1]].push_back({it[0],it[2]});
}

vector<long long> dist(n,1e18);
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