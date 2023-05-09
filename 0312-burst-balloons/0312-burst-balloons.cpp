class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solve(nums,1,n, dp);
        
//         Tabulation
//     i -> 1, n & j-> n-0 REvese this in tabulation
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        
//         base case when i>j dp[i][j] should be = 0
        for(int i=n;i>0;i--){
            for(int j=0;j<=n;j++){
                if(i>j) continue;
                int maxi = INT_MIN;
                for(int index=i;index<=j;index++){

                    int cost = nums[i-1]*nums[index]*nums[j+1]
                        + dp[i][index-1] + dp[index+1][j];
                    maxi = max(maxi,cost);            
                }

                dp[i][j] = maxi;      
                
            }
        }        
        return dp[1][n];
        
    }
    
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int index=i;index<=j;index++){
            
            int cost = nums[i-1]*nums[index]*nums[j+1]
                + solve(nums, i, index-1, dp)
                + solve(nums, index+1, j, dp);
            maxi = max(maxi,cost);            
        }
        
        return dp[i][j] = maxi;        
        
        
    }
};