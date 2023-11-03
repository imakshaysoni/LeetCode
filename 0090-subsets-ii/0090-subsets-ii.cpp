class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, subset);
        return ans;
    }
    
    void solve(vector<int> &num, int index, vector<vector<int>> &ans, vector<int> &subset){
	if(index==num.size()){
		ans.push_back(subset);
		return;
	}

	// Pick First
	subset.push_back(num[index]);
	solve(num, index+1, ans, subset);
	subset.pop_back();
	// Not Picking
    while(index<num.size()-1 and num[index]==num[index+1]) index++;
	solve(num, index+1, ans, subset);

}

};