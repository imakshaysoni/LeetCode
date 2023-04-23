class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        if(k > nums.size()) return false;
        int sum =0;
        for(auto x: nums) sum+=x;
        
        if(sum%k!=0 || k > sum)  return false;
        int target = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> buckets(k,0);
        return helper(nums, buckets, target, 0, k);
        
        
    }
    
    bool helper(vector<int> &nums, vector<int> &buckets, int target, int index, int k){
        
        if(index == nums.size()){
            for(auto sum: buckets){
                if(sum!=target) return false;
            }
            return true;
        }
        
        for(int i=0; i< k ; i++){
            
        
            if(buckets[i]+nums[index] > target) continue;
            
            buckets[i] +=nums[index];
            if(helper(nums, buckets, target, index+1, k)) return true;
            buckets[i]-=nums[index];            
            if(buckets[i]==0) break;
        }
        return false;
        
    }
};