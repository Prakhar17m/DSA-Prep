class Solution {
public:
    int findPeakIndex(MountainArray &mountainArr) {
        int start = 0, end = mountainArr.length() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
    int binarySearch(MountainArray &arr, int target, int start, int end, bool ascending) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = arr.get(mid);
            if (val == target) {
                return mid;
            }

            if (ascending) {
                if (val < target) start = mid + 1;
                else end = mid - 1;
            } else {
                if (val > target) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeakIndex(mountainArr);
        int index = binarySearch(mountainArr, target, 0, peak, true);
        if (index != -1) return index;
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }
};
