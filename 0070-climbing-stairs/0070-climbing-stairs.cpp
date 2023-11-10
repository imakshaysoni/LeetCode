class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, 0, dp);
    }
    
    int solve(int n, int index, vector<int> &dp){
        
        if(index==n) return 1;
        if(index>n) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        int op1 = solve(n, index+1, dp);
        int op2 = solve(n, index+2, dp);
        
        dp[index] = op1+op2;
        
        return dp[index];
    }
};