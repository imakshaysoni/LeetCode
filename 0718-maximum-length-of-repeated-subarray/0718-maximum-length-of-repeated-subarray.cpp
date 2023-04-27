// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
     
//         vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, 0));
//         int ans=0;
//         for(int i=1;i<=nums1.size();i++){
//             for(int j=1; j<=nums2.size();j++){
//                 if(nums1[i-1]!=nums2[j-1]){
//                     dp[i][j]=0;
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 }
//                 ans = max(ans, dp[i][j]);                
//             }
//         }
//         return ans;
        
//     }
    
    
// int findLength(vector<int>& nums1, vector<int>& nums2) {
//     if (nums1.size() < nums2.size())
//         swap(nums1, nums2);

//     const int n2 = nums2.size();
//     vector<int> indices2[101];
//     for (int i = 0; i < n2; ++i)
//         indices2[nums2[i]].emplace_back(i);

//     vector<int> dp0(n2 + 1), dp1(n2 + 1);
//     vector<int>& prev = dp0;
//     vector<int>& curr = dp1;
//     int answer = 0, count = sizeof(int) * prev.size();
//     for (int num : nums1) {
//         memset(prev.data(), 0, count);
//         swap(prev, curr);
//         for (int i : indices2[num])
//             answer = max(answer, curr[i + 1] = prev[i] + 1);
//     }
//     return answer;
// }
// };


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        //moving num2 on num1
        
        int ptr2 = 0;
        
        int cnt = 0;
        
        int largest  = INT_MIN;
        
        for(int i=0;i<n1;i++)
        {
            cnt = 0;
            for(int j=i,ptr2=0;j<n1 && ptr2<n2;j++,ptr2++)
            {
                if(nums1[j]==nums2[ptr2])
                {
                    cnt++;
                    
                }
                else
                {
                    cnt = 0;
                }
                largest = max(largest,cnt);
            }
        }
        
        //moving num1 on num2
        ptr2 = 0;
        cnt = 0;
        for(int i=0;i<n2;i++)
        {
            cnt = 0;
            for(int j=i,ptr2=0;j<n2 && ptr2<n1;j++,ptr2++)
            {
                if(nums2[j]==nums1[ptr2])
                {
                    cnt++;
                }
                else
                {
                    cnt = 0;
                }
                largest = max(largest,cnt);
            }
        }
        
        return largest;
        
    }
};