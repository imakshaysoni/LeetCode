class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int n = s.size();
        int ans = 0;

        unordered_map<char, int> mapp;
        while(right<n){
            char ch = s[right];

            if(mapp.find(ch)!=mapp.end() and mapp[ch] >= left ){
                left = mapp[ch]+1;
            }
            mapp[ch] = right;
            ans = max(ans, right - left + 1);
            right++;

        }
        return ans;
        
    }
};