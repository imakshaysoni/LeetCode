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