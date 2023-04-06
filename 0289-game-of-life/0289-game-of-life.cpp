class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count = check(board,i,j,m,n);
                if(board[i][j]==0){
                    if(count==3)board[i][j]=3;
                }
                else if(board[i][j]==1){
                    if(count <2 || count>3)board[i][j]=2;
                }
                
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2 or board[i][j]==3){
                if(board[i][j]%2==0)board[i][j]=0;
                else board[i][j]=1;
                }
            }
        }
        
        
        return;
        
    }
    
    int check(vector<vector<int>> &board, int i, int j, int m, int n){
        int count=0;        
        vector<int> x = {0,0,1,1,-1,-1,-1,1};
        vector<int> y = {-1,1,-1,1,0,-1,1,0};
        for(int index=0;index<x.size();index++){
            if(i+x[index] < 0 || i+x[index] >= m) continue;
            if(j+y[index] < 0 || j+y[index] >= n ) continue;
            if(board[i+x[index]][j+y[index]] == 1 or board[i+x[index]][j+y[index]] == 2){
                count++;
            }
        }
        return count;    
        
       
        
    }
};