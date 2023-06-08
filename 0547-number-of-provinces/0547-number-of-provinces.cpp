class Solution {
public:
    int ans=0;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                // dfs(i, vis, adj);
                bfs(i, vis, adj);
            }
        }
        return ans;
    }
    
    void bfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            vis[n]=1;
            q.pop();
            for(auto it: adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
        }
        
    }
    
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        
        vis[node]=1;
        for(auto n: adj[node]){
            if(vis[n]==0){
                dfs(n, vis, adj);
            }
        }
        return;
    }
};