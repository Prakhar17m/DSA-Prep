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
Node* deletionAthead(Node* &head){
    if(head==NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node * deletionAtTail(Node* &head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deletionAtPosition(Node* &head,int pos){
    if(head==NULL) return head;
    if(pos==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev = NULL;
    while(temp != NULL ){
        count++;
        if(count==pos){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* deletionValue(Node* &head,int ele){
    if(head==NULL) return head;
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev = NULL;
    while(temp != NULL ){
        if(temp->data == ele){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
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
    
    return 0;
}