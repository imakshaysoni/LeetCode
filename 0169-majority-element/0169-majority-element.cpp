class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj = nums[0];
        int n = nums.size();
        set<int> st;
        int majCount=0;
        int count;
        for(int i=0;i<n;i++){
            // if(st.find(maj)!=st.end()) continue;
            count=1;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]) count++;
            }
            if(majCount<count){
                maj = nums[i];
                majCount = count;
            }
            // st.insert(maj);
        }
        return maj;
    }
};