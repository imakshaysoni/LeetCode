class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        
 int i = nums.size() - 1, k = i;
    while (i > 0 && nums[i-1] >= nums[i])
        i--;
    for (int j=i; j<k; j++, k--)
        swap(nums[j], nums[k]);
    if (i > 0) {
        k = i--;
        while (nums[k] <= nums[i])
            k++;
        swap(nums[i], nums[k]);
    }
    
        // int n=nums.size();
        // int i=n-1;
        // int k;
        // int min=nums[n-1];
        // while(i>0){
        //     if(nums[i-1] >= nums[i]){
        //         i--;
        //     }
        //     else{
        //         int temp=nums[i-1];
        //         nums[i-1]=nums[i];
        //         nums[i]=temp;
        //         sort(nums.begin()+i,nums.end());
        //         break;
        //     }
        //     i--;
        // }
        // if(i==0){sort(nums.begin(),nums.end());}
        
    }
};



// 1 6 3 4 2
    

    