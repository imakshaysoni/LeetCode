class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.size()==1) return arr;
        
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        // return my_solution(arr);
        for(int i=0;i<arr.size();i++){
            if(ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }           
            
        }
        return ans;
        
        
        
        
        
    }
    
//     vector<vector<int>> my_solution(vector<vector<int>> &i){
//         int minn = i[0][0];
//         int maxx = i[0][1];
        
//         for(int j=1;j<i.size();j++){
            
//             int curr_minn = i[j][0];
//             int curr_maxx = i[j][1];
//             if(curr_minn <= maxx){
//                 minn = min(minn, curr_minn);
//                 maxx = max(maxx, curr_maxx);
//                 // ans.push_back({minn, maxx});
//             }
//             else{                                
//                 ans.push_back({minn, maxx});
//                 minn = curr_minn;
//                 maxx = curr_maxx;
//             }
//         }
//         ans.push_back({minn,maxx});
//         return ans;
//     }
};