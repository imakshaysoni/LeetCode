class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int k=n;
        while(k>0){
            char ch = s[0];
            for(int i=0;i<n-1;i++){
                s[i] = s[i+1];
            }
            s[n-1]=ch;
            cout<<s<<endl;
            if(s==goal){ return true; }
            k--;
        }
        return false;
        
    }
};