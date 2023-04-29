class Solution {
public:
#define mod 1000000007
int ans=0;
int knightDialer(int n) {
vector<vector<int>> mat(4,vector<int>(3,0));
vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n+1,-1)));
for(int i = 0; i < 4; i++) {
for(int j = 0; j < 3; j++) {
ans = (ans + helper(n-1,mat, i, j, dp)%mod) % mod;
}
}
return ans%mod;
}
int helper(int n, vector<vector<int>> &m, int i, int j, vector<vector<vector<int>>> &dp){
if(i<0 || i>=4 || j<0 || j>=3 || (i==3 && j!=1) ) return 0;
if(n==0) return 1;
if(dp[i][j][n]!=-1) return dp[i][j][n]%mod;
vector<int> dx = {-2,-2,-1,-1, 1, 1, 2, 2};
vector<int> dy = {-1, 1, 2,-2, 2,-2,-1, 1};
dp[i][j][n] = 0;
for(int index=0;index<8;index++){
dp[i][j][n]  = dp[i][j][n]%mod  + helper(n-1,m, i+dx[index], j+dy[index], dp)%mod;
}
return dp[i][j][n]%mod;
}
};