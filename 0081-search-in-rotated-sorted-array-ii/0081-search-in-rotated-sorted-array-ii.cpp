class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        return solve(nums, target, 0, nums.size()-1);
    }

    int solve(vector<int> &nums, int target, int left, int right){

        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target or nums[left]==target or nums[right]==target) return true;
            if(nums[mid]==nums[left] and nums[mid]==nums[right]){
                left++; right--; continue;
            }
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] and target<nums[mid]){
                    right = mid-1;
                }
                else left = mid+1;
            }
            else{
                if(target > nums[mid] and target <= nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }

        }
        return false;


    }
};