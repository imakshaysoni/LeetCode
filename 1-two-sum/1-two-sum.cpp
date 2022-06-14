class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int targetSum) {
        
        int n = arr.size();
        vector<int> result;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int req_num = targetSum-arr[i];
            if(m.count(req_num)){
                result.push_back(i);
                result.push_back(m[req_num]);
            }
            else{
                m[arr[i]] = i;
            }
        }

        return result;
        
    }
};