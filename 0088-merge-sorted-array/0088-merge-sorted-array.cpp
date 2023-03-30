class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     

        vector<int> v;
        int i=0;
        int j=0;
        while(i<m and j<n){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
            while(i<m){
                v.push_back(nums1[i]);
                i++;
            }
            while(j<n){
                v.push_back(nums2[j]);
                j++;
            }
        
        for(int i=0;i<nums1.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        for(int k=0;k<nums1.size();k++){
            nums1[k]=v[k];
        }
        
    }
};