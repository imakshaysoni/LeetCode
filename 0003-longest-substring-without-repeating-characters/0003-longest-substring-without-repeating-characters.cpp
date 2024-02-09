class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        
//         Brute Force
        int maxi = INT_MIN;
        int count=0;
        unordered_set<char> st;
        for(int i=0;i<n;i++){
            count = 0;
            st.clear();
            for(int j=i;j<n;j++){
                char ch = s[j];
                if(st.find(ch)!=st.end()){
                    maxi = max(maxi, count);
                    break;
                }
                st.insert(ch);
                count++;
            }
            maxi = max(maxi, count);
        }
        return max(maxi, count);
        
        
//         Optimal Approch
        // return slidingWindow(s, n);
        
    }
    int slidingWindow(string s, int n){
        
        int maxi=INT_MIN;
        int left=0;
        int right = 0;
        unordered_map<char,int> mapp;
        
        while(right<n){
            char ch = s[right];
            if(mapp.find(ch) != mapp.end() && mapp[ch]>=left){
                left = mapp[ch] + 1;
                mapp[ch] = right;
                right++;
            }
            else{
                maxi = max(maxi, right-left+1);
                mapp[ch]=right;
                right++;
            }
            
        }
        return maxi;
    }
};