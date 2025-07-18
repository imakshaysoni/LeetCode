class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int actual_sum = 0;
        for(int i=0;i<nums.size();i++){
            actual_sum += nums[i];
        }

        int n = nums.size();
        int expected_sum = n*(n+1)/2;

        return expected_sum - actual_sum;
        
    }
};