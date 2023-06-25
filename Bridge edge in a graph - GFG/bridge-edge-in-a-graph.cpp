//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
     int timer = 0;
    private:
        void dfs(vector<int> adj[], int parent, int node, vector<int> &visi, int low[], int tin[], vector<vector < int>> &bridges)
        {
            timer++;
            visi[node] = 1;
            low[node] = tin[node] = timer;
            for (auto it: adj[node])
            {
                if (it == parent) continue;
                if (visi[it] == 0)
                {
                    dfs(adj, node, it, visi, low, tin, bridges);
                    low[node] = min(low[node], low[it]);
                    if (low[it] > tin[node])
                    {
                        bridges.push_back({ node, it });
                    }
                }
                else
                {
                    low[node] = min(low[node], low[it]);
                }
            }
        }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        // Code here
           	// int n = connections.size();
            // vector<int> adj[n];

            // for (auto it: connections)
            // {
            //     adj[it[0]].push_back(it[1]);
            //     adj[it[1]].push_back(it[0]);
            // }

            int low[n];
            int tin[n];
            vector<int> visi(n, 0);
            vector<vector < int>> bridges;

            for (int i = 0; i < n; i++)
            {
                if (visi[i] == 0)
                {
                    dfs(adj, -1, i, visi, low, tin, bridges);
                }
            }
            // unordered_set<pair<int,int>> s;
            for(auto it: bridges){
             if(it[0]==c && it[1]==d or it[0]==d && it[1]==c) return 1;   
            }
            return 0;
        }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends