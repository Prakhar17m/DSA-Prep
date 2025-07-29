// problem link = https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int start = 0,res =-1, end = arr.size() -1;
        while(start <= end){
            int mid = start +(end - start)/2;
            if (x <= arr[mid]){
                res = mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        return res;
    }
};