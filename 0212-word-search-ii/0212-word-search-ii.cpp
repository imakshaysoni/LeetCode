class Trie{
    public:
        struct trieNode{
            bool isWord=false;
            string word;
            // vector<trieNode*> children(26, nullptr);
            vector<trieNode*> children = vector<trieNode*>(26, nullptr);
        };
        
        trieNode* root;
        
        Trie(){
            root = new trieNode();
        }
        
        void insert(string word){
            
            trieNode* crawl = root;
            for(auto ch: word){
                int index = ch-'a';
                if(crawl->children[index]==nullptr){
                    crawl->children[index] = new trieNode();
                }
                crawl = crawl->children[index];
            }
            crawl->isWord = true;
            crawl->word = word;
            return;
        }
        
        bool search(string word){
            trieNode* crawl = root;
            for(auto ch: word){
                int index = ch-'a';
                if(crawl->children[index]==nullptr){
                    return false;
                }
                crawl = crawl->children[index];
            }
            return crawl->isWord;
        }
};


class Solution {
  public:
    
    void dfs(vector<vector<char>>& board, int row, int col, unordered_map<string, bool> &mapp, Trie::trieNode* crawl){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='#') return;
        
        char ch = board[row][col];
        
        if(crawl->children[ch-'a']==nullptr) return;
        
        crawl = crawl->children[ch-'a'];
        if(crawl->isWord) {
            mapp[crawl->word]=true;
        }
        
        board[row][col]='#';
        
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(abs(dx)==abs(dy)) continue;
                int nrow = row + dx;
                int ncol = col + dy;
                dfs(board, nrow, ncol, mapp, crawl);
            }
        }
        board[row][col] = ch;
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // code here
        Trie root;
        
        for(string word: words){
            root.insert(word);
        }
        
        int rows = board.size();
        int cols = board[0].size();
        
        vector<string> result;
        unordered_map<string, bool> mapp;
        
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                dfs(board, row, col, mapp, root.root);
            }
        }        
        
        for(auto it: mapp){
            if(it.second==true){
                result.push_back(it.first);
            }
        }
        return result;
        
        
    }
};