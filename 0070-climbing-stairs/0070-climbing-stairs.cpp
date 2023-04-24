class Solution {
public:
    int climbStairs(int n) {
        
        int ways=0;
        vector<int> dp(n+1, -1);
        ways = helper(n, dp, 0);
        return ways;
        
    }
    
    int helper(int n, vector<int> &dp, int i){
     
//         TLE Now need to add DP
        if(i==n){
            return 1;
        }
        if(i>n) return 0;
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        dp[i] = helper(n, dp, i+1) + helper(n, dp, i+2);
        return dp[i];
//         Taking one step
//         helper(n, dp, i+1);
// //     taking 2 steps
//         helper(n, dp, i+2);
        
    }
};