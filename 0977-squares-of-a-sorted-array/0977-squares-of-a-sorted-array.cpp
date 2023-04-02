class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    
        int n=nums.size();
       vector<int> v(n);
        if(n==1){
            v[0]=nums[0]*nums[0];
            return v;
        }
        int i=0;
        int j=n-1;
        int x,y;
        int k =n-1;
        while(i<=j){
            x=nums[i]*nums[i];
            y=nums[j]*nums[j];
            if(x>y){
                v[k]=x;
                i++;
            }
            else{
                v[k]=y;
                j--;
            }
            k--;
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