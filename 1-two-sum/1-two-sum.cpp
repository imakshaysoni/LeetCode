class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int targetSum) {
        
        int n = arr.size();
        vector<int> result;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==targetSum){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
        
    }
};