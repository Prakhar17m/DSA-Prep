// problem_link = https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int n =arr.size();
        priority_queue <int> maxh;
        for(int i=0; i< n;i++){
            maxh.push(arr[i]);
            if (maxh.size()>k){
                maxh.pop();
            }
        }
        return maxh.top();
    }
};