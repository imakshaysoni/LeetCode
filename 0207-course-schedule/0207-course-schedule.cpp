class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
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
        int cnt=0;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            cnt++;
            
            for(int n: adj[node]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
            
            
        }
        if(cnt==V) return 1;
        return 0;
    }
//         ////////////////////////////////////////////
        
//         vector<int> indegree(numCourses,0);
//         for(auto x: prerequisites){
//             indegree[x[0]]++;
//         }
        
        
//         queue<int> q;
//         int cnt=0;
//         for(int i=0;i<numCourses;i++){
//             if(indegree[i]==0) q.push(i);
//         }
        
//         while(!q.empty()){
//             int n = q.front();
//             q.pop();
//             cnt++;
//             for(int x: prerequisites[n]){
//                 indegree[x]--;
//                 if(indegree[x]==0) q.push(x);
//             }
//         }
        
//         if(cnt==numCourses) return true;
//         return false;
        
    // }
};