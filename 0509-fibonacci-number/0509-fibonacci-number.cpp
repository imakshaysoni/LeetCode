class Solution {
public:
    int fib_dp(int n, vector<int> &dp){
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fib_dp(n-1,dp)+fib_dp(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(100,-1);
        return fib_dp(n, dp);
        // if(n==0)return 0;
        // if(n==1)return 1;
        // int a=0;
        // int b=1;
        // int c;
        // for(int i=2;i<=n;i++){
        //         c=a+b;
        //         a=b;
        //         b=c;
        // }
        // return c;
    }
};