class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minn_prod = 1;
        int ans = INT_MIN;
        int maxx_prod = 1;
        for(int i=0;i<nums.size();i++){            
            if(nums[i]<0) swap(minn_prod, maxx_prod);
            
            minn_prod = min(nums[i], minn_prod*nums[i]);
            maxx_prod = max(nums[i], maxx_prod*nums[i]);
            ans=max(ans,maxx_prod);
            
        }
        return ans;
        
    }
};