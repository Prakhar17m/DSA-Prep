// practice link = https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));
        for(int i = 0; i <= n; i++){
            t[i][0] = true;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        int mini = INT_MAX;
        for(int s = 0; s <= sum/2; s++) {
            if(t[n][s] == true) {
                mini = min(mini, sum - 2*s);
            }
        }
        return mini;
    }
};