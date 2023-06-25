class Solution {
    int timer=0;
    private:
    void dfs(vector<int> adj[], int parent, int node, vector<int> &visi, int low[], int tin[], vector<vector<int>> &bridges){
        timer++;
        visi[node]=1;
        low[node]=tin[node]=timer;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(visi[it]==0){
                dfs(adj, node, it, visi, low, tin, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // int n = connections.size();
        vector<int> adj[n];
        
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int low[n];
        int tin[n];
        vector<int> visi(n,0);
        vector<vector<int>> bridges;
        
        for(int i=0;i<n;i++){
                if(visi[i]==0){
                    dfs(adj, -1, i, visi, low, tin, bridges);    
                }
        }
        return bridges;
    }
};