// Length of Singly Linked List:
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};
// Iterative Approach
int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}
// Recursive Approach
int countNodes(Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + countNodes(head->next);
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    cout << "Count of nodes is " << countNodes(head);
    return 0;
}