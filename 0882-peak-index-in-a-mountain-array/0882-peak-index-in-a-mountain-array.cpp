class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        return solve(nums, 1, nums.size()-2);
    }

    int solve(vector<int> &arr, int left, int right){
        if(arr[0] > arr[1]) return 0;
        if(arr[arr.size()-1] > arr[arr.size()-2]) return arr.size()-1;
            
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid-1] > arr[mid]){
                right = mid-1;
            }
            else if(arr[mid+1] > arr[mid]){
                left = mid+1;
            }
            else return mid;
           
        }
        return -1;
    }
};