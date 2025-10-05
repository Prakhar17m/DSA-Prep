// problem link = https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    // Helper function for binary search
    int Binarysearch(vector<int>& nums, int target, bool findFirst) {
        int start = 0, end = nums.size() - 1;
        int result = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (findFirst) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left_index = Binarysearch(nums, target, true);
        int right_index = Binarysearch(nums, target, false);
        return {left_index, right_index};
    }
};
