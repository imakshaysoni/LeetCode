class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        // return min(solve(cost, 0, dp), solve(cost, 1, dp));
        int n = cost.size();
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
        
    }

    int solve(vector<int> &cost, int idx, vector<int>&dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int op1 = cost[idx] + solve(cost, idx+1, dp);
        int op2 = cost[idx] + solve(cost, idx+2, dp);
        return dp[idx] = min(op1, op2);
    }
};