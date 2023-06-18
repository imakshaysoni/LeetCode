//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstraUsingSet(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        
        set<pair<int,int>> s;
        s.insert({0,S});
        dist[S]=0;
        while(!s.empty()){
            auto it = *(s.begin());
            s.erase(it);
            int node = it.second;
            int wt = it.first;
            
            for(auto it: adj[node])
            {
                int n = it[0];
                int dis = it[1];
                if(wt + dis < dist[n]){
                    if(dist[n]!=1e9) s.erase({dist[n], n});
                    dist[n] = wt + dis;
                    s.insert({dist[n],n});
                }
            }
        }
        
        return dist;
        
        
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Using PQ
        vector<int> dist(V,1e9);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
        s.push({0,S});
        dist[S]=0;
        while(!s.empty()){
            auto it = s.top();
            s.pop();
            int node = it.second;
            int wt = it.first;
            
            for(auto it: adj[node])
            {
                int n = it[0];
                int dis = it[1];
                if(wt + dis < dist[n]){
                    dist[n] = wt + dis;
                    s.push({dist[n],n});
                }
            }
        }
        
        return dist;
        
        
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends