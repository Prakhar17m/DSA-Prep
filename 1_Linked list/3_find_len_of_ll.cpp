// practice link = https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1\

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
    int getCount(Node* head) {
        // Code here
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
        
    }
};