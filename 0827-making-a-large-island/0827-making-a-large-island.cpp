class DisJointSet{
    public:
        
        vector<int> parent, rank, size;
        DisJointSet(int n){
            parent.resize(n);
            rank.resize(n, 0);
            size.resize(n, 1);
        }

        int DisJointFind(int node){
            if(node==parent[node]) return node;

            return parent[node] = DisJointFind(parent[node]);
        }

        void DisJointUnion(int u, int v){
            
            int parent_u = DisJointFind(u);
            int parent_v = DisJointFind(v);

            if(parent_u == parent_v) return;

            parent[parent_v] = parent_u;
            return;

        }


        void DisJointUnionByRank(int u, int v){
            int parent_u = DisJointFind(u);
            int parent_v = DisJointFind(v);

            if(parent_u == parent_v) return;

            if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
            }
            else if( rank[parent_v] > rank[parent_u]){
                parent[parent_u] = parent_v;
            }
            else{
                parent[parent_v] = parent_u;
                rank[parent_u] += 1;
            }
            return;
        }

        void DisJointUnionBySize(int u, int v){
            int parent_u = DisJointFind(u);
            int parent_v = DisJointFind(v);

            if(parent_u == parent_v) return;

            if(size[parent_u] > size[parent_v]){
                parent[parent_v] = parent_u;
                size[parent_u] += size[parent_v];
            }
            else if( size[parent_v] > size[parent_u]){
                parent[parent_u] = parent_v;
                size[parent_v] += size[parent_u];
            }
            else{
                parent[parent_v] = parent_u;
                size[parent_u] += size[parent_v];
            }
            return;
        }
    };

class Solution {
public:
    bool isValid(int row, int col, vector<vector<int>> &grid){
        if(row <0 || row>=grid.size() 
    || col <0 || col >= grid[0].size() || grid[row][col]==0) return false;
         return true;
    }

    void dsu_join(vector<vector<int>> &grid, int row, int col, DisJointSet &ds){
        int firstNode = row * grid[0].size() + col;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(abs(dx)==abs(dy)) continue;

                int nrow = row + dx;
                int ncol = col + dy;
                if(isValid(nrow, ncol, grid)){
                    int secondNode = nrow * grid[0].size() + ncol;
                    ds.DisJointUnionBySize(firstNode, secondNode);
                }
            }
        }


    }
    int largestIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        DisJointSet ds(rows*cols);
        for(int i=0;i<rows*cols;i++) ds.parent[i]=i;     
        
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==1){
                    dsu_join(grid, row, col, ds);
                }
            }
        }
        
        set<int> st;
        int ans = -1;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==0){
                    for(int dx=-1;dx<=1;dx++){
                        for(int dy=-1;dy<=1;dy++){
                            if(abs(dx)==abs(dy)) continue;
                            int nrow = row + dx;
                            int ncol = col + dy;
                            if(isValid(nrow, ncol, grid)){                                
                                int node = nrow * cols + ncol;
                                int parentNode = ds.DisJointFind(node);
                                st.insert(parentNode);
                            }
                        }
                    }

                    int temp=1;
                    for(auto it: st){
                        temp += ds.size[it];
                    }
                    ans = max(ans, temp);
                    st.clear();

                }
                
            }
        }

        if(ans==-1) return rows*cols;

        return ans;
        


        
    }
};