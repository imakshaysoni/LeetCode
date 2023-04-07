class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        
        if(nums.size() < 4) return v;
        
        
        int n=nums.size();
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                int left = j+1;
                int right = n-1;
                long long t = (long long)target - (long long)nums[i] - (long long)nums[j];
                
                while(left<right){
                    int sum2 = nums[left]+nums[right];
                    if(sum2 == t){
                        v.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1])left++;
                        while(right>left && nums[right]==nums[right-1])right--;
                        left++;
                        right--;
                        // break;
                    }
                    else if (sum2 > t)right--;
                    else left++;                 
                    
                }              
                
            while(j<=n-3 && nums[j]==nums[j+1])j++;
            }
            while(i<=n-4 && nums[i]==nums[i+1])i++;
        }
        return v;
        
         
        
    }
};