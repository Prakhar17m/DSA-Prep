class Solution {
public:
    int largest(vector<int> &arr) {
        int l = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            if (l < arr[i]) {
                l = arr[i];
            }
        }
        return l;
    }
};



// python code
// class Solution:
//     def largest(self, arr):
//         # code here
//         l=arr[0]
//         for i in range(len(arr)):
//             if(l<arr[i]):
//                 l = arr[i]
//         return l
        

