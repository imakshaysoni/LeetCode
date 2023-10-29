class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
            }
        }
        while(i<n){
            nums[i]=0;
            i++;
        }
        
        return;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=0){
        //         // nums[j]=nums[i];
        //         swap(nums[i], nums[j]);
        //         j++;
        //     }
        // }
        // // while(j<n){
        // //     nums[j]=0;
        // //     j++;
        // // }
    }
};