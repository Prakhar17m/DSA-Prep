//practice link = https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  public:
    int t[101][101];
    int matrixMultiplication(vector<int> &arr) {
        // code here
        memset(t,-1,sizeof(t));
        return solve(arr,1,arr.size()-1);
    }
    int solve(vector<int> arr,int i,int j){
        if(i>=j){
            return 0;
        }
        int mn = INT_MAX;
        if(t[i][j] != -1){
            return t[i][j];
        }
        for(int k =i;k<j;k++){
            int tempans = solve(arr,i,k) + solve(arr,k+1,j) +arr[i-1]*arr[k]*arr[j];
            if(tempans<mn){
                mn = min(mn,tempans);
            }
        }
        t[i][j] = mn;
        return t[i][j];
    }
};