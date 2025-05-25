class Solution {
public:
    bool isPalindrome(string w){
        int left= 0;
        int right=w.size()-1;
        while(left<right){
            if(w[left]!=w[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mapp;
        int count=0;
        for(auto w: words){
            if(mapp.find(w)!=mapp.end()){
                count+=4;
                mapp[w] -= 1;
                if(mapp[w] == 0) mapp.erase(w);
            }
            else{
                reverse(w.begin(), w.end());
                mapp[w]+=1;
            }
        }
        cout<<endl<<"Diff W"<<count<<endl;
        for(auto it: mapp){
            // cout<<isPalindrome(it);
            if(isPalindrome(it.first)) {
                count+=2;
                break;
            }
        }
        return count;
        
    }
};