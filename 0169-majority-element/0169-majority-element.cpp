class Solution {
public:
    int majorityElement(vector<int>& nums) {


        // RBute force
        int n = nums.size();
        for(int i=0;i<n;i++){
            int number= nums[i];
            int count = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j]==number) count++;
            }
            if(count>n/2) return number;
        }
        return -1;
        
    }
};