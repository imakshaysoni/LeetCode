class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int largest = 0;
	    int n = v.size();
        unordered_set<int> s;
        for(int x: v){
            s.insert(x);
        }	

        for(int i=0;i<n;i++){
            int num=v[i];
            int len =1;
            if(s.find(num-1)==s.end()){
                while(s.find(num+1)!=s.end()){
                    num++;
                    len++;
                    // s.erase(num+1);
                }
                largest= max(largest,len);
            }
        }
        return largest;
    }
};