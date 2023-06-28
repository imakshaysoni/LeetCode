class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return solve(prices, 0, 1, 0, dp);
        
    }
    
    
    int solve(vector<int> &prices, int index, int buy, int count, vector<vector<int>> &dp){
        
        
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit;
        if(buy){
//             Buy it
            profit = max(solve(prices, index+1, 0, count+1, dp) - prices[index],
                        solve(prices, index+1, 1, count, dp));
        
        }
        else{
            profit = max(prices[index] + solve(prices, index+2, 1, count+1, dp),
                        solve(prices,index+1, 0, count+1, dp));
            
        }
        dp[index][buy]=profit;
        return dp[index][buy];
        
    }
};