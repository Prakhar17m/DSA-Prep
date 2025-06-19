// insertion in circular linked list
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
// Insertion in an empty List in the circular linked list
Node *insertInEmptyList(Node *last, int data){
    if (last != nullptr) return last;
    Node *newNode = new Node(data);
    newNode->next = newNode;
    last = newNode;
    return last;
}
// Insertion at the beginning in circular linked list
Node* insertAtBeginning(Node* last, int value){
    Node* newNode = new Node(value);
    if (last == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}
// Insertion at the end in circular linked list
Node *insertEnd(Node *tail, int value)
{
    Node *newNode = new Node(value);
    if (tail == nullptr){
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}
// Insertion at specific position in circular linked list
Node *insertAtPosition(Node *last, int data, int pos){
    if (last == nullptr){
        if (pos != 1){
            cout << "Invalid position!" << endl;
            return last;
        }
        Node *newNode = new Node(data);
        last = newNode;
        last->next = last;
        return last;
    }
    Node *newNode = new Node(data);
    Node *curr = last->next;
    if (pos == 1){
        newNode->next = curr;
        last->next = newNode;
        return last;
    }
    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;
        if (curr == last->next){
            cout << "Invalid position!" << endl;
            return last;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;
    if (curr == last) last = newNode;
    return last;
}
void printList(Node* last){
    if(last == NULL) return;
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}
int main(){
    Node *last = nullptr;
    last = insertInEmptyList(last, 1);
    cout << "List after insertion: ";
    printList(last);
    return 0;
}

// int main(){
//     Node* first = new Node(2);
//     first->next = new Node(3);
//     first->next->next = new Node(4);
//     Node* last = first->next->next;
//     last->next = first;
//     cout << "Original list: ";
//     printList(last);
//     last = insertAtBeginning(last, 5);
//     cout << "List after inserting 5 at the beginning: ";
//     printList(last);
//     return 0;
// }

// int main(){
//     Node *first = new Node(2);
//     first->next = new Node(3);
//     first->next->next = new Node(4);
//     Node *last = first->next->next;
//     last->next = first;
//     cout << "Original list: ";
//     printList(last);
//     last = insertEnd(last, 5);
//     last = insertEnd(last, 6);
//     cout << "List after inserting 5 and 6: ";
//     printList(last);
//     return 0;
// }

// int main(){
//     Node *first = new Node(2);
//     first->next = new Node(3);
//     first->next->next = new Node(4);
//     Node *last = first->next->next;
//     last->next = first;
//     cout << "Original list: ";
//     printList(last);
//     int data = 5, pos = 2;
//     last = insertAtPosition(last, data, pos);
//     cout << "List after insertions: ";
//     printList(last);
//     return 0;
// }