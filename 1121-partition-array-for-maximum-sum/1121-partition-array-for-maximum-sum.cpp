class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(arr, 0, k, dp);
    //     vector<int> dp(arr.size(), 0);
    //     int n = arr.size();

    //     for(int i=0;i<n;i++){
    //         int maxi = 0;
    //         int curr_max = 0;
    //         for(int j=i;j<arr.size() && j-i+1<=k;j++){
    //             curr_max = max(curr_max, arr[j]);
    //             if(j+1 < n ) maxi = max(maxi, dp[j+1] + curr_max*(j-i+1));
    //         }
    //         dp[i] = maxi;
    // }
    // return dp[n-1];
    }
    int solve(vector<int> &arr, int i, int k, vector<int> &dp){
        if(i >=arr.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int maxi = 0;
        int curr_max = 0;
        for(int j=i;j<arr.size() && j-i+1<=k;j++){
            curr_max = max(curr_max, arr[j]);

            maxi = max(maxi, solve(arr, j+1, k, dp) + curr_max*(j-i+1));
            // int res = solve(arr, j+1, k);
            
            // int sum = 0;
            // for(int p=i;p<j;p++){
            //     sum = max(sum, arr[p]);
            // }
            // maxi = max(maxi, res +  sum * (j-i+1));

        }
        return dp[i] = maxi;

    }
};