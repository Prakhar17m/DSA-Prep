//practice link = https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
//p2 = https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m  = s1.size();
        int n = s2.size();
        int ans =0;
        vector<vector<int>> t(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1+ t[i-1][j-1];
                    ans = max(ans,t[i][j]);
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        return ans;
    }
};