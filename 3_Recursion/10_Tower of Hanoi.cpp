// practice problem = https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        int count =0;
        solve(n,count,from,to,aux);
        return count;
        
    }
    void solve(int n,int &count,int from,int to, int aux){
        if (n==0){
            return;
        }
        solve(n-1,count,from,aux,to);
        count++;
        // cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        solve(n-1,count,aux,to,from);
        return;
    }
};