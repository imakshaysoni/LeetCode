class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        
        int r = board.size();
        int c = board[0].size();
        if(word.size() > r*c) return false;
        
        int arr[128] = {0}; 
        for(auto &v: board){
            for(auto c: v){
                arr[ c ]++; 
            }
        }
        for(auto c: word){
            if(--arr[c] < 0 ) return false;
        }
        
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(helper(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char>> &board, string &word, int i, int j, int k){
        
        if(k >= word.size()) return true;
       
        if(i < 0 || j < 0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[k]) return false;
        
        if(board[i][j] == '.') return false;
        
        board[i][j] = '.';
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1, -1, 0, 0};
        
        bool temp = false;
        for(int index=0;index<4;index++){
            temp = temp || helper(board, word, i+dx[index], j+dy[index], k+1);
        }
        
        board[i][j] = word[k];
        return temp;       
        
    }
};