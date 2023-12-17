class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> adj[nodes];
        for(int i=0;i<nodes;i++){
            for(auto it: graph[i]){
                adj[i].push_back(it);
            }
        }
        
        
        
        vector<int> safeNodes;
        vector<int> visited(nodes, 0);
        vector<int> pathVis(nodes, 0);
        vector<int> check(nodes, 0);
        for(int i=0; i<nodes;i++){
            if(visited[i]==0){
                dfs(adj, i, visited, pathVis, check);
            }
        }
        
        for(int i=0;i<nodes;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
    
    bool dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &pathVis, vector<int> &check){
        
        visited[node]=1;
        pathVis[node]=1;
        
        for(auto adjNode: adj[node]){
            if(visited[adjNode]==0){
                if(dfs(adj, adjNode, visited, pathVis, check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[adjNode]==1){
                check[adjNode]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
};