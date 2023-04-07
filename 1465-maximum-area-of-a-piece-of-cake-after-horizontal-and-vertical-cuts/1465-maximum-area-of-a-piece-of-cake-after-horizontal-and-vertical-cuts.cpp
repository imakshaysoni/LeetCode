class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        
         hC.push_back(h);
        sort(hC.begin(), hC.end());
		int maxh = hC[0];
        for(int i=1; i<hC.size(); i++){
            maxh = max(maxh, hC[i] - hC[i-1]);
        }
        
        vC.push_back(w);
        sort(vC.begin(), vC.end());
		int maxv = vC[0];
        for(int i=1; i<vC.size(); i++){
            maxv = max(maxv, vC[i] - vC[i-1]);
        }
		
        return (1LL*maxh*maxv) % 1000000007; //1LL used to make the product long long or integer sign overflow will occur.
        
//         HCuts.push_back(h);
//         HCuts.push_back(0);
//         sort(HCuts.begin(),HCuts.end());
        
//         int maxh=INT_MIN;
//         for(int i=1;i<HCuts.size();i++){
//             maxh = max(maxh, HCuts[i]-HCuts[i-1]);
//         }
        
//         VCuts.push_back(w);
//         VCuts.push_back(0);
//         sort(VCuts.begin(),VCuts.end());
        
//         int maxv=INT_MIN;
//         for(int i=1;i<VCuts.size();i++){
//             maxv = max(maxv, VCuts[i]-VCuts[i-1]);
//         }
        
//         cout<<maxh<<" "<<maxh;
//         return (1LL*maxh*maxv)%1000000007;
        
    }
};