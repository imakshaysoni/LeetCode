class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    
        int n=nums.size();
       vector<int> v(n);
        int l=0;
        int r=n-1;
        for(int k=r;k>=0;k--){
            if(abs(nums[l]) > abs(nums[r])) v[k]=nums[l]*nums[l++];
            else v[k]=nums[r]*nums[r--];
        }
        return v;
        
        
//         for(int i=0;i<nums.size();i++){
//             nums[i]*=nums[i];
//         }
//         sort(nums.begin(),nums.end());
//         # nlog(n)
        
//         return nums;
    }
};