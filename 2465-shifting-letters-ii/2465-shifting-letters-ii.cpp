class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        vector<int> diff(s.size(), 0);

        for(auto it: shifts){
            int left = it[0];
            int right = it[1];
            int dir = it[2];
            if(dir==1) {
                diff[left] += 1;
                if(right+1 < diff.size()) diff[right+1] += -1;
            }
            else {
                diff[left] += -1;
                if(right+1 < diff.size()) diff[right+1] += 1;
            }
        }
        for(int i=0;i<diff.size();i++){
            if(i>0) diff[i] += diff[i-1];

            int shift = diff[i] % 26;
            if(shift<0) shift += 26;

            s[i] = ((s[i] - 'a') + shift ) % 26 + 'a';
        

        }
        return s;
    }
};