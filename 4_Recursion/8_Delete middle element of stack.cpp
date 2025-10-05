// practie link = https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        if (s.size()==0){
            return;
        }
        int k = (s.size()/2) +1;
        solve(s,k);
        return;
    }
    void solve(stack<int> &s,int k){
        if (k==1){
            s.pop();
            return;
        }
        int temp =s.top();
        s.pop();
        solve(s,k-1);
        s.push(temp);
        return;
    }
};