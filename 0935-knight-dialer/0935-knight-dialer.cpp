class Solution {
public:
    #define mod 1000000007
    vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
    int final_ans=0;
    int knightDialer(int n) {
        vector<vector<long>> dp(10,vector<long>(n+1,-1));
        if(n==1) return 10;
        long ans=0L;
        for(int digit=0;digit<10;digit++){
            ans += helper(n, digit, dp) % mod;
        }
        
        return static_cast<int>( ans % mod );
    }
    
    
    int helper(int n, int digit, vector<vector<long>>&dp){
        
        if(n-1==0) return 1;
        
        // if(m[digit][0]==-1) return 0;
        
        if(dp[digit][n]!=-1) return dp[digit][n];
        long sum=0L;
        // int op1 = helper(n-1, m,m[digit][0])%mod;
        // int op2 = helper(n-1, m,m[digit][1])%mod;
        // int op3=0;
        // if(digit==4 || digit==6) int op3 = helper(n-1, m,m[digit][2])%mod;
        // sum+=op1+op2+op3;
        
        for(auto x: ms[digit]){
            sum+=helper(n-1,x,dp) % mod;
        }
        
        return dp[digit][n] = sum%mod;
        
    }
};

// static const int MOD = 1000000007;
// using VI = vector< int >;
// using VVI = vector< VI >;
// VVI memo=VVI( 5001, VI(10,1L) );
// class Solution {
//     VVI hops{ {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4} };
//     long go( int N, int digit, long result = 0L ){
//         if( N-1 == 0 || memo[ N ][ digit ] > 1L )
//             return memo[ N ][ digit ];
//         for( auto hop: hops[ digit ] )
//             result += go( N-1, hop ) % MOD;
//         return memo[ N ][ digit ] = result % MOD;
//     }
// public:
//     int knightDialer( int N, long result=0L ){
//         for( int digit = 0;  digit < 10;  ++digit )
//             result += go( N, digit ) % MOD;
//         return static_cast<int>( result % MOD );
//     }
// };