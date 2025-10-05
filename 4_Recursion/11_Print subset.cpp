// problem link = https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, int index) {
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // exclude nums[index]
        solve(nums, curr, index + 1);

        // include nums[index]
        curr.push_back(nums[index]);
        solve(nums, curr, index + 1);

        // backtrack
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, curr, 0);
        return ans;
    }
};
