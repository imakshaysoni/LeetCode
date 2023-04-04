class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> m;
        
        
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)ans++;
            if (m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            m[sum]++;
            
        }
        return ans;
        
        // int sum=0,ans=0;
        // m[sum]=1;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     int find = sum-k;
        //     if(m.find(find)!=m.end()){
        //         ans+=m[find];
        //     }
        //     m[sum]++;
        // }
        // return ans;
        
        
        
        // Brute Force Approch TLE;
        // int count=0;
        // int n = nums.size();
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==k)count++;
        //     sum=nums[i];          
        // for(int j=i+1;j<n;j++){
        //     sum+=nums[j];
        //     if(sum==k){
        //         count++;
        //     }
        // }   
        // }
        // return count;
        
    }
};