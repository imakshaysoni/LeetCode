class Solution {
public:
    int countSubstrings(string s) {
        
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                count += helper(s,i,j);
            }
        }
        return count;
    }
    
    int helper(string &s, int i, int j){
        if(i>=j) return 1;
        return s[i] == s[j] ? helper(s,i+1,j-1) : 0;
    }
        
        
        
//         TLE
//         vector<string> strSubset;
//         for(int i=0;i<s.size();i++){
//             string temp;
//             for(int j=i;j<s.size();j++){
//                 temp+=s[j];
//                 strSubset.push_back(temp);
//             }
//         }
        
//         int count=0;
//         for(auto str: strSubset){
//             if(isPalindrome(str)) count++;
//         }
//         // for(auto x: strSubset) cout<<x<<endl;
//         return count;
        
//     }
    
//     bool isPalindrome(string str){
        
//         int n = str.size();
//         for(int i=0,j=n-1;i<j; i++,j--){
//             if(str[i]!=str[j]) return 0;
//         }
//         return 1;
//     }
};