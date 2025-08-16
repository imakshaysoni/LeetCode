class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int right = 0;
        int n = s.size();
        int ans = 0;
        int maxFreq=0;
        unordered_map<char,int> mapp;
        while(right<n){
            char ch = s[right];
            mapp[ch]++;
            maxFreq = max(maxFreq, mapp[ch]);
            while((right-left+1) - maxFreq > k and left<s.size()){
                char c1 = s[left];
                mapp[c1]--;
                if(mapp[c1]==0) mapp.erase(c1);
                maxFreq= max(maxFreq, mapp[c1]);
                left++;
            }
            ans = max(right-left+1, ans);
            right++;
        }
        return ans;
        
    }
};