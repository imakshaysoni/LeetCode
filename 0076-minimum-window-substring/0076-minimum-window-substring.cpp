class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> ft(128, 0);
        vector<int> fs(128,0);
        int min_ans = INT_MAX;
        for(auto it: t) ft[it]++;

        int left =0, right=0;
        int start=0, end=0;
        int count = 0;
        while(right<s.size()){
            char ch = s[right];
            fs[ch]++;

            if(fs[ch]<=ft[ch]) count++;

            while(count==t.size()){
                if(min_ans>=right-left+1){
                    start=left;
                    min_ans = right-left+1;
                }

                char ch1 = s[left];
                fs[ch1]--;
                if(fs[ch1]<ft[ch1]) count--;
                left++;
            }
            right++;
        }
        return (min_ans==INT_MAX) ? "" : s.substr(start, min_ans);


    }
};