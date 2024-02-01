class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int n = s.size();
        int count=0;
        int maxi = INT_MIN;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            int count=1;
            st.insert(s[i]);
            for(int j=i+1;j<n;j++){
                if(st.find(s[j])!=st.end()){
                    maxi = max(maxi, count);
                    break;
                    }
                else{
                    count++;
                    st.insert(s[j]);
                }
            }
            maxi = max(maxi, count);
            st.clear();
            count = 0;
        }
        
        return maxi;
    }
};