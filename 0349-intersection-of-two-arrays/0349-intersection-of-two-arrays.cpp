class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int i=0, j=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m=nums1.size();
        int n=nums2.size();
        vector<int> result;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]) i++;
            else if(nums2[j]<nums1[i]) j++;
            else{
                if(result.size()==0 || result.back()!=nums1[i]){
                    result.push_back(nums1[i]);
                }                
                i++;
                j++;
            }
        }
        return result;
        
    }
};