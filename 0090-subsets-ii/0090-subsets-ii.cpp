class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { 
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};


// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         vector<int> subset;
//         subSets(nums,0,ans, subset);
//         return ans;
        
//     }
    
//     void subSets(vector<int> &v, int i, vector<vector<int>> &ans, vector<int> &subset){
        
        
//        if(i>=v.size()){
//            ans.push_back(subset);
//            return;
//        } 
        
// //       Take the first term
//         subset.push_back(v[i]);
//         subSets(v,i+1,ans,subset);
        
// //      Not taking first value
//         unordered_set<int> s;
//         int ignored = subset.back();        
//         s.insert(ignored);
//         subset.pop_back();        
//         // while(i+1<v.size() && v[i]==v[i+1]) i++;
    
//         while(s.find(v[i])!=s.end()){
//             i++;
//         }        
        
//         subSets(v,i+1,ans,subset);
//         // s.erase(s.find(ignored));
//     }
// };