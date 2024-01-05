class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int len = beginWord.size();
        string word= beginWord;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            if(word==endWord) return level;
            q.pop();
            for(int i=0;i<len;i++){
                char orignal = word[i];
                for(int ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        q.push({word, level+1});
                        st.erase(word);
                    }                
                }
                word[i]=orignal;            
        }    
            
            
        }
        return 0;
        
        
        
        
        
    }
};