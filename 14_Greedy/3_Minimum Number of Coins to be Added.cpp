//practice link = https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> coins={1, 2, 5, 10};
        int t = coins.size();
        int ans =0;
        for(int i=t-1;i>=0;i--){
            while(n>=coins[i]){
                n = n-coins[i];
                ans++;
            }
        }
        return ans;
    }
};
