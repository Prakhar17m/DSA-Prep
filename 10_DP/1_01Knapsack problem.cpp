// problem link - https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> t(n + 1, vector<int>(W + 1, 0));
        for(int i =1; i<=n;i++){
            for(int j = 1;j<=W;j++){
                if(wt[i-1]<=j){
                    t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
        
        
    }
};