//practice link = https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1


/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head==NULL && head->next==NULL){
            return head;
        }
        Node* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->data == temp->next->data){
                Node* dup  = temp->next;
                temp->next= dup->next;
                if(dup->next ){
                    dup->next->prev = temp;
                }
                free(dup);
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};