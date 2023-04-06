class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        
         int count=0;
        vector<int>v(60,0);
        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;
            if(a==0)
                count+=v[0];
            else
                count+=v[60-a];
            v[a]++;
        }
        return count;
        
//         int ans=0;
//         int n = time.size();
//         if(time.size()<=1)return 0;
//         unordered_map<int,int> m;
//         for(int i=n-1;i>=0;i--){
//             int x = time[i]%60;
//             int find=60-x;
//             if(m.find(find)!=m.end()){
//                 ans+=m[find];
//             }
//             if(x==0)x=find;
//             if(m.find(x)!=m.end())m[x]+=1;
//             else m[x]=1;
            
//         }        
//         return ans;
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