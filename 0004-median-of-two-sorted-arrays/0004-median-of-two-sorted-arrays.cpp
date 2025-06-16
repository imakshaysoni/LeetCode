class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int first=0;
        int second = 0;

        int n = nums1.size() + nums2.size();

        int idx1 = n/2;
        int idx2 = n/2-1;
        int val1= -1;
        int val2 = -1;
        int idx= 0;
        while(first < nums1.size() and second <nums2.size()){
            if(nums1[first] < nums2[second] ){
                if(idx==idx1) val1=nums1[first];
                if(idx==idx2) val2=nums1[first];
                first++;
            }
            else{
                if(idx==idx1) val1=nums2[second];
                if(idx==idx2) val2=nums2[second];
                second++;
            }
            idx++;
            if(val1!=-1 and val2!=-1) break;
        }
        while(first < nums1.size() and (val1==-1 or val2==-1)){

            if(idx==idx1) val1=nums1[first];
            if(idx==idx2) val2=nums1[first];
            first++;
            idx++;
        }
        while(second < nums2.size() and  (val1==-1 or val2==-1)){
            if(idx==idx1) val1=nums2[second];
            if(idx==idx2) val2=nums2[second];

            second++;
            idx++;
        }
        cout<<val1<<" "<<val2;
        if(n%2==0) return (val1+val2)/2.0;
        return val1;


        

        
    }
};