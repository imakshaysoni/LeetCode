class Solution {
public:
    vector<vector<string>> ans;
    void dfs(string word, vector<string> &seq, unordered_map<string, int> &mapp, string beginWord){
        
        int step = mapp[word];
        string curr_word = word;
        
        if(word==beginWord){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        for(int i=0;i<word.size();i++){
            string orignal = word;
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mapp.find(word)!=mapp.end() and 
                    mapp[word]+1 == mapp[curr_word]){
                    seq.push_back(word);
                    dfs(word, seq, mapp, beginWord);
                    seq.pop_back();
                }
            }
            word = orignal;
        }
        return;
        
        
        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mapp;
        mapp[beginWord]=0;
        
        queue<string> q;
        q.push(beginWord);
        int step = 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.count(beginWord)) st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int curr_step = mapp[word];
            if(word==endWord) break;
            
            
            for(int i=0;i<word.size();i++){
                string orignal = word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        mapp[word] = curr_step+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word = orignal;
            }
        }
        
        // cout<<"Mapping\n";
        // for(auto it: mapp) cout<<it.first<<":"<<it.second<<endl;
        
        //Step 2: DFS traver from reverse of mapp
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq, mapp, beginWord);
        return ans;
    }
};