#include <iostream>

using namespace std;

template <typename T>
class Queue {
    private:
        class Node {
            public:
                T data;
                Node* next;
                
                Node(const T& d) : data(d) {
                    next = nullptr;
                };
        };
        
    
        Node* front;
        Node* rear;
        int size;
        int capacity;

    public:
        Queue( int cap) { 
            front =  nullptr;
            rear = nullptr;
            size=0;
            capacity=cap;
        } // Constructor

        ~Queue() { // Destructor
            Node* temp;
            while (front) {
                temp = front;
                front= front->next;
                delete temp;
            }
        }

        void enqueue(const T& value) {
            Node* newNode = new Node(value);
            if (front == nullptr) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        T first() {
            return front->data;
        }

        T& dequeue() {
            Node* temp = front;
            T& ret = temp->data;
            front = front->next;
            delete temp;
            size--;
            return ret;
        }

        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == capacity;
        }
};

int main() {
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}