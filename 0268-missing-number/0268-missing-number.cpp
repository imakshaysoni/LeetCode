class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Brute Force
        int n = nums.size();
        
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=i) return i;
        // }
        // return n;


        // Optimal
        int expected_sum = n *(n+1)/2;
        int actual_sum = 0;
        for(auto it: nums) actual_sum+=it;
        return expected_sum-actual_sum;
    }
};