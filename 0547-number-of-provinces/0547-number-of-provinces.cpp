class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities=isConnected.size();
        vector<vector<int>> adj(cities+1,vector<int> (cities+1,0));
        for(int i=0;i<cities;i++){
            for(int j=0;j<cities;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> visited(cities+1,0);
        queue<int> q;
        
        for(int i=0;i<cities;i++){
            
            if(visited[i]==0){
                ans++;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
            int city = q.front();
            q.pop();
            
            for(auto it: adj[city]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }    
            }
            
        }
        
        return ans;
        
        
        
        
    }
};