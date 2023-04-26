else break;
}
int digCnt=0;
for(int i=row,j=col;i<m.size() && j<m[0].size();j++,i++){
if(m[i][j]=='1') digCnt++;
else break;
}
int minCount = min(min(rightCnt, downCnt), digCnt);
// int cnt = 0;
for(int i=row+1;i<row+minCount;i++){
for(int j=col;j<col+minCount;j++){
// cout<<i<<" "<<j<<endl;
if(m[i][j]=='0'){
// return cnt*cnt;
return row-i;
}
}
}
return minCount;
return minCount*minCount;
}
};