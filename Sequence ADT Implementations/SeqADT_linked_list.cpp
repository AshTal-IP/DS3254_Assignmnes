#include <iostream>

using namespace std;

template <typename T>

class Linkedlist {
    private:
        class Node {
            public:
                T data;
                Node* next;
                
                Node(const T& d) : data(d) {
                    next = nullptr;
                };
        };
        
    
        Node* head;
        Node* tail;
        int size;

    public:
        Linkedlist() { 
            head =  nullptr;
            tail = nullptr;
            size=0;
        } // Constructor

        ~Linkedlist() { // Destructor
            Node* temp;
            while (head) {
                temp = head;
                head= head->next;
                delete temp;
            }
        }


        // Member functions

        void append(const T& value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        void prepend(const T& value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void remove(const T& value) {
            if (head == nullptr) {
                return;
            }
            if (head -> data == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                if (head == nullptr) { // If the list becomes empty
                    tail = nullptr;
                }
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr && temp->next->data != value) {
                temp = temp->next;
            }
            if (temp->next == nullptr) {
                return;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
            size--;
            if (temp->next == nullptr) {
                tail = temp;
            }
        }

        int lenght() {
            return size;
        }

        T& removeLast() {
            // if (head == nullptr) {
            //     cout<< "Empty list" <<endl;
            //     return -1;
            // }
            if (head == tail) {
                T& ret = head->data;
                delete head;
                head = tail = nullptr;
                size--;
                return ret;
            }
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            T& ret = tail->data;
            delete tail;
            tail = temp;
            size--;
            return ret;
        }

        T& removeFirst() {
            // if (head == nullptr) {
            //     cout << "Empty list" << endl;
            //     return -1;
            // }

            if (head == tail) {
                T& ret = head->data;
                delete head;
                head = tail = nullptr;
                size--;
                return ret;
            }
            T& ret = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return ret;
        }

        void insert(int index, const T& value) {
            if (index < 0 || index > size) {
                cout << "Invalid index" << endl;
                return;
            }
            if (index == 0) {
                prepend(value);
                return;
            }
            if (index == size) {
                append(value);
                return;
            }
            Node* newNode = new Node(value);
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }

        T& remove_index(int index) {
           
            if (index == 0) {
                return removeFirst();
            }
            if (index == size - 1) {
                return removeLast();
            }
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            T& ret = delNode->data;
            temp->next = delNode->next;
            delete delNode;
            size--;
            return ret;
        }

        void replace(int index, const T& value) {
            if (index < 0 || index >= size) {
                cout << "Invalid index" << endl;
                return;
            }
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->data = value;
        }


        // Implement elementAt function
        T& elementAt(int index) const {
            Node* temp = head;
            for (int i=0; i < index; i++) {
                temp = temp->next;
            }
            return temp->data;
        
        }

       


}
;

// End of class Linkedlist


int main(){
    Linkedlist<int> list;
    for (int i=0; i < 10; i++) {
        list.append(i^2);
    }
    for (int i=0; i < list.lenght(); i++) {
        cout << list.elementAt(i) << " ";
    }
    cout << endl;
    list.prepend(100);
    list.append(200);
    list.insert(5, 300);
    list.replace(3, 400);
    list.remove(2);
    list.removeFirst();
    list.removeLast();
    for (int i=0; i < list.lenght(); i++) {
        cout << list.elementAt(i) << " ";
    }


}