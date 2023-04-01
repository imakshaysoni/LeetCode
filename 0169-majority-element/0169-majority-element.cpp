class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        
        
//          int major=num[0];
//          int count = 1;
//         for(int i=1; i<num.size();i++){
//             if(count==0){
//                 count++;
//                 major=num[i];
//             }else if(major==num[i]){
//                 count++;
//             }else count--;
            
//         }
//         return major;
        
        
        int count=1;
        int max = nums[0];
        for(int i=1; i<nums.size();i++){
            if(count==0){
                count++;
                max=nums[i];
            }
            else if(max==nums[i]){
                count++;
            }
            else{count--;}
            
        }
        return max;
        
        
        // int n=nums.size()/2;
        // sort(nums.begin(),nums.end());
        // int count=1;
        // for(int i=0;i<nums.size()-1;i++){
        //     cout<<nums[i]<<endl;
        //     if(nums[i]==nums[i+1]){
        //         count++;
        //     }
        //     cout<<count<<endl;
        //     if(count>n){
        //         return nums[i];
        //     }
        // }
        // return nums[0];
    }
};