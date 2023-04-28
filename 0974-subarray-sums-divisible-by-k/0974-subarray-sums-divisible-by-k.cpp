class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        int sum=0;
        int count=0;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            if(sum<0) sum=sum+k;
            if(map.find(sum)!=map.end()){
                count+=map[sum];
            }
            map[sum]++;
        }
        
        for(auto x: map) cout<<x.first<<"->"<<x.second<<endl;
        return count;
        
    }
};