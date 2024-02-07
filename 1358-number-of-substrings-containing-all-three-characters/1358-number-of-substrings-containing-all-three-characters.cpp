class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mapp;       
        
        int left=0;
        int right=0;
        int ans=0;
        int n = s.size();
        while(right<n){
            mapp[s[right]]++;
            
            while(mapp['a']>=1 && mapp['b']>=1 && mapp['c']>=1){
                ans += (n-right);
                mapp[s[left]]--;
                left++;
            }
            right++;
            
        }
        return ans;
    }
};