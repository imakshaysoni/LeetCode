class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
//         Alternate Solution without extra space
        if(n==0){
            return;
        }
        if(m==0){
            nums1=nums2;
            return;
        }
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 and j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0){
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }

//         vector<int> v;
//         int i=0;
//         int j=0;
//         while(i<m and j<n){
//             if(nums1[i]<=nums2[j]){
//                 v.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 v.push_back(nums2[j]);
//                 j++;
//             }
//         }
//             while(i<m){
//                 v.push_back(nums1[i]);
//                 i++;
//             }
//             while(j<n){
//                 v.push_back(nums2[j]);
//                 j++;
//             }
        
//         for(int i=0;i<nums1.size();i++){
//             cout<<v[i];
//         }
//         cout<<endl;
//         for(int k=0;k<nums1.size();k++){
//             nums1[k]=v[k];
//         }
        
    }
};