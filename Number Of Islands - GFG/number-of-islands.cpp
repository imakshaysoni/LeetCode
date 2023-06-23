//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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



class Solution {
    private:
    bool isValid(int row, int col, int m, int n){
        return row>=0 && col>=0 && row<m && col<n;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
    DisjointSet ds(n * m);
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<int> ans;
    int count = 0;
    
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    
    for (auto it : operators) {
        int i = it[0];
        int j = it[1];
        
        if (grid[i][j] == 1) {
            ans.push_back(count);
            continue;
        }
        
        grid[i][j] = 1;
        count++;
        
        int node = i * m + j;
        
        for (int index = 0; index < 4; index++) {
            int newr = i + delrow[index];
            int newc = j + delcol[index];
            
            if (isValid(newr, newc, n, m) && grid[newr][newc] == 1) {
                int adjNode = newr * m + newc;
                if (ds.findUp(node) != ds.findUp(adjNode)) {
                  count--;
                  ds.unionBySize(node, adjNode);
                }
            }
        }

        ans.push_back(count);
    }
    return ans;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends