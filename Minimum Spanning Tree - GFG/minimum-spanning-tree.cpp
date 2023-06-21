//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DisjointSet
{
private:
	vector<int> parent, rank, size;

public:
	// Constructor to initialize the disjoint set with size n
	DisjointSet(int n){
		rank.resize(n+1, 0);
		parent.resize(n+1);
		size.resize(n+1, 1);
		for(int i=0;i<=n;i++) parent[i]=i;
	}

	// Find the representative (root) of the set to which node belongs (with path compression)
	int findUp(int node){
		if(node == parent[node]) return node;
		
		// Path compression by updating the parent of the node
		return parent[node] = findUp(parent[node]);
	}

	// Union two sets based on rank
	int unionByRank(int u, int v){
		if(parent[u] == parent[v]) return 0;

		int usp = findUp(u); // Find representative of u's set
		int vsp = findUp(v); // Find representative of v's set

		if(rank[usp] > rank[vsp]){
			parent[vsp] = usp; // Set v's representative's parent as u's representative
		}
		else if(rank[vsp] > rank[usp]){
			parent[usp] = vsp; // Set u's representative's parent as v's representative
		}
		else{
			parent[usp] = vsp; // Set u's representative's parent as v's representative
			rank[vsp]++; // Increment the rank of v's representative
		}
		return 1;
	}

	// Union two sets based on size
	void unionBySize(int u, int v){
		if(parent[u] == parent[v]) return;

		int usp = findUp(u); // Find representative of u's set
		int vsp = findUp(v); // Find representative of v's set

		if(size[usp] > size[vsp]){
			parent[vsp] = usp; // Set v's representative's parent as u's representative
			size[usp] += size[vsp]; // Update the size of u's set
		}
		else{
			parent[usp] = vsp; // Set u's representative's parent as v's representative
			size[vsp] += size[usp]; // Update the size of v's set
		}
	}
};

class Solution
{
    private:
    // class DisjointSet(int);
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
{
    // Code: BY Krushkal Algorithm using DisJointSet
    int sum = 0;
    priority_queue<pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>> pq;
    
    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            pq.push({it[1], {i, it[0]}});
        }
    }
    DisjointSet ds(V);
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUp(u) != ds.findUp(v)){
            sum += wt;
            ds.unionByRank(u,v);
        }
        
    }
    
    return sum;
    
    // code here: By Prism Algorithm
    // return byPrismAlgo(V, adj);
}

int byPrismAlgo(int V, vector<vector<int>> adj[])
{
    vector<int> visi(V, 0);
    priority_queue<pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>> pq;
    pq.push({0, {0, -1}});
    int sum = 0;
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        
        if(visi[node] == 1)
            continue;
        
        visi[node] = 1;
        sum += wt;
        
        for(auto edge : adj[node]){
            int v = edge[0];
            int wt = edge[1];
            if(visi[v] == 1)
                continue;
            pq.push({wt, {v, node}});
        }
    }
    
    return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends