class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
    //     int n = nums.size();
    // unordered_map<int, int> mp;
    // int sum = 0;
    // mp[0] = -1; // to handle case where subarray sum is multiple of k and starts from index 0
    // for (int i = 0; i < n; i++) {
    //     sum += nums[i];
    //     if (k != 0) sum %= k;
    //     if (mp.count(sum)) {
    //         if (i - mp[sum] > 1) return true;
    //     } else {
    //         mp[sum] = i;
    //     }
    // }
    // return false;
        if(nums.size()<2) return false;
        int len=0;
        int sum=0;
        unordered_map<int,int> map;
        map[0]=-1;
//         return helper(nums,k);
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            if(sum<0) sum+=k;
            if(map.count(sum)){
                if(i - map[sum] > 1) return true;
            }
            else{
                map[sum]=i;
            }
        }
        return false;
    }
    
    
    
//      Brute Force TLE
//     int helper(vector<int> &nums,int k){
        
        
//         for(int i=0;i<nums.size();i++){
//             int sum=nums[i];
//             for(int j=i+1;j<nums.size();j++){
//                 sum+=nums[j];
//                 if(sum%k==0) return true;               
                
//             }
//         }
//         return false;
//     }
        
};