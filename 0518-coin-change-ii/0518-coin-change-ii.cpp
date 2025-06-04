class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return solve(coins, amount, 0, dp);
    }

    int solve(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp){


        if(amount==0) return 1;
        if(amount < 0 or idx >= coins.size()) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        //op1`
        int op1 = solve(coins, amount - coins[idx], idx, dp);
        int op2 = solve(coins, amount, idx+1,dp);
        return dp[idx][amount] = op1 + op2;


    }
};