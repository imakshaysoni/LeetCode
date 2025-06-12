class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int maxTime = 0;
        int minTime = 0;
        for(auto it: nums){
            maxTime += it;
            minTime = max(minTime, it);
        }
        // return linearSearch(nums, k, minTime, maxTime);        
        return binarySerach(nums, k, minTime, maxTime);
    }

    int binarySerach(vector<int> &arr, int k, int start, int end){
        int ans = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(isPossible(arr, k, mid)){
                ans = min(ans, mid);
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
        
        
    }
    
    bool isPossible(vector<int> &arr, int k, int mid){
        
        int i=0;
        int painter = 1;
        int paint=0;
        while(i<arr.size()){
            
            if(paint + arr[i] <= mid){
                paint += arr[i];
                i++;
            } 
            else{
                painter++;
                paint = 0;
            }
            
        }
        
        if(painter<=k){
            return true;
        }
        return false;
    }
    
    int linearSearch(vector<int>&arr, int k, int minTime, int maxTime){
        int ans = INT_MAX;
        for(int t=minTime;t<=maxTime;t++){
            
            if(isPossible(arr, k, t)){
                ans= min(ans, t);
            }
            
        }
        return ans;
    }
};