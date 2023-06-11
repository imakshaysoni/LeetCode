class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(graph, color, i)==false) return false;
            }
        }
        return true;
    }
    
    bool check(vector<vector<int>> & graph, vector<int> &color, int start){
        int n = graph.size();
        int baseColor = 0;
        queue<int> q;
        q.push(start);
        color[start]=baseColor;
        
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            int prevColor = color[node];
            int newColor = ! prevColor;
            for(int adjNode: graph[node]){
               
                if(color[adjNode]== prevColor) return false;
                if(color[adjNode]==-1){
                    q.push(adjNode);
                    color[adjNode]=newColor;
                }
            }            
            
        }
        
        return true;
    }
};