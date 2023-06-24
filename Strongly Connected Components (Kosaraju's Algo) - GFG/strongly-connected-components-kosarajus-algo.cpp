//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &visi, stack<int> &st){
        visi[i]=1;
        for(auto it: adj[i]){
            if(visi[it]==0){
                dfs(adj, it, visi, st);
            }
        }
        st.push(i);
    }
    
    void dfs_other(vector<int> adjT[], int i, vector<int> &visi){
        visi[i]=1;
        for(auto it: adjT[i]){
            if(visi[it]==0){
                dfs_other(adjT, it, visi);
            }
        }
    }
	
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> adjrev[V];
        vector<int> visi(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(visi[i]==0){
                dfs(adj, i, visi, st);
            }
        }
        
        for(int i=0;i<V;i++){
            visi[i]=0;
            for(auto it: adj[i]){
                adjrev[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node = st.top(); st.pop();
            if(visi[node]==0){
                scc++;
                dfs_other(adjrev, node, visi);
            }
        }
        
        return scc;
        
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends