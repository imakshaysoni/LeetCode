class Solution {
public:
    bool isMatch(string s, string p) {        
        
        
        return helper(s, p, 0, 0);
    }
    
    bool helper(string &s, string &p, int i, int j){
        
        // base cases
        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;
        
        
        bool match = i<s.size() and ((s[i]==p[j]) or p[j]=='.');
        
        if(j+1 < p.size() and p[j+1] == '*'){
            bool op1 = match && helper(s, p, i+1, j);
            bool op2 = helper(s, p, i, j+2);
            return op1 || op2;
        }
        if (match){
           return helper(s, p, i+1,j+1); 
        }
        return false;    
        
        
    }
};