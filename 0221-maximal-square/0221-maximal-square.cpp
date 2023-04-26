// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& m) {
//         int maxCount = 0;
//         for(int row=0;row<m.size();row++){
//             for(int col=0;col<m[0].size();col++){
//                 if(m[row][col]=='1'){
//                     int area = 0;
//                     area = helper(m, row, col);
//                     maxCount = max(maxCount,area);
//                 }
//             }
//         }
//         return maxCount*maxCount;        
//     }
    
//     int helper(vector<vector<char>> &m, int row, int col){
        
//         if(row<0 || row>=m.size() || col<0 || col>=m[0].size() || m[row][col]=='0') return 0;
// //         
//         int count =0;
//         count++;
        
// //         right Count
//         int rightCnt=0;
//         for(int j=col;j<m[0].size();j++){
//             if(m[row][j]=='1') rightCnt++;
//             else break;
//         }
        
//         int downCnt=0;
//         for(int i=row;i<m.size();i++){
//             if(m[i][col]=='1') downCnt++;
//             else break;
//         }
        
//         int digCnt=0;
//         for(int i=row,j=col;i<m.size() && j<m[0].size();j++,i++){
//             if(m[i][j]=='1') digCnt++;
//             else break;
//         }
        
//         int minCount = min(min(rightCnt, downCnt), digCnt);
//         int cnt = 0;
//         for(int i=row+1;i<row+minCount;i++){
//             for(int j=col+1;j<col+minCount;j++){
//                 // cout<<i<<" "<<j<<endl;
//                 if(m[i][j]=='0'){
//                     // return cnt*cnt;
//                     return i-row+1;
//                 }
//             }
//         }        
//         // minCount = min(cnt)
//         return minCount;
//         return minCount*minCount;
        
//     }
    
    
// };

class Solution {
public:
    int maxAns = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        
        // int x = helper(matrix,0,0, dp);
        int x = dpBottomUp(matrix);
        return maxAns*maxAns;
    }
    
    int helper(vector<vector<char>> &mat, int i, int j, vector<vector<int>> &dp){
        
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int rightCnt = helper(mat, i, j+1, dp);
        int digCnt = helper(mat, i+1, j+1, dp);
        int downCnt = helper(mat, i+1, j, dp);
        
        if(mat[i][j]=='1'){
            int ans = 1+min(rightCnt,min(downCnt,digCnt));
            dp[i][j]=ans;
            maxAns = max(maxAns, ans);
            return ans;
        }
        else{
            return dp[i][j]=0;
        }          
        
        
    }
    
    int dpBottomUp(vector<vector<char>> &mat){
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row+1,vector<int> (col+1,0));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                
                int rightCnt = dp[i][j+1];
                int digCnt = dp[i+1][j+1];
                int downCnt = dp[i+1][j];
                
                if(mat[i][j]=='1'){
                    dp[i][j]=1+min(rightCnt,min(digCnt,downCnt));
                    maxAns = max(maxAns, dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return 0;
        
    }
};