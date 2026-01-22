class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return binarySearch(nums, 0, nums.size()-1, target);
    }

    int binarySearch(vector<int>&nums, int low, int high, int target){

        if(low > high) return -1; // not found
        
        int mid = low +(high-low)/2;

        if(nums[mid]==target) return mid;
        // if(nums[low]==target) return low;
        // if(nums[high]==target) return high;

        if(nums[low] <= nums[mid]){
            //left half is sorted
            if(target >= nums[low] and target <= nums[mid]){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target >= nums[mid] and target <= nums[high]){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return binarySearch(nums, low, high, target);
    }
};
