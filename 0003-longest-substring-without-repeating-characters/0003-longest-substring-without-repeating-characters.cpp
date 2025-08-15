class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int n = s.size();
        // unordered_map<char,int> mapp;
        set<char> st;
        int ans = 0;

        while(right < n){
            char ch = s[right];
            while(st.find(ch)!=st.end()){
                char c = s[left];
                st.erase(c);
                left++;
            }
            ans = max(ans, right-left+1);
            st.insert(ch);
            right++;

        }
        return ans;
        
    }
};