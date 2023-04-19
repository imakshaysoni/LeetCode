class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        unordered_map<char, int> m;
        int ans=0;
        int finalAns=0;
        helper(arr,ans,0,m, finalAns);
        return finalAns;
    }
    
    
    
    void helper(vector<string> &arr, int &ans, int i, unordered_map<char,int> &m, int &finalAns){
        
        
        if(i>=arr.size()) {
            if(ans>finalAns){
                finalAns=ans;
            }
            return;
        }
        
        
        helper(arr,ans,i+1,m, finalAns);
        // for(int j=i;j<arr.size();j++){
            if(uniqueCheck(arr[i],m)){                
                for(auto x: arr[i]) m[x]++;
                ans+=arr[i].size();
                helper(arr,ans,i+1,m,finalAns);
                for(auto x: arr[i]) m[x]--;
                ans-=arr[i].size();
                    
            }    
        // }
                
    }
    
    bool uniqueCheck(string s, unordered_map<char,int> &m){        
        unordered_map<char,int> map;
        for(auto x: s){
            if(map.find(x)!=map.end()){
                return false;
            }
            if(m[x]>0) return false;
            map[x]++;
        }
        
        return true;
        
    }
};