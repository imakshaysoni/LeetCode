// class Solution {
// public:
//     int maxLen = INT_MIN;
//     int lengthOfLIS(vector<int>& nums) {
//         // int n = nums.size();
//         // vector<int> subset;
//         vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1, -1));
//         int ans = LenHelper(nums, 0,-1, dp);
//         return ans;
//     }
    
//     int LenHelper(vector<int> &nums, int index, int prev, vector<vector<int>> &dp){
        
//         if(index==nums.size()) return 0;
        
//         if(dp[index][prev+1] != -1) return dp[index][prev+1];
        
// //        not Take it
//         int op1 =LenHelper(nums, index+1, prev, dp);
        
// //         Take it
//         int op2=0;
//         if(prev == -1 || nums[index] > nums[prev])
//         {
//             op2 = 1 + LenHelper(nums, index+1,index, dp);
//         }
        
//         return dp[index][prev+1] = max(op1,op2);
//     }
    
// //     void helper(vector<int> &nums, vector<int> &subset, int i){
        
// //         // if(i>nums.size()) return;
// //         if(i==nums.size()){
// //             for(auto x: subset) cout<<x<<" ";
// //             int len = subset.size();
// //             maxLen = max(len,maxLen);
// //             cout<<endl;
// //             return;
// //         }
        
// //         if(subset.size()>0 && nums[i] > subset.back()){
// // //         Take it
// //             subset.push_back(nums[i]);
// //             helper(nums,subset,i+1);    
            
// //         }        
        
// //         if(i==0){ subset.push_back(nums[i]); helper(nums,subset,i+1); }
        
// //         // leave it
// //         if(subset.size()>0)  subset.pop_back();
// //         helper(nums,subset,i+1);
// //         return;
        
// //     }
// };

class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));   // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int i, int prev_i) {
        if(i >= size(nums)) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int take = 0, dontTake = solve(nums, i + 1, prev_i);
        if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + solve(nums, i + 1, i); // try picking current element if no previous element is chosen or current > nums[prev_i]
        return dp[i][prev_i+1] = max(take, dontTake);
    }
};