// problem link = https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat.size();
        int m = mat[0].size();
        int i =0;
        int j= m-1;
        while(i>=0 && i<n && j<m && j>=0){
            if(mat[i][j] == x){
                return true;
            }
            else if (mat[i][j]>x){
                j--;
            }
            else if (mat[i][j]<x){
                i++;
            }
        }
        return false;
    }
};