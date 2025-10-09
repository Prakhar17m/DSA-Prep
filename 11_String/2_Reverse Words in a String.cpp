// problem link = https://leetcode.com/problems/reverse-words-in-a-string/


class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string temp = "";
        stack<string> st;
        for (int i=0;i<s.size();i++){
            char ch = s[i];
            if (ch ==' '){
                if(!temp.empty()){
                    st.push(temp);
                }
                temp="";
            }
            else{
                temp+= ch;
            }
        }

        if (!temp.empty()) {
            st.push(temp);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop(); 
            if (!st.empty()) ans += " ";

        }
        return ans;
    }
};




// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         string word;
//         vector<str> words
//         if(ss >> word){
//             words
//         }
//     }
// };