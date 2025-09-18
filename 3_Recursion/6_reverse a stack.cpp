// practice link = https://www.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if (st.size()== 1){
            return;
        }
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insert(st,temp);
        return;
    }
    void insert(stack<int> &st,int ele){
        if (st.size()==0){
            st.push(ele);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(st,ele);
        st.push(temp);
        return;
    }
};