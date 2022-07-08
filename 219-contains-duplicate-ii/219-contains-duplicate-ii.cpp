class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
           unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])) { return true; }
            s.insert(nums[i]);
            if(s.size() > k){
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};
    
    
//      if(k<1){ return false; }
//         int i=0,j=1;
//         while(j<nums.size()){
//             if(nums[i]==nums[j] and abs(i-j) <= k ){
//                 return true;
//             }
//             else if(abs(i-j) > k){
//                 i++;
//             }
//             else{
//                 j++;
//             }            
//         }
//         return false;
        
//     }