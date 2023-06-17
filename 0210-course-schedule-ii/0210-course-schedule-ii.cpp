class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
            // BFS Approch Kahan's Algorithm
        vector<vector<int>> adj(V);
    for (vector<int> it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }
        
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(int node : adj[i]){
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int n: adj[node]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
            
            
        }
        if(topo.size()==V) return topo;
        vector<int> emp;
        return emp;    
    }
};