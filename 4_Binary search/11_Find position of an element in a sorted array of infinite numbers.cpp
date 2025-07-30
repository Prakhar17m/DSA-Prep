class Solution {
public:
    int searchPos(vector<int>& nums, int target){
        int start = 0;
        int end = 1;
        while (end < nums.size() && target > nums[end]) {
            start = end;
            end = end * 2;
        }
        if (end >= nums.size()) {
            end = nums.size() - 1;
        }
        return search(nums, start, end, target);
    }
    int search(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};
