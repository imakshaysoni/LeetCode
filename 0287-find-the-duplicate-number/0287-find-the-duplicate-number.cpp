class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();   
        
        for(int i=0;i<n;i++){
            int id = nums[i]%n;
            nums[id]+=n;
        }
        
        int max_val=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>max_val){
                max_val=nums[i];
                ans=i;
            }
        }
        
        return ans;
        
//         Fast & slow pointer
        // if(n<=1) return nums[0];
        // if(n==2) return nums[0];
        // int slow = 0;
        // int fast = 1;
        // while(nums[slow]!=nums[fast]){
        //     slow++;
        //     fast+=2;
        //     if(slow>=n) slow=1;
        //     if(fast>=n) fast=n-fast;
        //     if(slow==fast) 
        // }
        // cout<<nums[slow]<<" "<<nums[fast];
        // return nums[slow];
        
        
        // HashMap, Using Extra Space
        // unordered_map<int,int> m;        
        // for(int i=0;i<n;i++){
        //     if(m.find(nums[i])!=m.end()) return nums[i];
        //     else m[nums[i]]=1;
        // }
        
        
        
//        sorting, Modifing Input
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1]) return nums[i];
        // }
        
        
        
        
//         Brute Force TLE
        
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1; j<n;j++){
//                 if(nums[i]==nums[j]) return nums[j];
//             }
//         }
        
        return 0;
    }
};