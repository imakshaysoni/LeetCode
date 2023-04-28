class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
     
        unordered_map<int, int> remainders;
        remainders[0] = 1;
        int count = 0, running_sum = 0;
        for (int i = 0; i < A.size(); i++) {
            running_sum = (running_sum + A[i]) % K;
            if (running_sum < 0) running_sum += K; // fix negative modulo
            if (remainders.count(running_sum)) {
                count += remainders[running_sum];
                remainders[running_sum]++;
            } else {
                remainders[running_sum] = 1;
            }
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