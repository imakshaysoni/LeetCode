class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int max=0;
        // for(int i=0;i<prices.size()-1;i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         if(prices[j]-prices[i] > max){
        //             max=prices[j]-prices[i];
        //         }
        //     }
        // }
        int max_profit=0;
        int min_price=INT_MAX;
        for (int i=0;i<prices.size();i++){
            min_price=min(prices[i],min_price);
            int profit = prices[i]-min_price;
            max_profit = max(profit,max_profit);
        }
        return max_profit;
    }
};