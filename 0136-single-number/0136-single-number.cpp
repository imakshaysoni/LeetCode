class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<n){
            if(nums[i]==nums[j]){
                i=i+2;
                j=j+2;
            }
            else{
                return nums[i];
            }            
        }
        return nums[i];
    }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    //     //better solution
    //     unordered_map<int,int> m;
    //     for(auto it: nums){
    //         m[it]++;
    //     }
    //     for(auto it: m){
    //         if(it.second==1) return it.first;
    //     }
    //     return 0;
    // }
};