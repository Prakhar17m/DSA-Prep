// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int n = s.size();
        int l=0,r=0,max_len=0,len=0;
        while(r<n){
            if (hash[s[r]]!= -1){
                if (hash[s[r]]>=l){
                    l = hash[s[r]]+1;
                }
            }
            len = r-l+1;
            max_len = max(len,max_len);
            hash[s[r]]=r;
            r++;
        }
        return max_len;
    }
};