class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> indegree, outdegree;
        for(auto iter: pairs){
            int u = iter[0];
            int v = iter[1];
            adjList[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        int startNode=pairs[0][0];

        for(auto it: outdegree){
            int node = it.first;
            if(outdegree[node]-indegree[node] == 1){
                startNode = node;
                break;
            } 
        }

        // Perform DFS
        vector<int> result;
        dfs(adjList, startNode, result);
        
        reverse(result.begin(), result.end());

        int n = result.size();
        vector<vector<int>> output;
        for(int i=0;i<n-1;i++){
            output.push_back({result[i], result[i+1]});
        }

        return output;
    }

    void dfs(unordered_map<int, vector<int>> &adjList, int node, vector<int> &result){                

        while(!adjList[node].empty()){
            int adjNode = adjList[node].back();
            adjList[node].pop_back();
            dfs(adjList, adjNode, result);
        }

        result.push_back(node);
        return;
    }
};