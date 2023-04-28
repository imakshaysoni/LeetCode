class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
        
//        int n = nums.size();
//         if(n==1) return nums[0];
//         // if(n==2) return max(nums[0],nums[1]);
//         // if(n==3) return max(nums[0],max(nums[1],nums[2]));
        
        
//         vector<int> dp(nums.size()+1, -1);
        
//         int op1 = helper(nums,1,n-1, dp);
//         int op2 = helper(nums,0,n-2,dp);
        
//         return max(op1,op2);
        
// //         vector<int> dp(nums.size()+2,0);
// //         for(int i=nums.size()-1;i>=0;i--){
// //             int op1 = nums[i]+dp[i+2];
// //             int op2 = dp[i+1];
// //             dp[i] = max(op1,op2);
// //         }
        
// //         return dp[0];
//     }
    
// //     Recursive
//     int helper(vector<int> &nums, int i, int n, vector<int> &dp){
       
//         if(i>=n) return 0;
        
//         if(dp[i]!=-1) return dp[i];
        
//         int op1, op2;
//         op1 = nums[i] + helper(nums, i+2, n, dp);
//         op2 = helper(nums,i+1, n, dp);
//         dp[i] = max(op1,op2);
        
//         return dp[i];      
        
//     }
    
// };