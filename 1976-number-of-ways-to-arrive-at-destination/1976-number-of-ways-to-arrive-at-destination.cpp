class Solution {
public:
    long long mod = 1e9+7;
    int countPaths(int V, vector<vector<int>>& edges) {
                vector<vector<pair<int,int>>> adjList(V);
        
        for(auto iter: edges){
            int u = iter[0];
            int v = iter[1];
            int time = iter[2];
            
            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        pq.push({0, 0});
        vector<long long> dist(V, 1e9);
        dist[0]=0;
        vector<long long> paths(V, 0);
        paths[0]=1;
        
        while(!pq.empty()){
            long long time = pq.top().first;
            long long u = pq.top().second;
            pq.pop();
            
            for(auto it: adjList[u]){
                long long v = it.first;
                long long t = it.second;
                
                if(dist[v] > time + t){
                    dist[v] = dist[u] + t;
                    paths[v] = paths[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v]==time+t){
                    paths[v] = (paths[v]+paths[u])%mod;
                }
            }
        }
        return paths[V-1]%mod;
    }
};