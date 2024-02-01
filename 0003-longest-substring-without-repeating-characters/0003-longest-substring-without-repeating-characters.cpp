class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        unordered_set<char> st;
        
        int left= 0;
        int right=0;
        int maxi = INT_MIN;
        while(left<=right and right<n){
            
            if(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            else{
                maxi = max(maxi, (right-left+1));
                st.insert(s[right]);
                right++;
            }           
            
        }
               return maxi;
        
    }
};