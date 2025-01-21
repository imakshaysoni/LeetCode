class Solution {
public:
    int characterReplacement(string s, int k) {
        

        int left = 0, right=0;
        int ans = 0;
        int max_f = INT_MIN;
        unordered_map<int,int> mapp;
        while(right<s.size()){
            char ch = s[right];
            mapp[ch]++;
            max_f = max(max_f, mapp[ch]);

            while( (right-left+1) - max_f > k and left < s.size()){
                char c1 = s[left];
                mapp[c1]--;
                max_f = max(max_f, mapp[c1]);
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};