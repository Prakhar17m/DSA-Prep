//problem link = https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1




#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k) {
    unordered_map<int, int> mp;  // prefix_sum -> first index
    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefix_sum += arr[i];

        // Case 1: Subarray from index 0 to i
        if (prefix_sum == k) {
            max_len = max(max_len, i + 1);
        }

        // Case 2: Subarray in between
        if (mp.find(prefix_sum - k) != mp.end()) {
            max_len = max(max_len, i - mp[prefix_sum - k]);
        }

        // Store prefix_sum if first occurrence
        if (mp.find(prefix_sum) == mp.end()) {
            mp[prefix_sum] = i;
        }
    }

    return max_len;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout << longestSubarrayWithSumK(arr, k) << endl; // Output: 6
    return 0;
}
