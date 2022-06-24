class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n<=1){
            return "";
        }
        for(int i=0;i<n;i++){
            if(n>2 and i == n/2){ continue; }
            if(char(palindrome[i]) != 'a'){
                palindrome[i]='a';
                return palindrome;
            }
            if(i==palindrome.length()-1){
                palindrome[i]='b';            
                return palindrome;
            }

        }
        return palindrome;
    }
};