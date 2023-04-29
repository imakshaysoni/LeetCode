class Solution {
public:
    #define mod 1000000007
    vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
    int final_ans=0;
    int knightDialer(int N) {
        unordered_map<int, vector<int>> m;
        
         vector<int> d1(10, 1), d2(10);
  for (; --N > 0; swap(d1, d2))
    for (auto i = 0; i < 10; ++i) 
        d2[i] = accumulate(begin(ms[i]), end(ms[i]), 0, [&](int s, int i) {return (s + d1[i]) % 1000000007;});
  return accumulate(begin(d1), end(d1), 0, [](int s, int n) {return (s + n) % 1000000007;});
        
        
//         m[1] = {6, 8};
//         m[2] = {7, 9};
//         m[3] = {4, 8};
//         m[4] = {0, 3, 9};
//         m[5] = {-1,-1};
//         m[6] = {0, 1, 7};
//         m[7] = {2, 6};
//         m[8] = {1, 3};
//         m[9] = {2, 4};
//         m[0] = {4, 6};
//         if(n==1) return 10;
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans += helper(n, m, 0)%mod;
//         }
        
//         return ans;
    }
    
    
    int helper(int n, unordered_map<int,vector<int>> &m, int index){
        
        if(n==0) return 1;
        if(index==-1) return 0;
        int sum=0;
        for(int i=0;i<n;i++){
            int op1 = helper(n-1, m,m[index][0])%mod;
            int op2 = helper(n-1, m,m[index][1])%mod;
            int op3=0;
            if(index==4 || index==6) int op3 = helper(n-1, m,m[index][2])%mod;
            sum+=op1+op2+op3;
        }       
        
        return sum;
        
    }
};