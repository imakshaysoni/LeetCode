class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=0;i<nums.size()-1;i++){
            cout<<nums[i]<<endl;
            if(nums[i]==nums[i+1]){
                count++;
            }
            cout<<count<<endl;
            if(count>n){
                return nums[i];
            }
        }
        return nums[0];
    }
};