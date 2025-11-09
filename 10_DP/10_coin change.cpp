// practice link =https://www.geeksforgeeks.org/problems/coin-change2448/1



// coins problem with max number of ways
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> t(n+1,vector<int> (sum+1,0));
        for(int i = 0;i<=n;i++){
            t[i][0] = 1;
        }
        for(int j = 1;j<=sum;j++){
            t[0][j] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j){
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};


// coins problem with the min number of ways
