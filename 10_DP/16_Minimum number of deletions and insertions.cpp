//practice link = https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> t(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        int LCS = t[m][n];
        int INC = n-LCS;
        int DEL = m-LCS;
        return INC+DEL;
    }
};