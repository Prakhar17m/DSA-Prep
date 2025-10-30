class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        for(int i =0;i<arr.size();i++){
            for(int j = i+1;j<arr.size();j++){
                if(arr[i]<arr[j]){
                    swap(arr[i],arr[j]);
                }
            }
        }
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
        

