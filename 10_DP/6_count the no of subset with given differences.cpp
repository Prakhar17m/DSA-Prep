// practice link = https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution {
  public:
    int countsubset(vector<int>& arr , int sum){
        int n = arr.size();
        vector<vector<int>> t(n+1,vector<int> (sum+1 , 0));
        for(int i =0; i<= n ; i++){
            t[i][0] = 1;
        }
        for(int i= 1;i<=n;i++){
            for(int j =0; j<= sum ;j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int totalsum=0;
        int sum = 0;
        for(int s =0 ; s< arr.size();s++){
            totalsum += arr[s];
        }
        if(diff> totalsum) {
            return 0;
        }
        if((diff+totalsum)%2!= 0){
            return 0;
        }
        sum = (diff + totalsum )/ 2;
        return countsubset(arr,sum);
        
    }
};