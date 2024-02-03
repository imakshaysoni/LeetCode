class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left= 0;
        int right= 0;
        int ans = 0;
        while(right<nums.size()){
            if(nums[right]==1){
                ans = max(ans, right-left+1);
                right++;
            }
            else{
                right++;
                left=right;
            }
        }
        return ans;
    }
};