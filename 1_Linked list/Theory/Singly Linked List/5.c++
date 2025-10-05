// Insertion in Singly Linked List---------at beginning,at end,at Specific Position
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data; 
    Node* next;
    Node(int new_data)
    {
        data = new_data;
        next = nullptr; 
    }
};
Node* insertAtFront(Node* head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}
Node* insertAtEnd(Node* head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        return new_node;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    return head;
}
Node *insertPos(Node *head, int pos, int data) {
    if (pos < 1)
        return head;
    if (pos == 1) {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) 
        return head;
    Node *newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}
void printList(Node* head)
{
    Node* curr = head;
    while (curr != nullptr) {
        cout << " " << curr->data;
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    cout << "Original Linked List:";
    printList(head);
    cout << "After inserting Nodes at the front:";
    int data = 1;
    head = insertAtFront(head, data);
    printList(head);
    return 0;
}