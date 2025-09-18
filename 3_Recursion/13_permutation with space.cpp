// problem link =https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

class Solution {
  public:

    vector<string> permutation(string s) {
        // Code Here
        string op="";
        vector<string> v;
        op.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,op,v);
        return v;
    }
    void solve(string s,string op,vector<string> &v)
    {
        if (s.size()==0){
            v.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,op1,v);
        solve(s,op2,v);
        return;
    }
};