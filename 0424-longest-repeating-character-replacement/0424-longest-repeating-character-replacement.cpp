class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int right = 0;
        unordered_map<char,int> mapp;
        int topFreq = 0;
        int ans = 0;
        while(right<s.size()){
            char ch = s[right];
            mapp[ch] += 1;
            topFreq = max(topFreq, mapp[ch]);
            
            while(right-left+1 - topFreq > k and left<s.size() ){
                mapp[s[left]]--;
                left++;
            }
            
            if(right-left+1 - topFreq <= k){
                ans = max(ans, right-left+1);
            }
            right++;
            
        }
        return ans;
    }
};