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
                getCnt(grid, m,n,i,j,count);
                maxCount = max(maxCount,count);
                count=0;
            }
        }        
        return maxCount;                
    }
    
    void getCnt(vector<vector<int>> &grid, int m, int n, int i, int j,int &count){
         
        if( i<0 || i==m || j<0 || j==n || grid[i][j] == 0 || grid[i][j] == '*') return;
        grid[i][j] = '*';
        count++;
        vector<int> x = {0,0,1,-1};
        vector<int> y = {-1,1,0,0};        
    
        for(int index=0;index<4;index++){
            getCnt(grid, m, n, i+x[index], j+y[index], count);    
        }
        return;   
    }
    
};