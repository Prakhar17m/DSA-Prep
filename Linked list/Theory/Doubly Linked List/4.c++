// Insertion in a Doubly Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next, *prev;
    Node(int new_data) {
        data = new_data;
        next = prev = NULL;
    }
};
// 1.Insertion at Beginning
Node *insertAtFront(Node *head, int new_data) {
    Node *new_node = new Node(new_data);
    new_node->next = head;
    if (head != NULL)
        head->prev = new_node;
    return new_node;
}
// 2.Insertion at End
Node *insertEnd(Node *head, int new_data) {
    Node *new_node = new Node(new_data);
    if (head == NULL) {
        head = new_node;
    }
    else {
      	Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->prev = curr;
    }
    return head;
}
// 3.Insertion at Specific Position
Node *insertAtPosition(Node *head, int pos, int new_data) {
    Node *new_node = new Node(new_data);
    if (pos == 1) {
        new_node->next = head;
        if (head != NULL)
            head->prev = new_node;
        head = new_node;
        return head;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Position is out of bounds." << endl;
        delete new_node;
        return head;
    }
    new_node->prev = curr;
    new_node->next = curr->next;
    curr->next = new_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    return head;
}
void printList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << " " << curr->data;
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    cout << "Original Linked List:";
    printList(head);
    cout << "After inserting Node at the front:";
    int data = 1;
    head = insertAtFront(head, data);
    int d = 5;
    head = insertEnd(head, d);
    cout << "Inserting Node with data 3 at position 3: ";
    int data = 3;
    int pos = 3;
    head = insertAtPosition(head, pos, data);

    printList(head);
    return 0;
}