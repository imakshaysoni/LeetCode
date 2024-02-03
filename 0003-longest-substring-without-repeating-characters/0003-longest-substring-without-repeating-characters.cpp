class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        
        int maxi=INT_MIN;
        int left=0;
        int right = 0;
        unordered_map<char,int> mapp;
        
        while(right<n){
            cout<<"Right: "<<right<<endl;
            char ch = s[right];
            if(mapp.find(ch) != mapp.end() && mapp[ch]>=left){
                left = mapp[ch] + 1;
                mapp[ch] = right;
                right++;
            }
            else{
                if(right==6){
                    cout<<"LeftVal"<<left;
                }
                maxi = max(maxi, right-left+1);
                mapp[ch]=right;
                right++;
            }
            
        }
        return maxi;
    }
};