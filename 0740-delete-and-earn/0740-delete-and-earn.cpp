class Solution {
public:
    int max_ans= 0;
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1, 0);
        sort(nums.begin(), nums.end());
        return helper(nums, 0, dp);
        // cout<<max_ans;
        
        // return max_ans;
        
        
    }
    
    
    int helper(vector<int> &nums, int i, vector<int> &dp){
        
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=0) return dp[i];
        
        int currSum = nums[i];
        int currVal = nums[i];
        int index = i+1;
        
        while(index < nums.size() && currVal == nums[index]){
            currSum += nums[index];
            index++;
        }
        
        while(index < nums.size() && nums[index] == currVal+1){
            index++;
        }
        
        
        int ans1 = helper(nums,i+1, dp);
        int ans2 = currSum + helper(nums, index, dp);
        return dp[i] = max(ans1, ans2);
        
        
    }
    
//     void helper(vector<int> &nums, unordered_set<int> &st, int ans, int i){
        
//         if(i==nums.size()){
//             cout<<ans<<endl;
//             max_ans = max(max_ans, ans);
//             return;
//         }
//         // if(st.find(nums[i])==st.end()) return;
        
// //         delete ith nums
//         ans += nums[i];
        
//         if(st.find(nums[i]+1)!=st.end()) st.erase(nums[i]+1);
//         if(st.find(nums[i]-1)!=st.end()) st.erase(nums[i]-1);
//         helper(nums, st, ans, i+1);
        
//         ans -= nums[i];
//         st.insert(nums[i]+1);
//         st.insert(nums[i]-1);
        
//         helper(nums, st, ans, i+1);
        
        
//     }
};