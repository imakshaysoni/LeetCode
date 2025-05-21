class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        // Brute Force
        // return brute_force(nums, queries);
        // nums.push_back(0);
        vector<int> diff(nums.size(), 0);

        for (auto it : queries) {
            int left = it[0];
            int right = it[1];
            diff[left] += -1;
            if (right + 1 < diff.size()) {
                diff[right + 1] -= -1;
            }
        }
        // Commulative
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }
        for (auto it : diff)
            cout << it << ",";
        for (int i = 0; i < nums.size(); i++) {
            if (abs(diff[i]) < nums[i])
                return false;
        }
        return true;
    }

    bool other(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, int> mapp;
        for (auto it : queries) {
            int left = it[0];
            int right = it[1];
            while (left <= right) {
                mapp[left] += 1;
                left++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= mapp[i];
            if (nums[i] > 0)
                return false;
        }
        return true;
    }

    bool brute_force(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto it : queries) {
            int left = it[0];
            int right = it[1];

            for (int i = left; i <= right; i++) {
                if (nums[i] != 0) {

                    nums[i]--;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                return false;
        }
        return true;
    }
};