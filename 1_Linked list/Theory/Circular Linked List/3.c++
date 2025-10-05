// Searching in Circular Linked list
#include <iostream>
using namespace std;

class Search {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
    };

public:
    Node* head = nullptr;
    Node* tempo = nullptr;

    // Function to add new nodes at the end of the list
    void addNode(int data)
    {
        Node* new1 = new Node(data);
        if (head == nullptr) {
            head = new1;
        }
        else {
            tempo->next = new1;
        }
        tempo = new1;
        tempo->next = head;
    }

    void find(int key)
    {
        Node* temp = head;
        int f = 0;
        if (head == nullptr) {
            cout << "List is empty" << endl;
        }
        else {
            do {
                if (temp->data == key) {
                    cout << key << " Found" << endl;
                    f = 1;
                    break;
                }
                temp = temp->next;
            } while (temp != head);

            if (f == 0) {
                cout << key << " Not Found" << endl;
            }
        }
    }
};
int main()
{
    Search s;
    s.addNode(5);
    s.addNode(4);
    s.addNode(3);
    s.addNode(2);
    int key = 2;
    s.find(key);
    key = 6;
    s.find(key);

    return 0;
}