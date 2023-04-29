// class Solution {
// public:
//     #define mod 1000000007
//     vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
//     int final_ans=0;
//     int knightDialer(int N) {
//         unordered_map<int, vector<int>> m;
        
        
// //         m[1] = {6, 8};
// //         m[2] = {7, 9};
// //         m[3] = {4, 8};
// //         m[4] = {0, 3, 9};
// //         m[5] = {-1,-1};
// //         m[6] = {0, 1, 7};
// //         m[7] = {2, 6};
// //         m[8] = {1, 3};
// //         m[9] = {2, 4};
// //         m[0] = {4, 6};
// //         if(n==1) return 10;
// //         int ans=0;
// //         for(int i=0;i<n;i++){
// //             ans += helper(n, m, 0)%mod;
// //         }
        
// //         return ans;
//     }
    
    
//     int helper(int n, unordered_map<int,vector<int>> &m, int index){
        
//         if(n==0) return 1;
//         if(index==-1) return 0;
//         int sum=0;
//         for(int i=0;i<n;i++){
//             int op1 = helper(n-1, m,m[index][0])%mod;
//             int op2 = helper(n-1, m,m[index][1])%mod;
//             int op3=0;
//             if(index==4 || index==6) int op3 = helper(n-1, m,m[index][2])%mod;
//             sum+=op1+op2+op3;
//         }       
        
//         return sum;
        
//     }
// };

static const int MOD = 1000000007;
using VI = vector< int >;
using VVI = vector< VI >;
VVI memo=VVI( 5001, VI(10,1L) );
class Solution {
    VVI hops{ {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4} };
    long go( int N, int digit, long result = 0L ){
        if( N-1 == 0 || memo[ N ][ digit ] > 1L )
            return memo[ N ][ digit ];
        for( auto hop: hops[ digit ] )
            result += go( N-1, hop ) % MOD;
        return memo[ N ][ digit ] = result % MOD;
    }
public:
    int knightDialer( int N, long result=0L ){
        for( int digit = 0;  digit < 10;  ++digit )
            result += go( N, digit ) % MOD;
        return static_cast<int>( result % MOD );
    }
};