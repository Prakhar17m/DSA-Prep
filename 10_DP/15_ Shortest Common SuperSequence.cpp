//practice link = https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1


class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n = s2.size();
        int m = s1.size();
        vector<vector<int>> t(m+1,vector<int> (n+1,0));
        for(int i = 1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return m+n-t[m][n];
    }
};