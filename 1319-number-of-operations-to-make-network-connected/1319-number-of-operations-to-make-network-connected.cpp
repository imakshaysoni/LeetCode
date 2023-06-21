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
			size[vsp] = size[vsp] + size[usp]; // Update the size of v's set
		}
	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // code here
        int initial_edges = connections.size();
        if(n > initial_edges + 1) return -1;
        DisjointSet ds(n-1);
        int cntExtras=0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUp(u)== ds.findUp(v)) cntExtras++;
            else ds.unionBySize(u,v);
            initial_edges++;
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findUp(i) == i) count++;
        }
        if(cntExtras>=count-1) return count-1;
        return -1;
    }
};