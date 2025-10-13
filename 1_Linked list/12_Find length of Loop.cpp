// practice link = https://www.geeksforgeeks.org/problems/find-length-of-loop/1


/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head;
        Node *fast = head;
        while(fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                int count=1;
                slow = slow->next;
                while(slow!= fast){
                    slow = slow->next;
                    count++;
                }
                return count;
            }
        }
        return 0;
    }
};