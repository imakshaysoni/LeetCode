class Solution {
public:
vector<string> wordBreak(string s, vector<string>& wordDict) {
unordered_set<string> st;
for(auto x: wordDict){
st.insert(x);
}
vector<string> result;
string temp="";
for(int i=0;i<s.size();i++){
temp+=s[i];
if(st.find(temp)!=st.end()){
string temp1 = temp;
temp += " " + solve(s, i+1, st);
result.push_back(temp);
temp = temp1;
}
// temp="";
}
return result;
}
string solve(string &s, int index, unordered_set<string> &wordDict){
if(index==s.size()) return "";
string temp;
string result;
for(int i=index;i<s.size();i++){
temp+=s[i];
if(wordDict.find(temp)!=wordDict.end()){
string ans=temp;
string op = solve(s, i+1, wordDict);
// if(op.size())
result = ans.append(op);
}
}
return result;
}
};