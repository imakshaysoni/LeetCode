class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
     int n=nums.size();
    int i=n-1;
    while(i>0){
        if(nums[i-1] < nums[i])break;
        i--;
    }
    int k=n-1;
        --i;
    while(k>i and i>=0){
     if(nums[k] > nums[i]){
         int temp=nums[k];
         nums[k]=nums[i];
         nums[i]=temp;
         break;
     }
        k--;
    }
    int j=i+1;
    k=n-1;
    while(j<k){
        int x = nums[j];
        nums[j]=nums[k];
        nums[k]=x;
        j++;k--;
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
    

    