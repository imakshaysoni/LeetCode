class Solution {
public:
    void sortColors(vector<int>& nums) {

            int zerosCount = 0;
            int onesCount = 0;
            int twosCount = 0;

            int n = nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]==0) zerosCount++;
                else if(nums[i]==1) onesCount++;
                else if(nums[i]==2) twosCount++;
            }

            int i=0;
            while(zerosCount>0){
                nums[i]=0;
                i++;
                zerosCount--;
            }
            while(onesCount>0){
                nums[i]=1;
                i++;
                onesCount--;
            }
            while(twosCount>0){
                nums[i]=2;
                i++;
                twosCount--;
            }
            return;

    }
};