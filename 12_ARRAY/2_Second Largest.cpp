// problem link = https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
public:
    int getSecondLargest(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return -1;

        int first_largest = INT_MIN;
        int second_largest = INT_MIN;

        for (int num : arr) {
            if (num > first_largest) {
                second_largest = first_largest;
                first_largest = num;
            } 
            else if (num < first_largest && num > second_largest) {
                second_largest = num;
            }
        }

        return (second_largest == INT_MIN) ? -1 : second_largest;
    }
};


// python code 
// class Solution:
//     def getSecondLargest(self, arr):
//         # Code Here
//         if len(arr)<2 :
//             return -1
//         first_largest= float('-inf')
//         second_largest = float('-inf')
//         for i in arr:
//             if(i>first_largest):
//                 second_largest = first_largest
//                 first_largest = i
//             elif first_largest > i > second_largest:
//                 second_largest = i
//         return second_largest if second_largest != float('-inf') else -1