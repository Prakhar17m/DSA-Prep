// Modify a Singly Linked List
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
Node* modifyTheList(Node* head) {
    if (!head->next) {
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    Node* mid;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;
    Node* reversedList = mid->next;
    mid->next = nullptr;
    reversedList = reverse(reversedList);
    Node* curr1 = head;
    Node* curr2 = reversedList;
    vector<int> firstHalf, secondHalf;
    while (curr1 != nullptr) {
        firstHalf.push_back(curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
        secondHalf.push_back(curr2->data);
        curr2 = curr2->next;
    }
    for (int i = 0; i < secondHalf.size(); i++) {
        int x = firstHalf[i];
        firstHalf[i] = secondHalf[i] - x;
        secondHalf[i] = x;
    }
    curr1 = head;
    for (int val : firstHalf) {
        curr1->data = val;
        curr1 = curr1->next;
    }
    curr2 = reversedList;
    for (int val : secondHalf) {
        curr2->data = val;
        curr2 = curr2->next;
    }
    mid->next = reverse(reversedList);
    return head;
}
void printList(Node* node) {
    Node* curr = node;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(6);
    head = modifyTheList(head);
    printList(head);
    return 0;
}