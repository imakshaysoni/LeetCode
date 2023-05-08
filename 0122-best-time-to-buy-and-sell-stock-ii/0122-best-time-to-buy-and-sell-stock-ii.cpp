class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
//         Another Approch found in discussion section, it is also easy
//         int profit=0;
//         for(int i=0;i<prices.size()-1;i++){
//             profit += max(prices[i+1]-prices[i],0);
//         }
//         return profit;
        
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
};