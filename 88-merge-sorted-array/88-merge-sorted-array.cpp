class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m==0){ 
        for(int i=0;i<n;i++){
            nums1[i] = nums2[i];
        }
        
        }
        if(n==0) { return; }
         
        int size = m>n?m:n;
        vector<int> result;
        int i=0,j=0;
        while(i<m and j<n ){
            if(nums1[i]<nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
            else{
                result.push_back(nums2[j]);
                j++;
            }
            
        }
        
        if(i!=m) { 
        
        while(i<m){ result.push_back(nums1[i]); i++; }
        
        };
        
        if(j!=n){
            while(j<n){ result.push_back(nums2[j]); j++; }
        }
        for(int i=0;i<result.size();i++){
            nums1[i]=result[i];
        }
    }
};