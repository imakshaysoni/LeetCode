class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        
        for(auto e: prerequisites){
            adjList[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int node=0;node<numCourses;node++){
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
        reverse(topo.begin(), topo.end());
        if(topo.size()==numCourses) return topo;
        return {};
    }
};