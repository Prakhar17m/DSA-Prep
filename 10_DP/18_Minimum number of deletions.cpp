//practice link = https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
//p2 = https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution {
  public:
    int LCS(string a,string b){
        int m = a.size();
        int n = b.size();
        vector<vector<int>> t(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
    int minDeletions(string &s) {
        // code here
        int m = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        return m-LCS(s,s1);
    }
};