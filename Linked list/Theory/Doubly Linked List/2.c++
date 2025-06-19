// Types of Traversal in Doubly Linked List--Forward Traversal, Backward Traversal
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
// 1. Iterative Approach for Forward Traversal
void forwardTraversal(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
// 2. Recursive Approach for Forward Traversal
void forwardTraversal(Node *head) {
    if (head == nullptr)
        return;
    cout << head->data << " ";  
    forwardTraversal(head->next);  
}
// 3. Iterative Approach for Backward Traversal
void backwardTraversal(Node* tail) {
    Node* curr = tail;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
}
// 4. Recursive Approach for Backward Traversal
void backwardTraversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    backwardTraversal(node->prev);
}
int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    cout << "Forward Traversal: ";
    forwardTraversal(head);
    backwardTraversal(third);
    return 0;
}