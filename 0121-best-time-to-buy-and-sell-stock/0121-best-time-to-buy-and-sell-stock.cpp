class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0];
        int max_profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] < buy) buy = prices[i];
            else{
                int profit = prices[i]-buy;
                max_profit = max(profit, max_profit);
            }
        }
        
        return max_profit;
    }
};