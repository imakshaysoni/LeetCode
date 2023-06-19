class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // int n = flights.size();
        int m = flights[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        dist[src]=0;
        q.push({0, {src,0}});
        
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            int stops = it.first;
            int u = it.second.first;
            int wt = it.second.second;
            
            if(stops>k) continue;            
            
            for(auto n: adj[u]){
                int adjNode = n.first;
                int dis = n.second;
                
                if(dist[adjNode] > wt + dis){
                    dist[adjNode] = wt + dis;
                    q.push({stops+1,{adjNode, dist[adjNode]}});
                }
                
            }
            
            
        }
        for(int x: dist) cout<<x<<" ";
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};