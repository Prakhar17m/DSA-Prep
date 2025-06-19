// Deletion
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
// 1.Deletion at beginning 
Node* deleteHead(Node* head) {
    if (head == nullptr)
        return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
// 2.Deletion at End--Time Complexity: O(N),Auxiliary Space: O(1)
Node *delLast(Node *head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->prev->next = NULL;
    delete curr; 
    return head;
}
// 3.Deletion at at a given position--Time Complexity: O(N),Auxiliary Space: O(1)
Node * delPos(Node* head, int pos) {
    if (head == NULL)
        return head;

    Node * curr = head;
    for (int i = 1; curr != NULL && i < pos; ++i) {
        curr = curr -> next;
    }
    if (curr == NULL)
        return head;
    if (curr -> prev != NULL)
        curr -> prev -> next = curr -> next;
    if (curr -> next != NULL)
        curr -> next -> prev = curr -> prev;
    if (head == curr)
        head = curr -> next;
    delete curr;
    return head;
}
void printList(Node* curr) {
    while (curr != nullptr) {
      	cout << curr->data << " ";
        curr = curr->next; 
    }
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(18);
    head = deleteHead(head);
    head = delPos(head, 2);
    printList(head);
    return 0;
}