//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    private:
        void dfs(vector<int> adj[], int parent, int node, vector<int> &visi, int low[], int tin[], vector<int> &mark)
        {
            timer++;
            visi[node] = 1;
            int child=0;
            low[node] = tin[node] = timer;
            for (auto it: adj[node])
            {
                if (it == parent) continue;
                if (visi[it] == 0)
                {
                    dfs(adj, node, it, visi, low, tin, mark);
                    low[node] = min(low[node], low[it]);
                    if (low[it] >= tin[node] and parent!=-1)
                    {
                        mark[node] = 1;
                    }
                    child++;
                }
                else
                {
                    low[node] = min(low[node], tin[it]);
                }
            }
            if(child>1 and parent==-1) mark[node]=1;
        }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {

            int low[n];
            int tin[n];
            vector<int> visi(n, 0);
            vector<int> mark(n,0);

            for (int i = 0; i < n; i++)
            {
                if (visi[i] == 0)
                {
                    dfs(adj, -1, i, visi, low, tin, mark);
                }
            }
            
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(mark[i]==1) ans.push_back(i);
            }
            if(ans.size()==0) return {-1};
            return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends