int m=b.size();
if(m==0) return false;
int n = b[0].size();
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(b[i][j]==word[0]){
if(helper(b, i, j, m, n, 0, word)) return true;
}
}
}
return false;
}
bool helper(vector<vector<char>> &b, int i, int j, int m, int n, int k, string word){
if(k >= word.size() ) return true;
if( i<0 || j<0 || i>=m || j>=n || b[i][j]=='.' || b[i][j]!=word[k]) return false;
if(word.size()==1 && word[k]==b[i][j]) return true;
b[i][j]='.';
int temp=false;
// int x[4] = {0,0,-1,1};
// int y[4] = {-1,1,0,0};
// for(int index=0;index<4;index++){
//     temp = temp || helper(b,i+x[index],j+y[index],m,n,k+1,word);
// }
temp = temp || helper(b, i-1, j, m, n , k+1, word);
temp = temp || helper(b, i+1, j, m, n , k+1, word);
temp = temp || helper(b, i, j-1, m, n , k+1, word);
temp = temp || helper(b, i, j+1, m, n , k+1, word);
b[i][j]=word[k];
return temp;