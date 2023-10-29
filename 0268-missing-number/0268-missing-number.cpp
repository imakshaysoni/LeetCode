class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
//         [0,1,3,4]
        if(nums[0]!=0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                return i;
            }
        }
        return n;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         //Brute Force
//         // sort(nums.begin(),nums.end());
//         // for(int i=0;i<nums.size();i++){
//         //     if(nums[i]!=i){
//         //         return nums[i]-1;
//         //     }
//         // }
//         // return n;

//         int expected_sum = (n*(n+1))/2;
//         int sum =0;
//         for(auto it: nums){
//             sum += it;
//         }
//         return expected_sum - sum;
    }
};