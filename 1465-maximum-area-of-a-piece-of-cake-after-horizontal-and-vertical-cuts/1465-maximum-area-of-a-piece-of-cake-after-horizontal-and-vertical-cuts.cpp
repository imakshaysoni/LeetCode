const int MOD = 1e9 + 7;
class Solution {
public:
    
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long int maxHeight = getMaxGap(horizontalCuts, h),
            maxWidth = getMaxGap(verticalCuts, w);
        
        return (maxWidth * maxHeight) % MOD;
    }
    
    int getMaxGap(const vector<int>& cuts, const int size) {
        int minCut = *min_element(begin(cuts), end(cuts)),
            maxCut = *max_element(begin(cuts), end(cuts));
        int bucketSize = max(1, (maxCut - minCut) / (int) cuts.size()),
            prevBucketMax = minCut,
            ans = max(minCut, size - maxCut);
        vector<tuple<bool, int, int>> buckets((maxCut - minCut) / bucketSize + 1, {false, INT_MAX, INT_MIN});
        
        for (const int& cut: cuts) {
            int bucketIdx = (cut - minCut) / bucketSize;
            
            get<0>(buckets[bucketIdx]) = true;
            get<1>(buckets[bucketIdx]) = min(get<1>(buckets[bucketIdx]), cut);
            get<2>(buckets[bucketIdx]) = max(get<2>(buckets[bucketIdx]), cut);
        }
        
        for (auto &[used, bucketMin, bucketMax]: buckets) {
            if (not used) {
                continue;
            }
            
            ans = max(ans, bucketMin - prevBucketMax);
            prevBucketMax = bucketMax;
        }

        return ans;
    
    // int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        
        
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