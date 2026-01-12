class Solution {
public:
int dsu_find(int node, vector<int> & parent){
        if(node==parent[node]) return node;
        return parent[node] = dsu_find(parent[node], parent);
    }
    
    void dsu_union(int u, int v, vector<int> &parent){
        int parent_u = dsu_find(u, parent);
        int parent_v = dsu_find(v, parent);
        
        if(parent_u==parent_v) return;
        
        parent[parent_u] = parent_v;
        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        unordered_map<string,int> mapp;
        
        for(int i=0;i<details.size();i++){
            for(int j=1;j<details[i].size();j++){
                string email = details[i][j];
                if(mapp.count(email)){
                    int firstNode=i;
                    int secondNode= mapp[email];
                    dsu_union(firstNode, secondNode, parent);
                }
                else{
                    mapp[email] = i;
                }
            }
            
        }
        vector<vector<string>> mergedNodes(n);
        
        for(auto iter: mapp){
            string email = iter.first;
            int node = iter.second;
            int parentNode = dsu_find(node, parent);
            mergedNodes[parentNode].push_back(email);
        }
        
        vector<vector<string>> result;
        for(int i=0;i<mergedNodes.size();i++){
            if(mergedNodes[i].size() == 0) continue;
            string name = details[i][0]; 
            
            vector<string> temp;
            temp.push_back(name);
            
            sort(mergedNodes[i].begin(), mergedNodes[i].end());
            
            for(int j=0;j<mergedNodes[i].size();j++){
                temp.push_back(mergedNodes[i][j]);
            }
            result.push_back(temp);
        }
        
        return result;
    }
};