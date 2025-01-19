class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        return solve(nums, k);
    }
    int solve(vector<int> &nums, int k){
        int left=0, right = 0;
        int zerosCount = 0;
        int ans = 0;
        while(right<nums.size()){
            if(nums[right]==0) zerosCount++;

            while(zerosCount>k){
                if(nums[left]==0) zerosCount--;
                left++;
            }
            ans = max(ans, right - left +1);
            right++;
        }
        return ans;


    }
};