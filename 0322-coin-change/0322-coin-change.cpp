class Solution {
public:
    // int count  = 0;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int s=0;
        // vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,-1));
         vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = helper(coins, amount, 0, dp);
        return (ans < INT_MAX-1)?ans:-1;
        
        
        
    }
    
    
    int helper(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){
        // if(amount == 0) return 0;
        
        // if(n < 0 || amount < 0) return INT_MAX-1;      
        
        if(amount==0) return 0;       
        if(i>=coins.size() || amount < 0) return INT_MAX-1;
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int op1 = 1+helper(coins, amount-coins[i], i, dp);
        int op2 = helper(coins, amount, i+1, dp);
        dp[i][amount] = min(op1,op2);
        return dp[i][amount];
        
        // return min(op1,op2);
//         if(op1&&op2) {
//             cout<<op1<<" "<<op2<<endl;
//             return min(op1,op2);}
//         if(op1) return op1;
//         else return op2;
        
    }
};
