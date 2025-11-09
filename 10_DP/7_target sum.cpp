// practice link = https://leetcode.com/problems/target-sum/description/
 // p2 = https://www.geeksforgeeks.org/problems/target-sum-1626326450/1

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
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        int sum = 0;
        for(int s =0 ; s< nums.size();s++){
            totalsum += nums[s];
        }
        if(abs(target)> totalsum) {
            return 0;
        }
        if((target+totalsum)%2!= 0){
            return 0;
        }
        sum = (target + totalsum )/ 2;
        return countsubset(nums,sum);
    }

};
