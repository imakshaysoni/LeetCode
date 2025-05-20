class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

        int n = words.size();
        if(n==1) return words;
        int count = 1;
        vector<string> idx;
        idx.push_back(words[0]);
        for(int i=0;i<n-1;i++){
            if(groups[i]!=groups[i+1]){
                //start = i;
                idx.push_back(words[i+1]);
                count++;
            }
        }
        cout<<count;
        
        return idx;
    }
        
};