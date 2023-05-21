class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            long long minVal = nums[i];
            long long maxVal = nums[i];
            
            for (int j = i; j < n; j++) {
                minVal = min(minVal, (long long)nums[j]);
                maxVal = max(maxVal, (long long)nums[j]);
                sum += maxVal - minVal;
            }
        }
        
        return sum;
    }
};