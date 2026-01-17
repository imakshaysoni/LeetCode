class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };

    trieNode* getNode(){
        trieNode* node = new trieNode();
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    trieNode* root = getNode();
    
    void insert(int number){
        trieNode* crawl = root;

        for(int i=31;i>=0;i--){
            int ith_bit = (number>>i) & 1;
            if(ith_bit==0){
                if(crawl->left==nullptr) crawl->left= getNode();
                crawl = crawl->left;
            }
            else{
                if(crawl->right==nullptr) crawl->right= getNode();
                crawl = crawl->right;
            }
        }
        return;

    }

    int getMaxXor(int number){
        trieNode* crawl = root;
        long long xorr = 0;
        for(int i=31;i>=0;i--){
            int ith_bit = (number>>i) & 1;
            if(ith_bit==0){ //i_th bit - 0
                if(crawl->right!=nullptr){
                    xorr += pow(2, i);
                    crawl = crawl->right;
                }
                else{
                    crawl = crawl->left;
                }
            }
            else{
                if(crawl->left!=nullptr){
                    xorr += pow(2, i);
                    crawl = crawl->left;
                }
                else crawl = crawl->right;
            }
        }
        return int(xorr);

    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root;
        int maxXor = 0;
        for(auto number: nums){
            insert(number);
        }

        for(auto number: nums){
            int xorr = getMaxXor(number);
            maxXor = max(xorr, maxXor);
        }        
        return maxXor;         

         
    }
};