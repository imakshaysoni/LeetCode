class Solution {
public:
    bool search(int r, int c, size_t i, const string &word, vector <vector <char>> &board) {
        if(i == word.size()) {return true;}
        else if(r < 0 || r >= (int) board.size() || c < 0 || c >= (int) board[0].size()) {return false;}
        else if(board[r][c] != word[i]) {return false;}
        
        board[r][c] = '#';
        
        bool ret = search(r - 1, c, i + 1, word, board) || search(r + 1, c, i + 1, word, board)
                || search(r, c - 1, i + 1, word, board) || search(r, c + 1, i + 1, word, board);
        
        board[r][c] = word[i];
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size(), C = board[0].size(), N = word.size();
        
        // Prune #1: If there aren't even enough letters in the board to fit word, then return false
        if((int) word.size() > R * C) {return false;}
        
        // Prune #2: For each letter, the board must contain at least as many of that letter as word contains
        int occ[128] = {};
        for(const auto &v : board) {for(char c : v) {++occ[c];}}
        for(char c : word) {
            if(--occ[c] < 0) {return false;}
        }
        
        // Prune #3: Find the longest prefix/suffix of the same character. If the longest suffix is longer
        // than the longest prefix, swap the strigns (so we are less likely to have a long prefix with a lot
        // of the same character)
        int left_pref = word.find_first_not_of(word[0]);
        int right_pref = word.size() - word.find_last_not_of(word.back());
        if(left_pref > right_pref) {
            reverse(word.begin(), word.end());
        }
        
        // for every starting point, see if we can find word from there
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(search(r, c, 0, word, board)) {return true;}
            }
        }
        return false;
    }
};