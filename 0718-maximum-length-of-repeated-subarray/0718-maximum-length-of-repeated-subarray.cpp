class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
      //         Recursive
        // int ans=0;
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, -1));
        int max_ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int ans=0;
                    ans += helper(nums1,nums2,i,j, dp);
                    max_ans = max(ans, max_ans);
                    dp[i][j] = max_ans;
                }
            }
        }
        
        return max_ans;
    }
    
    
    int helper(vector<int> &nums1, vector<int> &nums2, int index1, int index2, vector<vector<int>> &dp){
        
        if(index1>=nums1.size() || index2>=nums2.size()){
            return 0;
        }
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        
        if(nums1[index1]==nums2[index2]){
            return dp[index1][index2] = 1 + helper(nums1,nums2, index1+1, index2+1, dp);
        }
        return dp[index1][index2]=0;      
    }
    
        // vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, 0));
        // int ans=0;
        // for(int i=1;i<=nums1.size();i++){
        //     for(int j=1; j<=nums2.size();j++){
        //         if(nums1[i-1]!=nums2[j-1]){
        //             dp[i][j]=0;
        //         }
        //         else{
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //         }
        //         ans = max(ans, dp[i][j]);                
        //     }
        // }
        // return ans;
        
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int cnt = 0;
//         int largest = INT_MIN;
//         for(int i=0;i<n1;i++){
//             cnt=0;
//             for(int j=i, ptr=0;j<n1 && ptr<n2;j++,ptr++){
//                 if(nums1[j]==nums2[ptr]) cnt++;
//                 else cnt=0;
//                 largest = max(largest,cnt);
//             }
            
//         }
//         cnt = 0;
//         for(int i=0;i<n2;i++){
//             cnt=0;
//             for(int j=i, ptr=0;j<n2 && ptr<n1; j++, ptr++){
//                 if(nums2[j]==nums1[ptr]) cnt++;
//                 else cnt=0;
//                 largest = max(largest,cnt);
//             }
//         }
        
//         return largest;
        
    

};
