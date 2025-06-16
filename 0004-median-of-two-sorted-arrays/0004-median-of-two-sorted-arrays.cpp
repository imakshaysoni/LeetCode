class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(auto it: nums2) nums1.push_back(it);
        sort(nums1.begin(), nums1.end());
        int mid = nums1.size()/2;
        if(nums1.size()==1) return nums1[0];
        // cout<<nums1[mid]<< " "<<nums1[mid-1];
        if(nums1.size()%2==0) return (nums1[mid] + nums1[mid-1] )/2.0;
        return nums1[mid];

        
    }
};