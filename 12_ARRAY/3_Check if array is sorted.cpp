// problem link = https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

class Solution {
public:
    bool isSorted(vector<int> &arr) {
        int temp = INT_MIN; 
        
        for (int i : arr) {
            if (i < temp) {
                return false;   // Found an unsorted pair
            }
            temp = i;
        }
        return true;  // Array is sorted
    }
};



// python code 
// class Solution:
//     def isSorted(self, arr) -> bool:
//         # code here
//         temp = float('-inf')
//         for i in arr:
//             if i<temp:
//                 return False
//             temp = i
//         return True