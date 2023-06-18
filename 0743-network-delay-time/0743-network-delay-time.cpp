class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int S) {
        vector<int> dist(V + 1, 1e9);
        set<pair<int, int>> s;
        s.insert({0, S});
        dist[S] = 0;
        
        vector<pair<int,int>> adj[V+1];

        for(auto it: times){
            adj[it[0]].push_back({it[2],it[1]});
        }
        
        while (!s.empty()) {
            auto it = *(s.begin());
            s.erase(it);
            int node = it.second;
            int wt = it.first;
            
            for (auto edge : adj[node]) {
                int n = edge.second;
                int dis = edge.first;
                if (wt + dis < dist[n]) {
                    if (dist[n] != 1e9)
                        s.erase({dist[n], n});
                    dist[n] = wt + dis;
                    s.insert({dist[n], n});
                }
            }
        }
        dist[S] = -1;
        for(int i=1;i<V+1;i++){ 
            if(dist[i]==1e9) return -1;
        }
        return *max_element(dist.begin()+1, dist.end());
    }
};
