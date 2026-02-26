class Solution {
public:
    int minCut(string s) {


        return solve(s, 0)-1;
        
    }
    int solve(string s, int i){

        if(i>=s.size()) return 0;
        string str = "";
        int mini = 1e8;
        for(int j=i;j<s.size();j++){
            str+=s[j];
            if(isPalindrome(str)){
                int result = 1 + solve(s, j+1);

                mini = min(mini, result);           
            }    

        }
        return mini;


    }

    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        while(start <= end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};