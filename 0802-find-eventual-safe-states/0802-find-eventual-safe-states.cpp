class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        int n = graph.size();
        vector<int> visi(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(visi[i]==0){
                dfs(graph, i, visi, path, check);
            }
        }
        
        for(int i=0;i<n;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        
        return safeNodes;
        
    }
    
    
    bool dfs(vector<vector<int>> & graph, int node, vector<int> &visi, vector<int> &path, vector<int> & check){
        
        visi[node]=1;
        path[node]=1;
        
        for(int n: graph[node]){
            
            if(visi[n]==1 and path[n]==1){
                return false;
            }
            
            if(visi[n]==0){
                if(dfs(graph, n, visi, path, check)==false){
                    return false;
                }
            }
            
            
        }        
        check[node]=1;
        path[node]=0;
        return true;
        
    }
};