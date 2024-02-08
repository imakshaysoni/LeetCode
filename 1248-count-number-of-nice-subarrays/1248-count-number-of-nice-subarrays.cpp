class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atMostKoddNumber(nums, k) - atMostKoddNumber(nums, k-1);
        
    }
    
    int atMostKoddNumber(vector<int>&nums, int k){
        
        int n = nums.size();
        int left = 0;
        int right= 0;
        
        int count = 0;
        int oddCounter = 0;
        
        while(right<n){
            if(nums[right]%2==1) oddCounter++;
            
            while(oddCounter>k && left<=right){
                if(nums[left]%2==1) oddCounter--;
                left++;
            }
            
            count += (right-left+1);
            right++;          
            
            
        }
        return count;        
        
        
    }
};