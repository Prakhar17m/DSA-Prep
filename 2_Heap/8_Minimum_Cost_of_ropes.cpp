// problem link = https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int first,second;
        int cost =0;
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i =0; i<arr.size(); i++){
            minh.push(arr[i]);
        }
        while(minh.size()>=2){
            first = minh.top();
            minh.pop();
            second = minh.top();
            minh.pop();
            cost = cost+first+second;
            minh.push(first+second);
        }
        return cost;
    }
};