class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
//         Recurssive, Giving tle event after DP
        // return solve(prices, 0, 1, 1, k);
        
//         Tabulation Method
        //         Tabulation, beacuse Recurssion giving TLE 
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (k+n,0)));
        
//         
//         Preparing base Case
        // 1. If index==n then cap/buy can be anything ==0
        for(int buy=0;buy<=1;buy++){
            for(int count=0;count<=1;count++){
                dp[n][buy][count]=0;
            }
        }
//         if count==2 then index/buy can be anything ==0
        for(int index=0;index<n;index++){
            for(int buy=0;buy<=1;buy++){
                dp[index][buy][2]=0;
            }
        }
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int count=k-1;count>=0;count--){
                    int profit;
                    if(buy){
                        int op1=0,op2=0;
                        op1 = dp[index+1][0][count]-prices[index];
                        op2 = dp[index+1][1][count];
                        profit = max(op1, op2);
                        
                    }
                    else{
                        int op1=0, op2=0;
                        op1 = dp[index+1][1][count+1] + prices[index];
                        op2 = dp[index+1][0][count];
                        profit = max(op1,op2);
                        
                    }
                    dp[index][buy][count] = profit;                  
                    
                    
                }
            }
        }        
        return dp[0][1][0];
        
        
    }
    
    
    int solve(vector<int> &prices, int index, int buy, int count, int k){
        
        
        if(index==prices.size()) return 0;
        int profit;
        if(buy){
//             Buy it
            int op1=0,op2=0;
            if(count<=k) { op1 = solve(prices, index+1, 0, count+1, k)-prices[index]; }
            op2 = solve(prices, index+1, 1, count, k);
            profit = max(op1, op2);
            
            // profit = max(solve(prices, index+1, 0, count+1) - prices[index],
            //             solve(prices, index+1, 1, count));
        
        }
        else{
            int op1=0, op2=0;
            op1 = solve(prices,index+1,1,count, k) + prices[index];
            op2 = solve(prices, index+1, 0, count, k);
            profit = max(op1,op2);
            
            // profit = max(prices[index] + solve(prices, index+1, 1, count+1),
            //             solve(prices,index+1, 0, count+1));
            
        }
        return profit;
        
        
        
        
    }
};