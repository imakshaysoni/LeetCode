class Solution {
public:
    int findMin(vector<int>& nums) {
        
        return solve(nums, 0, nums.size()-1);

    }

    int solve(vector<int> &nums, int left, int right){
        int mini = INT_MAX;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[left]<=nums[mid]){
                // left sorted array
                mini = min(mini,nums[left]);
                left = mid+1;
            }
            else{
                mini = min(mini,nums[mid]);
                right = mid-1;
            }
        }
        return mini;
    }
};