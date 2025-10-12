 

#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next= NULL;
        prev= NULL;
    }
};
class DoublyList{
    Node* head;
    Node* tail;
    public:
    DoublyList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtPosition(int pos,int val){
        Node *newNode = new Node(val);
        if(pos==1){
            insertAtHead(val);
            return;
        }
        Node* temp = head;
        int count =1;
        while(temp != NULL && count<pos-1){
            temp = temp->next;
            count++;
        }
        if(temp ==NULL){
            insertAtTail(val);
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next !=NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        return;
    }
    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(tail ==NULL){
            tail = newNode;
            head = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void printlist(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data << " <=> ";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
};

int main(){
    DoublyList dll;
    dll.printlist();
    // dll.insertAtHaed(10);
    // dll.insertAtHaed(20);
    // dll.insertAtHaed(30);
    // dll.printlist();
    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.printlist();
    return 0;
}