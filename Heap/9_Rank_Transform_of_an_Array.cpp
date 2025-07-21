// problem link = https://leetcode.com/problems/rank-transform-of-an-array/description/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue <pair<int,int>> maxh;
        int n = arr.size();
        if (n == 0) return {};
        
        for(int i=0; i< arr.size();i++){
            maxh.push({arr[i],i});
        }
        
        vector<int> result(n);
        unordered_map<int, int> mp;
        int rank = 1;

        while(maxh.size()>0){
            auto [val, index] = maxh.top(); 
            maxh.pop();
            if (mp.find(val) == mp.end()) {
                mp[val] = rank++;
            }
            result[index] = mp[val];
        }
        int maxRank = rank - 1;
        for (int& r : result) {
            r = maxRank - r + 1;
        }
        return result;
    }
};