//problem link = https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
// this probloem can also be called as sort the k sorted array

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int> , greater<int>> minh;
        vector<int> result;
        for(int i=0; i< arr.size() ;i++){
            minh.push(arr[i]);
            if(minh.size() > k){
                result.push_back(minh.top());
                minh.pop();
            }
        }
            while(minh.size() > 0){
                result.push_back(minh.top());
                minh.pop();
            }
        arr = result;
    }
};
