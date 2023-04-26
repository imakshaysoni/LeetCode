class Solution {
public:    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
//         FLood FIll Algorithm
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int maxCount = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    // getCnt(grid, m,n,i,j,count);
                    count = helper(grid, i, j);
                }
                maxCount = max(maxCount,count);
                count=0;
            }
        }        
        return maxCount;                
    }
    
    int helper(vector<vector<int>> &m, int row, int col){
        
        if(row<0 || row >= m.size() || col<0 || col>=m[0].size() || m[row][col]==0) return 0;
        int count = 0 ;
        count++;
        m[row][col]=0;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        for(int index=0;index<4;index++){
            count = count + helper(m, row+dx[index], col+dy[index]);
        }
        return count;
        
        
    }
    
    void getCnt(vector<vector<int>> &grid, int m, int n, int i, int j,int &count){
         
        if( i<0 || i==m || j<0 || j==n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        count++;
        vector<int> x = {0,0,1,-1};
        vector<int> y = {-1,1,0,0};        
    
        for(int index=0;index<4;index++){
            getCnt(grid, m, n, i+x[index], j+y[index], count);    
        }
        return;   
    }
    
};