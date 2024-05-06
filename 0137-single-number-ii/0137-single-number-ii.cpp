class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        
        for(int i=1;i<nums.size();i+=3){
            if(nums[i-1]!=nums[i]) return nums[i-1];
            // if(nums[i+1]!=nums[i]) return nums[]
        }
        return nums[nums.size()-1];
    }
};