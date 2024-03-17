class Solution {
public:
    string twoPointer(string s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
        
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
                string even = twoPointer(s, i, i+1);
                string odd = twoPointer(s, i, i);
                
                if(even.size()>ans.size()){
                    ans=even;
                }
                if(odd.size()>ans.size()){
                    ans = odd;
                }
        }
        
        return ans;
        
    }
};