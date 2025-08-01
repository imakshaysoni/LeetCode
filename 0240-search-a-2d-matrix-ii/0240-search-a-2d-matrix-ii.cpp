class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row = 0;
        int col = cols-1;

        while(row<rows and col>=0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(target > matrix[row][col]){
                row++;
            }
            else{
                col--;
            }
        }
        
        return false;
        
    }
};