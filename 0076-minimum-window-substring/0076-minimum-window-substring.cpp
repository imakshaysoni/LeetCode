class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> mapp;
        // Count Freq Of each word in t
        for(char ch: t){
            mapp[ch]++;
        }
        int mini=INT_MAX;
        int startIdx = -1;
        int left=0;
        int right=0;
        int n=s.size();
        int cnt = 0;
        while(right<n){
            char ch = s[right];
            if(mapp.find(ch)!=mapp.end() and mapp[ch]>0){
                cnt++;
                mapp[ch]--;
            }
            else{
                if(mapp.find(ch)!=mapp.end()){
                    mapp[ch]--;
                }
                else{
                    mapp[ch]=-1;
                }
            }
            
            while(cnt==t.size()){
                if(right-left+1 < mini){
                    mini = right-left+1;
                    startIdx = left;
                }
                char ch = s[left];
                mapp[ch]++;
                left++;
                if(mapp[ch]>0) cnt--;
            }
            right++;
        }
        if(startIdx==-1) return "";
        return s.substr(startIdx, mini);
    }
};