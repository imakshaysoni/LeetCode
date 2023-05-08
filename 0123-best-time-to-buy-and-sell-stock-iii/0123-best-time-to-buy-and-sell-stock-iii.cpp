class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         Recursive Givin TLE Even After Memorization
        // int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (4,-1)));
        // return solve(prices, 0, 1, 0, dp);
        
        
//         Tabulation, beacuse Recurssion giving TLE 
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (4,0)));
        
//         
//         Preparing base Case
        // 1. If index==n then cap/buy can be anything ==0
//         for(int buy=0;buy<=1;buy++){
//             for(int count=0;count<=1;count++){
//                 dp[n][buy][count]=0;
//             }
//         }
// //         if count==2 then index/buy can be anything ==0
//         for(int index=0;index<n;index++){
//             for(int buy=0;buy<=1;buy++){
//                 dp[index][buy][2]=0;
//             }
//         }
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count>=0;count--){
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
    
    
    int solve(vector<int> &prices, int index, int buy, int count, vector<vector<vector<int>>> dp){
        
        
        if(index==prices.size()) return 0;
        if(count>=2) return 0;
        
        if(dp[index][buy][count]!=-1) return dp[index][buy][count];
        int profit;
        if(buy){
//             Buy it
            int op1=0,op2=0;
            op1 = solve(prices, index+1, 0, count, dp)-prices[index];
            op2 = solve(prices, index+1, 1, count, dp);
            profit = max(op1, op2);
            
            // profit = max(solve(prices, index+1, 0, count+1) - prices[index],
            //             solve(prices, index+1, 1, count));
        
        }
        else{
            int op1=0, op2=0;
            op1 = solve(prices,index+1,1,count+1, dp) + prices[index];
            op2 = solve(prices, index+1, 0, count, dp);
            profit = max(op1,op2);
            
            // profit = max(prices[index] + solve(prices, index+1, 1, count+1),
            //             solve(prices,index+1, 0, count+1));
            
        }
        return dp[index][buy][count] = profit;       
        
        
        
    }
};