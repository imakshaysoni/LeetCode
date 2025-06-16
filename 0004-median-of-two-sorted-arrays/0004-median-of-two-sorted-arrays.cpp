class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        int first=0;
        int second = 0;

        while(first < nums1.size() and second <nums2.size()){
            if(nums1[first] < nums2[second] ){
                res.push_back(nums1[first]);
                first++;
            }
            else{
                res.push_back(nums2[second]);
                second++;
            }
        }
        while(first < nums1.size()){
            res.push_back(nums1[first]);
            first++;
        }
        while(second < nums2.size()){
            res.push_back(nums2[second]);
            second++;
        }

        int n = res.size();
        int mid = n/2;
        if(n%2==0) return (res[mid] + res[mid-1] )/2.0;
        return res[mid];


        

        
    }
};