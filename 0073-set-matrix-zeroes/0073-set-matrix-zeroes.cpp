class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(matrix[row][col]==0){
                    zeros.push_back({row, col});
                }
            }
        }
        
        for(auto row_col: zeros){
            
            // make whole row as 0
            for(int i=0;i<cols;i++){
                matrix[row_col.first][i] = 0;
            }
            
            //make whole col as 0
            for(int j=0;j<rows;j++){
                matrix[j][row_col.second] = 0;
            }
        }
        
    }
};