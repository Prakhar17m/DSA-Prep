// problem link = https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int res = -1;
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] <= x) {
                res = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return res;
    }
};
