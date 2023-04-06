class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int ans=0;
        int n = time.size();
        if(time.size()<=1)return 0;
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--){
            int x = time[i]%60;
            int find=60-x;
            if(m.find(find)!=m.end()){
                cout<<find<<"*"<<ans<<m[find]<<endl;
                ans+=m[find];
            }
            if(x==0)x=find;
            if(m.find(x)!=m.end())m[x]+=1;
            else m[x]=1;
            
        }
        cout<<endl;
        for(auto x: m){
            cout<<x.first<<" "<<x.second<<endl;
        }
        
        return ans;
        
        
        
        
    }
};


// BruteForce O(N2)

//  if(time.size()<=1)return 0;
        
//         int ans=0;
        
        
//         for(int i=0;i<time.size()-1;i++){
//             for(int j=i+1;j<time.size();j++){
//                 int duration = time[i]+time[j];
//                 if(duration%60==0)ans++;
//             }
//         }
        
//         return ans;