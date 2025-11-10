//practice link = https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

class Solution {
  public:
    vector<string> allLCS(string &s1, string &s2) {
        // Code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> t(m+1,vector<int>(n+1,0));
        string s ="";
        for(int i =1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        int i=m,j=n;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                s.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i][j-1] > t[i-1][j]){
                    j--;
                }
                else{
                    i--;
                }
            }
        }
        reverse(s.begin(),s.end());
        return {s};
    }
};
