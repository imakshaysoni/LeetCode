class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n<=1){
            return "";
        }
        for(int i=0;i<n;i++){
            if(i == n/2){
                palindrome[n-1]='b';            
                return palindrome; }
            if(char(palindrome[i]) != 'a'){
                palindrome[i]='a';
                return palindrome;
            }
            // if(i==palindrome.length()-1){
            //     palindrome[i]='b';            
            //     return palindrome;
            // }

        }
        return palindrome;
    }
};