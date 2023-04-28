class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size()<2) return false;
        int len=0;
        int sum=0;
        unordered_map<int,int> map;
        map[0]=-1;
//         return helper(nums,k);
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            if(sum<0) sum+=k;
            if(map.find(sum)!=map.end()){
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