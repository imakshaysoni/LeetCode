class Solution {
public:
    void nextPermutation(vector<int>& num) {
   
        int n=num.size();
    if(n<2)
        return;
    int index=n-1;        
    while(index>0){
        if(num[index-1]<num[index])
            break;
        index--;
    }
    if(index==0){
        reverse(num.begin(),num.end());
        return;
    }
    else{
        int val=num[index-1];
        int j=n-1;
        while(j>=index){
            if(num[j]>val)
                break;
            j--;
        }
        swap(num[j],num[index-1]);
        reverse(num.begin()+index,num.end());
        return;
        
    }
        
        
        
//         StriverSolution & Intution
//      int n=nums.size();
//     int i=n-1;
//     while(i>0){
//         if(nums[i-1] < nums[i])break;
//         i--;
//     }
//     int k=n-1;
//     --i;
//     while(k>i and i>=0){
//      if(nums[k] > nums[i]){
//          swap(nums[k],nums[i]);
//          break;
//      }
//         k--;
//     }
    
//     int j=i+1;
//     k=n-1;
//     while(j<k){
//         swap(nums[j],nums[k]);
//         j++;k--;
//     }
        
        
        
        
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
    

    