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