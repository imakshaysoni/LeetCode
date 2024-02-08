class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubArraySumAtMostGoal(nums, goal) - countSubArraySumAtMostGoal(nums, goal-1);
    }
    
    int countSubArraySumAtMostGoal(vector<int>&nums, int goal){
        
        int left=0;
        int right = 0;
        int sum=0;
        int count= 0;
        
        while(right<nums.size()){
            
            sum += nums[right];
            
            while(sum>goal and left<=right){
                sum -= nums[left];
                left++;
            }
            
            count += (right-left+1);
            right++;
            
        }
        
        return count;
        
    }
};