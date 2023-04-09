class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> arr;
        // nums.push_back(0);
        for(int x : nums){
            int idx = abs(x);
            if(nums[idx-1]<=0)arr.push_back(idx);
            else nums[idx-1] = -nums[idx-1];
        }
        
        return arr;
        
        
        
    }
};