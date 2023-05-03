class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
//         Global for both
        int n = nums.size();
        int ans = 0;
     
//         Iterrative bottom Up DP
        unordered_map<int, int> dp[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];
                int cnt = 1;
                
                if(dp[j].count(diff)) cnt = dp[j][diff];
                dp[i][diff]= 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;

        
        
        
//         Recursive Giving tLE, Top Down DP is also giving TLE
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, 2 + solve(j,nums[j]-nums[i],nums));
            }
        }
        
        return ans;
        
    }
    
    int solve(int index, int diff, vector<int> &nums){
        
        int ans = 0;
        for(int j=index+1;j<nums.size();j++){
            if(nums[j]-nums[index]==diff){
                ans = max(ans, 1 + solve(j, diff, nums));
                // dp[diff][index] = ans;
            }
        }
        
        return ans;
    }
};