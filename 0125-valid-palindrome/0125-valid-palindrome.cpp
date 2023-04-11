class Solution {
public:
    bool isPalindrome(string s) {
        
        return isPal(s,0,s.size()-1);       
    }
    
    bool isPal(string &s, int l, int r){
        if(l>r) return true;
         while (isalnum(s[l]) == false && l < r) l++; // Increment left pointer if not alphanumeric
        while (isalnum(s[r]) == false && l < r) r--; // Decrement right pointer if no alphanumeric
        // while(!isalnum(s[l]) && l<r)l++;
        // while(!isalnum(s[r]) && r>l)r--;
        if(l==r) return true;
        if(toupper(s[l]) != toupper(s[r])) return false;
        
        return isPal(s,l+1,r-1);       
        
    }
        
};