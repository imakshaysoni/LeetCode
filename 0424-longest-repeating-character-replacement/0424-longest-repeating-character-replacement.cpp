class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int topFreq = 0;
        int left=0;
        int right= 0;
        unordered_map<char, int> mapp;
        int maxi = 0;
        int n = s.size();
        
        while(right<n){
            mapp[s[right]]++;
            topFreq = max(mapp[s[right]], topFreq);
            
            if(right-left+1 - topFreq > k){
                mapp[s[left]]--;
                left++;                
            }
            if(right-left+1 -topFreq <= k){
                maxi = max(maxi, right-left+1);    
            }
            right++;
            
            
        }
        return maxi;
        
        
    }
};