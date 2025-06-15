class Solution {
public:
    string isPalindrome(string s, int left, int right){
        while(left >=0 and right<s.size() and s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right - left - 1);


    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++){

            //even len string
            string op1 = isPalindrome(s, i, i);

            //odd len string
            string op2 = isPalindrome(s, i, i+1);

            if(op1.size() > ans.size()) ans = op1;
            if(op2.size() > ans.size()) ans = op2;

        }
        return ans;
        
    }
};