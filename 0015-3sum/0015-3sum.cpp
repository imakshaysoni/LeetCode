class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int target = -nums[i];
            int s=i+1;
            int e=n-1;
            while(s<e){
                
                if(nums[s]+nums[e] == target){
                    v.push_back({nums[i],nums[s],nums[e]});
                    while(s<e && nums[s]==nums[s+1])s++;
                while(e > s&&nums[e]==nums[e-1])e--;
                    s++;e--;
                }
                else if (nums[s]+nums[e]>target)e--;
                else s++;
            }
            while(i<n-1 && nums[i]==nums[i+1])i++;
            
        }
        return v;
//          Brute Force TLE
        // sort(nums.begin(),nums.end());
        // vector<vector<int>> v;
        // int n=nums.size();
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 v.push_back({nums[i],nums[j],nums[k]});   
        //             }
        //             while(k<n-1 && nums[k]==nums[k+1])k++;
        //         }
        //         while(j<n-1 && nums[j]==nums[j+1])j++;
        //     }
        //     while(i<n-2 && nums[i]==nums[i+1])i++;
        // }
        // return v;
    }
};