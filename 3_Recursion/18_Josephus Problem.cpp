// problem link =https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/1773401998/


class Solution {
public:
    void solve(vector<int>v, int k, int index, int &ans){
        if(v.size()==1){
            ans = v[0];
            return;
        }
        index = (index+k)%v.size();
        v.erase(v.begin() + index);
        solve(v,k,index,ans);
    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i <= n; i++){
            v.push_back(i);
        }
        int ans =-1;
        solve(v,k-1,0,ans);
        return ans;
    }
};