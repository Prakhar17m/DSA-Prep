// Deletion from a Circular Linked List
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// 1. Delete the first node in circular linked list
Node* deleteFirstNode(Node* last) {
    if (last == nullptr) {
        cout << "List is empty" << endl;
        return nullptr;
    }
    Node* head = last->next;
    if (head == last) {
        delete head;
        last = nullptr;
    } else {
        last->next = head->next;
        delete head;
    }
    return last;
}
// 2. Delete a specific node in circular linked list
Node* deleteSpecificNode(Node* last, int key) {
    if (last == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }
    Node* curr = last->next;
    Node* prev = last;
    if (curr == last && curr->data == key) {
        delete curr;
        last = nullptr;
        return last;
    }
    if (curr->data == key) {
        last->next = curr->next;
        delete curr;
        return last;
    }
    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        delete curr;
    } else {
        cout << "Node with data " << key
          << " not found." << endl;
    }
    return last;
}
// 3. Deletion at the end of Circular linked list
Node* deleteLastNode(Node* last) {
    if (last == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }
    Node* head = last->next;
    if (head == last) {
        delete last;
        last = nullptr;
        return last;
    }
    Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }
    curr->next = head;
    delete last;
    last = curr;
    return last;
}
void printList(Node* last) {
    if(last == NULL) return ;
    Node *head = last->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}
int main() {
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);
    Node* last = first->next->next;
    last->next = first;
    cout << "Original list: ";
    printList(last);
    last = deleteFirstNode(last);
    cout << "List after deleting first node: ";
    printList(last);
    return 0;
}
// int main() {
//     Node* first = new Node(2);
//     first->next = new Node(3);
//     first->next->next = new Node(4);
//     Node* last = first->next->next;
//     last->next = first;
//     cout << "Original list: ";
//     printList(last);
//     int key = 3;
//     last = deleteSpecificNode(last, key);
//     cout << "List after deleting node " << key << ": ";
//     printList(last);
//     return 0;
// }

// int main() {
//     Node* first = new Node(2);
//     first->next = new Node(3);
//     first->next->next = new Node(4);
//     Node* last = first->next->next;
//     last->next = first;
//     cout << "Original list: ";
//     printList(last);
//     last = deleteLastNode(last);
//     cout << "List after deleting last node: ";
//     printList(last);
//     return 0;
// }