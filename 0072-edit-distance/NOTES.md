}
}
diff = diff + min(l_count,r_count);
}
else{
//             l2>l1
diff = l2-l1;
//             2 options to track
//             track left to right
int l_count=0,r_count=0;
for(int i=0;i<l1;i++){
if(word1[i]!=word2[i]){
l_count++;
}
}
for(int i=l1-1;i>=0;i--){
if(word1[i]!=word2[i]){
r_count++;
}
}
diff = diff + min(l_count,r_count);
}
return diff;
}
};