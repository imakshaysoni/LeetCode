class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int ans = 0;
        vector<int> res = {-1, -1};
        int rows = mat.size();
        int cols = mat[0].size();
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(mat[row][col] > ans){
                    ans = mat[row][col];
                    res= {row, col};
                }
            }
        }
        return res;   
    }
};