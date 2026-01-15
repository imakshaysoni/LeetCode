class Trie {
public:

    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;
        for(char ch: word){
            int index = ch-'a';
            if(crawler->children[index]==NULL){
                crawler->children[index] = getNode();
            }
            crawler = crawler->children[index];
        }
        
        crawler->isEndOfWord = true;        
        return;
    }
    
    bool search(string word) {
        trieNode* crawler = root;
        for(char ch: word){
            int index = ch-'a';

            if(crawler->children[index]==NULL) return false;
            crawler = crawler->children[index];
        }

        return crawler->isEndOfWord;        
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for(char ch: prefix){
            int index = ch-'a';
            if(crawler->children[index]==NULL) return false;
            crawler = crawler->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */