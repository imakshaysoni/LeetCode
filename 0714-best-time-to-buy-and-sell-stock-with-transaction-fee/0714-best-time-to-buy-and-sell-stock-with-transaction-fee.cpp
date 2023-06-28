class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return solve(prices, 0, 1, 0, dp, fee);
        
    }
    
    
    int solve(vector<int> &prices, int index, int buy, int count, vector<vector<int>> &dp, int fee){
        
        
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit;
        if(buy){
//             Buy it
            profit = max(solve(prices, index+1, 0, count+1, dp, fee) - prices[index] - fee,
                        solve(prices, index+1, 1, count, dp, fee));
        
        }
        else{
            profit = max(prices[index] + solve(prices, index+1, 1, count+1, dp, fee),
                        solve(prices,index+1, 0, count+1, dp, fee));
            
        }
        dp[index][buy]=profit;
        return dp[index][buy];
        
    }
};