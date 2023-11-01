class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        vector<int> arr;
        solve(candidates, target, arr, 0);
        return result;
    }
    void solve(vector<int> &c, int target, vector<int> &arr, int index){
        if(target==0) {
            result.push_back(arr);
            return;
        }
        if(target<0 or index>=c.size()){ return; }
        
//         Select First
        arr.push_back(c[index]);
        solve(c, target-c[index], arr, index);
        arr.pop_back();
//             Not Select
        solve(c, target, arr, index+1);
    }
    
    
};