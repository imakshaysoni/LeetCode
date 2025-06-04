class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // brute force     
        if(n==1) return 1;
        if(trust.size()==0) return -1;       

        return myfirstApproch(n, trust);
        
    }

    int potentialJudge(int judge, vector<vector<int>> & trust){
        unordered_map<int, set<int>> mapp;
        for(int i=0;i<trust.size();i++){
            int man = trust[i][0];
            int t = trust[i][1];

            if(mapp.find(man)!= mapp.end()){
                mapp[man].insert(t);
            }
            else{
                mapp[man] = {t};
            }
        }
        for(auto it: mapp){
            set<int> st = it.second;
            if(st.find(judge)==st.end()) return -1;
        }
        return judge;
    }

    int myfirstApproch(int n, vector<vector<int>> &trust){
        unordered_set<int> st;
        for(auto it: trust){
            st.insert(it[0]);
        }

        int totSum=0;
        for(auto it: st) totSum += it;

        int allSum = (n *(n+1))/2;
        if(allSum - totSum) {
            return potentialJudge(allSum-totSum , trust);
        }
        return -1;
    }
};