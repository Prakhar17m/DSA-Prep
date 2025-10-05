// Problem link = https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end  = nums.size() - 1;
        int n = nums.size();
        while(start <= end){
            if (nums[start] <= nums[end]) {
                return nums[start];
            }
            int mid  = start + (end - start) / 2;
            int prev = (mid + n -1) % n;
            int next =  (mid +1)% n;
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                return nums[mid];
            }
            if (nums[start] <= nums[mid]){
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return -1;
    }
};