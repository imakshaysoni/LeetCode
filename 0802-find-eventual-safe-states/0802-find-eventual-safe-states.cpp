class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();

        vector<int> indegree(nodes, 0);
        
        vector<int> adjList[nodes];
        for(int node=0;node<nodes;node++){
            for(auto adjNode: graph[node]){
                adjList[adjNode].push_back(node);
                indegree[node]++;
            }
        }
        

        
        queue<int> q;
        for(int node=0;node<nodes;node++){
            if(indegree[node]==0) q.push(node);
        }
        vector<int> topo;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto adjNode: adjList[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0) q.push(adjNode);
            }
            
        }
        // for(auto node: topo) cout<<node<<"->";
        sort(topo.begin(), topo.end());
        return topo;
    }
};