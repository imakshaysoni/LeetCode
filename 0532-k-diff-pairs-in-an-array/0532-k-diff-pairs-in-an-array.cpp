class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2) return 0;
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j = i+1;
            while(j<nums.size()){
                int diff = abs(nums[j]-nums[i]);
                if(diff == k){
                    count++; break;}
                else if (diff > k) break;
                j++;
            }            
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
            
        }
        
        return count;
    }
};