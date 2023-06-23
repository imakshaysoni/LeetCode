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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string, int> map;
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                
                string email = accounts[i][j];
                if(map.find(email)!=map.end()){
                    int firstNode = i;
                    int secondNode = map[email];
                    ds.unionByRank(firstNode, secondNode);
                }
                else{
                    map[email] = i; 
                }                
                
            }
        }
        
        vector<string> mergedMails[accounts.size()];
        for(auto it: map){
            string mail  = it.first;
            int node  = it.second;
            int pNode = ds.findUp(node);
            mergedMails[pNode].push_back(mail);
        }    
        
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            if(mergedMails[i].size()==0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMails[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};