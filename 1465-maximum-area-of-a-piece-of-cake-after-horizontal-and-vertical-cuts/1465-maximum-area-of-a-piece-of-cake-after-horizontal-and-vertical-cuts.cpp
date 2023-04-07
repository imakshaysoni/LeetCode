const int MOD = 1e9 + 7;
class Solution {
public:
    
       
    int maxArea(int h, int w, vector<int>& HCuts, vector<int>& VCuts) {
        
        
        HCuts.push_back(h);
        HCuts.push_back(0);
        sort(HCuts.begin(),HCuts.end());
        
        int maxh=INT_MIN;
        for(int i=1;i<HCuts.size();i++){
            maxh = max(maxh, HCuts[i]-HCuts[i-1]);
        }
        
        VCuts.push_back(w);
        VCuts.push_back(0);
        sort(VCuts.begin(),VCuts.end());
        
        int maxv=INT_MIN;
        for(int i=1;i<VCuts.size();i++){
            maxv = max(maxv, VCuts[i]-VCuts[i-1]);
        }
        
        cout<<maxh<<" "<<maxh;
        return (1LL*maxh*maxv)%1000000007;
        
    }
};