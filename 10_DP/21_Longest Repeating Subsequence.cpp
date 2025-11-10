//practice link = https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        string s1 = s;
        int m = s.size();
        int n = s1.size();
        vector<vector<int>> t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s1[j-1] && i!=j){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};