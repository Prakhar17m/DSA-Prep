// Deletion in Singly Linked List ---------at beginning,at end,at Specific Position
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
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
// 2.Deletion at end
Node* removeLastNode(struct Node* head)
{
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* second_last = head;
    while (second_last->next->next != nullptr) {
        second_last = second_last->next;
    }
    delete (second_last->next);
    second_last->next = nullptr;
    return head;
}
// 3.Delete a Linked List node at a given position
Node* deleteNode(Node* head, int position)
{
    Node* prev;
    Node* temp = head;
    if (temp == NULL)
        return head;
    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }
    for (int i = 1; i != position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        cout << "Data not present\n";
    }
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
    printList(head);
    return 0;
}