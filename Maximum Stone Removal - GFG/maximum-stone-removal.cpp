//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet
{

public:

	vector<int> parent, rank, size;
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
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        int maxRow = 0;
        int maxCol = 0;
        
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(1LL*maxCol+1LL*maxRow+1);
        unordered_set<int> s;
        unordered_map<int,int> m;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            s.insert(ds.findUp(nodeRow));
            m[nodeRow]=1;
            m[nodeCol]=1;
        }
        
        int count=0;
        for(auto it: m){
            if(ds.findUp(it.first)==it.first) count++;
        }
        return n - count;
        // return stones.size() - s.size();   
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends