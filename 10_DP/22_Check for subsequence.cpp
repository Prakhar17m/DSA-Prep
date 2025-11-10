//practice link = https://www.geeksforgeeks.org/problems/check-for-subsequence4930/1


class Solution {
  public:
    bool isSubSequence(string A, string B) {
        // code here
        int m = A.size();
        int n = B.size();
        vector<vector<int>> t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(A[i-1]==B[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        if(m == t[m][n]){
            return 1;
        }
        else{
            return 0;
        }
    }
};

// or

// class Solution {
//   public:
//     bool isSubSequence(string A, string B) {
//         int i = 0, j = 0;
//         int m = A.size(), n = B.size();
        
//         while (i < m && j < n) {
//             if (A[i] == B[j]) {
//                 i++;
//             }
//             j++;
//         }
        
//         return (i == m);
//     }
// };
