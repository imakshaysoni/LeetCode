class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
//         BFS Approch using topo sort
        
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<int> topo;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int x: graph[i]){
                adj[x].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int x: adj[node]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }  
        
        
//         dfs Approch
//         int n = graph.size();
//         vector<int> visi(n,0);
//         vector<int> path(n,0);
//         vector<int> check(n,0);
//         vector<int> safeNodes;
//         for(int i=0;i<n;i++){
//             if(visi[i]==0){
//                 dfs(graph, i, visi, path, check);
//             }
//         }
        
//         for(int i=0;i<n;i++){
//             if(check[i]==1) safeNodes.push_back(i);
//         }
        
//         return safeNodes;
        
//     }
    
    
//     bool dfs(vector<vector<int>> & graph, int node, vector<int> &visi, vector<int> &path, vector<int> & check){
        
//         visi[node]=1;
//         path[node]=1;
        
//         for(int n: graph[node]){
            
//             if(visi[n]==1 and path[n]==1){
//                 return false;
//             }
            
//             if(visi[n]==0){
//                 if(dfs(graph, n, visi, path, check)==false){
//                     return false;
//                 }
//             }
            
            
//         }        
//         check[node]=1;
//         path[node]=0;
//         return true;
        
//     }
};