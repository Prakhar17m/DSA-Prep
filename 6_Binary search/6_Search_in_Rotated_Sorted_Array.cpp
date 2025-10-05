// problem link = https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target){
        while(start <= end){
            int mid  = start + (end -start) / 2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target <= nums[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int find_Min_index(vector<int>& nums) {
        int start = 0;
        int end  = nums.size() - 1;
        int n = nums.size();
        while(start <= end){
            if (nums[start] <= nums[end]) {
                return start;
            }
            int mid  = start + (end - start) / 2;
            int prev = (mid + n -1) % n;
            int next =  (mid +1)% n;
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                return mid;
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

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0){
            return -1;
        }
        int minindex = find_Min_index(nums);
        if (minindex == 0) {
            return binary_search(nums, 0, n - 1, target);
        }
        if (nums[minindex] == target){
            return minindex;
        }
        if (nums[0]<= target){
            return binary_search(nums, 0, minindex-1, target);
        }
        else{
            return binary_search(nums,minindex, n-1 , target);
        }
    }
};