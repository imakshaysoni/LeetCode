class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
        
    }

    int solve(vector<int> &cost, int idx, vector<int>&dp){


        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int op1 = cost[idx] + solve(cost, idx+1, dp);
        int op2 = cost[idx] + solve(cost, idx+2, dp);
        return dp[idx] = min(op1, op2);
    }
};