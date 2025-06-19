// Reversing a Singly Linked List
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};
// Using Iterative Method - O(n) Time and O(1) Space
Node *reverseList(Node *head) {
    Node *curr = head, *prev = nullptr, *next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Using Recursion - O(n) Time and O(n) Space
Node *reverseList(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
// Using Stack - O(n) Time and O(n) Space
Node* reverseList(Node* head) {
    stack<Node*> s;
    Node* temp = head;
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }
    head = temp;
    while (!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
  	return head;
}
void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Given Linked List:";
    printList(head);
    head = reverseList(head);
    cout << "\nReversed Linked List:";
    printList(head);
    return 0;
}