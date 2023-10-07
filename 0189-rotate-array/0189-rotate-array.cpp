class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(),nums.end());
        
        
//         Brute Force: O(n-d), SC: O(d)
//         vector<int> temp;
//         for(int i=n-k;i<n;i++){
//             temp.push_back(nums[i]);
//         }
//         int j=0;
//         for(int i=n-k-1;i>=0;i--){
//             nums[n-1-j]=nums[i];
//             j++;
//         }
        
//         for(int i=0;i<k;i++){
//             nums[i]=temp[i];
//         }
    }
};