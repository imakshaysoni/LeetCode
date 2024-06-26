class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col1=1;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(matrix[row][col]==0){
                    matrix[row][0] = 0;
                    
                    if(col==0){
                        col1=0;
                    }
                    else{
                        matrix[0][col]=0;
                    }
                }
            }
        }
        
        for(int row=1;row<rows;row++){
            for(int col=1;col<cols;col++){
                if(matrix[row][0]==0 or matrix[0][col]==0){
                    matrix[row][col]=0;
                }
            }
        }
        
        if(matrix[0][0]==0){
            for(int col=1;col<cols;col++) matrix[0][col]=0;
        }
        
        if(col1==0){
            for(int row=0;row<rows;row++){
                matrix[row][0]=0;
            }
        }
        
    
        
    }
};