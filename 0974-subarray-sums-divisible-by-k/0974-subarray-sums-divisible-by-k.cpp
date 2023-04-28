class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
     
       vector<int> counts(K, 0);
    counts[0] = 1;
    int count = 0, running_sum = 0;
    for (int i = 0; i < A.size(); i++) {
        running_sum = (running_sum + A[i]) % K;
        if (running_sum < 0) running_sum += K; // fix negative modulo
        count += counts[running_sum];
        counts[running_sum]++;
    }
    return count;
//         unordered_map<int,int> map;
        
//         int sum=0;
//         int count=0;
//         map[0]=-1;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//             if(sum%k==0) count++;
//             int rem = sum%k;
//             if(map.find(rem)!=map.end()){
//                 count++;
//             }
//             map[rem]=i;
//         }
        
//         for(auto x: map) cout<<x.first<<"->"<<x.second<<endl;
//         return count;
        
    }
};