class Solution {
public:
    bool rotateString(string s, string goal) {
    
    if(s.length()!=goal.length()) { return false; }
    
    int n=s.length();
    for(int i=0;i<n;i++){
        char ch = s[0];
        s.erase(0,1);
        s.push_back(ch);
        if(s==goal){ return true; }
    }
        return false;
    }
};


// BurteForce O(n2)
// int n = s.length();
//         int k=n;
//         while(k>0){
//             char ch = s[0];
//             for(int i=0;i<n-1;i++){
//                 s[i] = s[i+1];
//             }
//             s[n-1]=ch;
//             cout<<s<<endl;
//             if(s==goal){ return true; }
//             k--;
//         }
//         return false;
        