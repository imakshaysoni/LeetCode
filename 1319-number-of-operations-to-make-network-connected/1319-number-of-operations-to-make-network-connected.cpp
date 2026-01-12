
class Solution {
public:

    int dsu_find(int node, vector<int> &parent){
        if(node==parent[node]) return node;
        return parent[node] = dsu_find(parent[node], parent); // Path Compression
    }

    void dsu_union(int a, int b, vector<int> & parent, vector<int> &rank){
        int a_parent = dsu_find(a, parent);
        int b_parent = dsu_find(b, parent);
        if(a_parent==b_parent) return;

        if(rank[a_parent] > rank[b_parent]){
            parent[b_parent] = a_parent;
        }
        else if(rank[b_parent] > rank[a_parent]){
            parent[a_parent] = b_parent;
        }
        else{
            parent[b_parent] = a_parent;
            rank[a_parent] += 1;
        }
        return;
    }



    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size()<n-1) return -1;
        
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i] = i;

        vector<int> rank(n, 0);

        for(auto iter: connections){
            dsu_union(iter[0], iter[1], parent, rank);
        }

        int count =0;
        for(int i=0;i<n-1;i++){
            if(dsu_find(i, parent) != dsu_find(i+1, parent)){
                dsu_union(i, i+1, parent, rank);
                count++;
            }
        }

        return count;

    }
};