class Solution {
public:
int dsu_find(int node, vector<int> &parent){
        if(node==parent[node]) return node;
        return parent[node] = dsu_find(parent[node], parent); // Path Compression
    }

    void dsu_union(int a, int b, vector<int> & parent, vector<int> & union_size){
        int a_parent = dsu_find(a, parent);
        int b_parent = dsu_find(b, parent);
        if(a_parent==b_parent) return;

        if(union_size[a_parent] > union_size[b_parent]){
            parent[b_parent] = a_parent;
            union_size[a_parent] += union_size[b_parent];
        }
        else if(union_size[b_parent] > union_size[a_parent]){
            parent[a_parent] = b_parent;
            union_size[b_parent] += union_size[a_parent];
        }
        else{
            parent[b_parent] = a_parent;
            union_size[a_parent] += union_size[b_parent];
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int> union_size(n, 1);
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto iter: edges){
            int u = iter[0];
            int v = iter[1];
            dsu_union(u,v, parent, union_size);
        }

        vector<int> vec;
        for(int i=0;i<n;i++){
            if(parent[i]==i) vec.push_back(union_size[i]);
        }

        long long ans= 0;
        long long prefixSum= 0;

        for (int x : vec) {
            ans += prefixSum * x;
            prefixSum += x;
        }

        return ans;  
    }
};