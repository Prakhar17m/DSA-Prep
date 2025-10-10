#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head  = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtPosition(Node* &tail,Node* &head,int pos, int d){
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int count =1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(temp,d);
        return;
    }
    Node* nodetoinsert  = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next  =nodetoinsert;
}
void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(10);
    // cout << node1-> data << endl;
    // cout << node1-> next << endl;
    Node* head = node1;
    Node* tail = node1;
    print(head);
    // insertAtHead(head,12);
    // print(head);
    // insertAtHead(head,15);
    // print(head);
    // insertAtTail(tail,12);
    // print(head);
    // insertAtTail(tail,15);
    // print(head);
    // insertAtPosition(head,3,13);
    // print(head);
    // insertAtPosition(head,1,8);
    // print(head);
    // insertAtPosition(tail,head,3,13);
    // print(head);
    return 0;
}