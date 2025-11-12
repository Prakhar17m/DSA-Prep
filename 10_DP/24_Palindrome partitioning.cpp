//practice link = https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1
//p2 = https://leetcode.com/problems/palindrome-partitioning/description/

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> t;
    bool ispalindrome(string s, int i,int j){
        if (i==j){
            return true;
        }
        if(i>j){
            return true;
        }
        while(i<j){
            if(s[i]!= s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string s,int i,int j){
        int mn = INT_MAX;
        if(i>=j){
            return 0;
        }
        if(ispalindrome(s,i,j)==true){
            return 0;
        }
        if(t[i][j] !=-1){
            return t[i][j];
        }
        for(int k=i;k<j;k++){
            int left,right;
            if(t[i][k]!=-1){
                left = t[i][k];
            }
            else{
                left = solve(s,i,k);
                t[i][k] = left;
            }
            if(t[k+1][j]!=-1){
                right = t[k+1][j];
            }
            else{
                right = solve(s,k+1,j);
                t[k+1][j] = right;
            }
            int temp = 1+left+right;
            if(temp<mn){
                mn = temp;
            }
        }
        t[i][j] = mn;
        return t[i][j];
    }
    int palPartition(string &s) {
        // code here
        int i=1,j=s.size()-1;
        int n = s.size();
        t.assign(n + 1, vector<int>(n + 1, -1));
        return solve(s,i,j);
    }
};