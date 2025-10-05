// problem link = https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string S) {
        int open = 0;
        string result="";
        for (char data : S){
            if(data == '('){
                if(open>0){
                    result += data;
                }
                open++;
            }
            else{
                open--;
                if(open>0){
                    result+= data;
                }
            }
        }
        return result;
    }
};