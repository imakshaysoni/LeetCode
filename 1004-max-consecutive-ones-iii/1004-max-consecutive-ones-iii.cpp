class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        int ans = 0;
        int left=0;
        int right=0;
        int zerosCount=0;
        while(right<n){
            if(nums[right]==0) zerosCount++;
            
            while(zerosCount>k){
                if(nums[left]==0) zerosCount--;
                left++;
            }
            
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
        
    }
};