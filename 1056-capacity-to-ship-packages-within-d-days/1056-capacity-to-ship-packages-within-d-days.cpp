class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxTime = 0;
        int minTime = 0;
        for(auto it: weights){
            maxTime += it;
            minTime = max(minTime, it);
        }
        // return linearSearch(nums, k, minTime, maxTime);        
        return binarySerach(weights, days, minTime, maxTime);
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
};