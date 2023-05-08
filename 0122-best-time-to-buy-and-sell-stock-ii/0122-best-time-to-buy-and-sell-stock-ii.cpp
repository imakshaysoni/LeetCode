class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
//         Recurssion
        // vector<vector<int>> dpRecur(prices.size()+1, vector<int> (2,-1));
        // return solve(prices, 0, 1, dpRecur);
        
//         Tablutation Bottom UP DP
        int n=prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int> (2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){    
                int profit;
                if(buy){
                    profit = max(dp[index+1][0]-prices[index], dp[index+1][1]);
                    
                }
                else{
                    profit=max(dp[index+1][1] + prices[index],dp[index+1][0]);
                }
                dp[index][buy]=profit;                
                
            }            
        }
        return dp[0][1];
        
    }
    
    
    int solve(vector<int> &prices, int index, int buy, vector<vector<int>> &dp){
        
        if(index==prices.size()) return 0;
        
        if(dp[index][buy]!=-1) return dp[index][buy];
        
        if(buy){
//             Buy it 
            int p1 = solve(prices, index+1, 0, dp) - prices[index];
            
//             Not buy it
            int p2 = solve(prices, index+1, 1, dp);
            
            return dp[index][buy]=max(p1,p2);
        }
        else{
//             sell it now
            int p3 = prices[index] + solve(prices, index+1, 1, dp);
            
//             not sell it
            int p4 = solve(prices, index+1, 0, dp);
            return dp[index][buy]=max(p3,p4);
            
        }        
        
        
    }
    
    int myMethod(vector<int> &prices){
        // My Approch, without any hint
        int min_price=INT_MAX;
        int max_profit=0;
        int final_profit=0;
        for(int i=0;i<prices.size();i++){
            min_price = min(prices[i],min_price);
            int profit = prices[i]-min_price;
            max_profit=max(profit,max_profit);
            
            
            if(i>0 && prices[i]<prices[i-1]){
                final_profit+=max_profit;
                min_price=prices[i];
                max_profit=0;
            }
        }
        return max_profit+final_profit;
    }
    
    int AnotherApproch(vector<int> &prices){
//         Another Approch found in discussion section, it is also easy
        int profit=0;
        for(int i=0;i<prices.size()-1;i++){
            profit += max(prices[i+1]-prices[i],0);
        }
        return profit;
    }
};