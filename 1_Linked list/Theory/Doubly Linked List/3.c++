// Program to find size of Doubly Linked List
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
// Approach - Using While Loop – O(n) Time and O(1) Space
int findSize(Node *curr) {
    int size = 0;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }
    return size;
}
// Approach - Using Recursion - O(n) Time and O(n) Space
int findSize(Node* head) {
    if (head == NULL)
        return 0;
    return 1 + findSize(head->next); 
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    cout << findSize(head);
    return 0;
}