// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(510, vector<int> (nums.size()+500, -1));
//         if(n<2) return n;
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 ans = max(ans, 2 + solve(i, nums[j]-nums[i], nums, dp));
//             }
//         }
//         return ans;
//     }
    
//     int solve(int index, int diff, vector<int> &nums, vector<vector<int>> &dp){
//         if(index<0) return 0;
        
//         if(dp[diff][index]!=-1) return dp[diff][index];
        
//         int ans = 0;
        
//         for(int j=index-1;j>=0;j--){
//             if(nums[index]-nums[j]==diff){
//                 ans = max(ans, 1 + solve(j, diff, nums, dp));
//             }
//         }        
//         return dp[diff][index]=ans;
//     }
// };

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size(),ans=0;
        int maxval=0;
        for(int a:A)
            maxval=max(a,maxval);
        vector<vector<int>> dp(2*maxval+1,vector<int>(n,0));
        
        for(int i=1;i<n;++i)
            for(int j=0;j<i;++j)
            {
                int dif=A[i]-A[j]+maxval;
                dp[dif][i]=dp[dif][j]+1;
                ans=max(ans,dp[dif][i]);
                
            }

        return ans+1;
    }
};