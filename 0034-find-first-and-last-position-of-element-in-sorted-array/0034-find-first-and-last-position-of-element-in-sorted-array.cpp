class Solution {
public:
    int minIdx=INT_MAX, maxIdx=INT_MIN;
    void binarySearch(vector<int> & nums, int target, int left, int right, bool getMax){
        int mid = left + (right-left)/2;
        if(left>right) return;
        if(nums[mid]==target) {
            if(getMax){
                maxIdx = max(maxIdx, mid);
                binarySearch(nums, target, mid+1, right, getMax);
            }   
            else{
                minIdx = min(minIdx, mid);            
                binarySearch(nums, target, left, mid-1, getMax);
            }
        }
        if(target > nums[mid]){
            left=mid+1;
        }
        else{
            right = mid-1;
        }
        binarySearch(nums, target, left, right, getMax);
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int left = 0;
        int right = n-1;
        // int minIdx = INT_MAX, maxIdx=INT_MIN;

        binarySearch(nums, target, left, right, false);
        if(minIdx==INT_MAX) return {-1, -1};
        binarySearch(nums, target, left, right, true);

        if(minIdx==INT_MAX) return {-1, -1};
        return {minIdx, maxIdx};

    }
};