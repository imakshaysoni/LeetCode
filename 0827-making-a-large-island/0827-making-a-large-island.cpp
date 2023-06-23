class DisjointSet
{

    public:

        vector<int> parent, rank, size;
   	// Constructor to initialize the disjoint set with size n
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

   	// Find the representative (root) of the set to which node belongs (with path compression)
    int findUp(int node)
    {
        if (node == parent[node]) return node;

       	// Path compression by updating the parent of the node
        return parent[node] = findUp(parent[node]);
    }

   	// Union two sets based on rank
    int unionByRank(int u, int v)
    {
        if (parent[u] == parent[v]) return 0;

        int usp = findUp(u);	// Find representative of u's set
        int vsp = findUp(v);	// Find representative of v's set

        if (rank[usp] > rank[vsp])
        {
            parent[vsp] = usp;	// Set v's representative's parent as u's representative
        }
        else if (rank[vsp] > rank[usp])
        {
            parent[usp] = vsp;	// Set u's representative's parent as v's representative
        }
        else
        {
            parent[usp] = vsp;	// Set u's representative's parent as v's representative
            rank[vsp]++;	// Increment the rank of v's representative
        }
        return 1;
    }

   	// Union two sets based on size
    void unionBySize(int u, int v)
    {
        if (parent[u] == parent[v]) return;

        int usp = findUp(u);	// Find representative of u's set
        int vsp = findUp(v);	// Find representative of v's set

        if (size[usp] > size[vsp])
        {
            parent[vsp] = usp;	// Set v's representative's parent as u's representative
            size[usp] += size[vsp];	// Update the size of u's set
        }
        else
        {
            parent[usp] = vsp;	// Set u's representative's parent as v's representative
            size[vsp] += size[usp];	// Update the size of v's set
        }
    }
};

class Solution
{
    private:
        bool isValid(int row, int col, int m, int n)
        {
            return row >= 0 && col >= 0 && row < m && col < n;
        }
    public:
        int largestIsland(vector<vector < int>> &grid)
        {
           	// code here
            int n = grid.size();
            int m = grid[0].size();
            DisjointSet ds(n *m);
            vector<int> dx = { -1, 0, 1, 0 };
            vector<int> dy = { 0, 1, 0, -1};
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int nodeNo = i *m + j;
                    if (grid[i][j] == 1)
                    {
                        for (int index = 0; index < 4; index++)
                        {
                            int adjr = i + dx[index];
                            int adjc = j + dy[index];

                            if (isValid(adjr, adjc, n, m) and grid[adjr][adjc] == 1)
                            {
                                int adjNodeNo = adjr *m + adjc;
                                if (ds.findUp(adjNodeNo) != ds.findUp(nodeNo))
                                {
                                    ds.unionBySize(nodeNo, adjNodeNo);
                                }
                            }
                        }
                    }
                }
            }

           	// Check is all node is already 1
           	// int flag = false;
           	// for(int i=0;i < n;i++){
           	//     for(int j=0;j < m;j++){
           	//         if(grid[i][j]==0) {
           	//             flag = true;
           	//             break;
           	//         }
           	//     }
           	// }

           	// if(flag==false) return n*m;

           	//  Make Disjoint Set
            int maxSize = -1;
            set<int> s;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {

                    if (grid[i][j] == 0)
                    {
                        for (int index = 0; index < 4; index++)
                        {
                            int adjr = i + dx[index];
                            int adjc = j + dy[index];
                            if (isValid(adjr, adjc, n, m))
                            {
                                if (grid[adjr][adjc] == 1)
                                {
                                    int adjNodeNo = adjr *m + adjc;
                                    int ulp = ds.findUp(adjNodeNo);
                                    s.insert(ulp);
                                }
                            }
                        }

                        int localSize = 0;
                        for (auto it: s)
                        {
                            localSize += ds.size[it];
                        }
                        maxSize = max(maxSize, localSize + 1);
                        s.clear();
                    }
                }
            }
            if (maxSize == -1) return n * m;
            return maxSize;
        }
};