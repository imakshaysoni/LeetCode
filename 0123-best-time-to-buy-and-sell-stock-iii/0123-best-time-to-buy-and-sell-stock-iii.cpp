class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        // return get_profit(prices, 0, 0, dp, 0);
        // return tabulation_code(prices, n);    
        return space_optimized(prices, n);
        
    }
    
    int space_optimized(vector<int>&prices, int n){
        //         Space Optimized
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
//         First Base case; When k == 2, whatever idx & buy, it shoudl be 0
//         for(int idx=0;idx<n;idx++){
//             for(int buy=0;buy<2;buy++){
//                 dp[idx][buy][2] = 0;
//             }
//         }
        
// //         SecondBase Case; When idx==n, whatever buy & cap, it should be 0
//         for(int idx=0;idx<n;idx++){
//             for(int buy=0;buy<2;buy++){
//             for(int k=0;k<=2;k++){
//                 dp[idx][buy][k] = 0;
//                 }
//             }    
//         }
        
        
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    if(j==0){
                    int op1 = -prices[i] + ahead[1][k]; //  get_profit(prices, idx+1, 1, dp, k);
                    int op2 = ahead[0][k]; //get_profit(prices, idx+1, 0, dp, k);
                    curr[j][k] = max(op1, op2);
                    }
                    else{
                        int op3 = prices[i] + ahead[0][k+1]; //get_profit(prices, idx+1, 0, dp, k+1);
                        int op4 = ahead[1][k]; //get_profit(prices, idx+1, 1, dp, k);            
                        curr[j][k] = max(op3, op4);
                    } 
                }
                
            }
            ahead = curr;
        }
        
        return ahead[0][0];

    }
    
    
    int tabulation_code(vector<int>&prices, int n){
        //         Tabulation
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
//         First Base case; When k == 2, whatever idx & buy, it shoudl be 0
        for(int idx=0;idx<n;idx++){
            for(int buy=0;buy<2;buy++){
                dp[idx][buy][2] = 0;
            }
        }
        
//         SecondBase Case; When idx==n, whatever buy & cap, it should be 0
        for(int idx=0;idx<n;idx++){
            for(int buy=0;buy<2;buy++){
            for(int k=0;k<=2;k++){
                dp[idx][buy][k] = 0;
                }
            }    
        }
        
        
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    if(j==0){
                    int op1 = -prices[i] + dp[i+1][1][k]; //  get_profit(prices, idx+1, 1, dp, k);
                    int op2 = dp[i+1][0][k]; //get_profit(prices, idx+1, 0, dp, k);
                    dp[i][j][k] = max(op1, op2);
                    }
                    else{
                        int op3 = prices[i] + dp[i+1][0][k+1]; //get_profit(prices, idx+1, 0, dp, k+1);
                        int op4 = dp[i+1][1][k]; //get_profit(prices, idx+1, 1, dp, k);            
                        dp[i][j][k] = max(op3, op4);
                    } 
                }
                
            }
        }
        
        return dp[0][0][0];

    }
    
    int get_profit(vector<int>&prices, int idx, int buy, vector<vector<vector<int>>>&dp, int k){
        
        if(idx==prices.size() || k==2 ) return 0;
        
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        
        if(buy==0){
            int op1 = -prices[idx] + get_profit(prices, idx+1, 1, dp, k);
            int op2 = get_profit(prices, idx+1, 0, dp, k);
            return dp[idx][buy][k] = max(op1, op2);
            // return max(op1, op2);
        }
        else{
            int op3 = prices[idx] + get_profit(prices, idx+1, 0, dp, k+1);
            int op4 = get_profit(prices, idx+1, 1, dp, k);            
            return dp[idx][buy][k] = max(op3, op4);
            // return max(op3, op4);
        }
        
        
    }
};