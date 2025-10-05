//problem link = https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

// User function template for C++
class Solution {
  public:
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string> v;
        string op="";
        int one =0;
        int zero=0;
        solve(one,zero,n,op,v);
        return v;
    }
    void solve(int one,int zero,int n,string op, vector<string> &v){
        if(n==0){
            v.push_back(op);
            return;
        }
        string op1 = op;
        op1.push_back('1');
        solve(one+1,zero,n-1,op1,v);
        if (one>zero){
            string op2 =op;
            op2.push_back('0');
            solve(one,zero+1,n-1,op2,v);
        }
    }
};