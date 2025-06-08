class Solution {
public:
    string answerString(string word, int numFriends) {
        
        if(numFriends==1) return word;
         // same comp but better code
        int n = word.size();
        string result = "";
        int maxLen = n - (numFriends-1);
        for(int i=0;i<n;i++){
            int canTake = min(maxLen, n-i);
            result = max(result, word.substr(i, canTake));
        }
        return result;

        
        // index of largest element
        char max_ch = word[0];
        for(int i=1;i<word.size();i++){
            char ch = word[i];
            if(ch-'a' > max_ch - 'a'){
                max_ch = ch;
            }
        }

        // fetch all starts with endelemtn
        string ans = "";
        for(int i=0;i<word.size();i++){
            if(word[i]==max_ch){
                int k = i;
                string temp = "";
                while(k<word.size() and temp.size() < word.size() - (numFriends - 1)){
                    temp += word[k];
                    k++; 
                } 
                ans = max(ans, temp);

            }
        }
        return ans;
    }
};