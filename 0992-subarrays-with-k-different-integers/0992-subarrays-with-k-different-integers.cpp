class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        cout<<"First: "<<atmostK(nums, k);
        cout<<"SEcond: "<<atmostK(nums, k-1);
        return  atmostK(nums, k) - atmostK(nums, k-1);
    }
    
    int atmostK(vector<int>&nums, int k){
        
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int, int> mapp;
        
        while(right<nums.size()){
            
            mapp[nums[right]]++;
            
            while(mapp.size()>k){
                mapp[nums[left]]--;
                if(mapp[nums[left]]==0){
                    mapp.erase(nums[left]);
                }
                left++;
            }
            
            count += right-left+1;
            right++;
            
        }
        return count;
        
        
    }
};