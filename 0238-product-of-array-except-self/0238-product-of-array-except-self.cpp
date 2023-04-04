class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int mul=1;
        vector<int> r;
        r.push_back(1);
        int l_sum=1;
        int n = nums.size()-1;
        for(int i=n;i>0;i--){
            mul*=nums[i];
            r.push_back(mul);
        }
        for(auto a: r)cout<<a<<" ";
        for(int i=0;i<=n;i++){
            int temp=nums[i];
            nums[i]=r[n-i]*l_sum;
            l_sum*=temp;                        
        }
        
        return nums;      
        
    }
};