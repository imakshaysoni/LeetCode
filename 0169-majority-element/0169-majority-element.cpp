class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> mapper;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mapper.find(nums[i])!=mapper.end()){
                mapper[nums[i]]++;
            }
            else{
                mapper[nums[i]] = 1;
            }
        }

        for(auto it: mapper){
            int number = it.first;
            int count = it.second;
            if(count>n/2) return number;
        }
        return -1;
        // Brute force
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int number = nums[i];
        //     int count = 1;

        //     for(int j=i+1;j<n;j++){
        //         if(nums[j]==number) count++;
        //     }

        //     if(count > n/2) return number;

        // }
        // return -1;
        // TC O(n*n)
    }
};