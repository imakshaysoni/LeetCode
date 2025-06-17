class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //

        return binarySearch(nums1, nums2);


    }


    double binarySearch(vector<int> &nums1, vector<int> &nums2){


        // for even
        if(nums1.size() > nums2.size()) return binarySearch(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        int k = (n1+n2+1)/2;
        int maxPos = min(k, n1);
        int minPos = max(0, k-n2);
        while(minPos <= maxPos){
            int mid = (minPos + maxPos )/2;
            int mid2 = k - mid;
            int l1 = INT_MIN, r1=INT_MAX;
            int l2 = INT_MIN, r2=INT_MAX;
            if(mid-1 >=0 ) l1 = nums1[mid-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];

            if(mid < n1 ) r1 = nums1[mid];
            if(mid2 < n2 ) r2 = nums2[mid2];
            if(l1 <= r2 and l2 <= r1){
                if(n%2==0)  return (max(l1, l2) + min(r1, r2) ) / 2.0;
                return max(l1, l2);
            }
            else{
                if(l1 > r2) maxPos = mid-1;
                else minPos = mid+1;
            }
        }

    return 0;
    }

    double intitive_sol(vector<int> &nums1, vector<int> &nums2){
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