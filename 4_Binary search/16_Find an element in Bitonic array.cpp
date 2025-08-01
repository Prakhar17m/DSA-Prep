// problem link = https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid>0 && mid< n-1){
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                    return arr[mid];
                }
                else if(arr[mid-1] > arr[mid]){
                    end = mid -1;
                }
                else{
                    start = mid+1;
                }
            }
            else if(mid == 0){
                if (arr[0] > arr[1]){
                    return arr[0];
                }
                else{
                    return arr[1];
                }
            }
            else if(mid == n-1){
                if(arr[n-1]>arr[n-2]){
                    return arr[n-1];
                }
                else{
                    return arr[n-2];
                }
            }
        }
        return -1;
    }
};