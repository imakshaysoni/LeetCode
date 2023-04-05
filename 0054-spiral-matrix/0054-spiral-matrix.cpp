class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int top=0;
        int left=0;
        int right=n-1;
        int bottom = m-1;
        
        while(top <= bottom and left <= right ){
            
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;i>=left && top <= bottom;i--){
                v.push_back(matrix[bottom][i]);            
            }
            bottom--;
            for(int i=bottom;i>=top && left<=right;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
            
        }
     return v;   
        
    }
};