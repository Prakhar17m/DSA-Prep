// problem_link = https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i=0; i< arr.size(); i++){
            minh.push(arr[i]);
            if (minh.size()>k){
                minh.pop();
            }
        }
        vector<int> result;
        while(minh.size()>0){
            result.push_back(minh.top());
            minh.pop();
        }
        sort(result.rbegin(),result.rend());
        return result;
    }
};

// T.c === O(n*logk)