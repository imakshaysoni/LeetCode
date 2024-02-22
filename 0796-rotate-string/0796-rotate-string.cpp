class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size()!=goal.size()) return false;
        int n = s.size();
        
        int k = n;
        while(k>0){
            char ch = s[0];
            for(int i=0;i<n-1;i++){
                s[i] = s[i+1];
            }
            s[n-1] = ch;
            if(s==goal) return true;
            k--;
        }
        return false;
    }
};