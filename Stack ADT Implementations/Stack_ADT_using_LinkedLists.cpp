#include <iostream>

using namespace std;

template <typename T>
class Stack{
    private:
        class Node{
            public:
                T data;
                Node* next;

                Node(const T& d): data(d){
                    next=nullptr;
                };
        };

        Node* top;
        int size;
        int capacity;

    public:
        Stack(int cap){
            top=nullptr;
            size=0;
            capacity=cap;
        }

        ~Stack(){
            Node* temp;
            while(top){
                temp=top;
                top=top->next;
                delete temp;
            }
        }

        void push( const T& value) {
            Node* newNode=new Node(value);
            if (top==nullptr){ 
                top = newNode;
                } else if (size==capacity){
                    cout<<"Stack is full"<<endl;
                    return;
                }
                
                
                else {
                    newNode->next=top;
                    top=newNode;
                }
            size++;
        }

        T& Top(){
            return top->data;
        }

        T& pop(){
            Node* temp=top;
            T& ret=top->data;
            top=top->next;
            delete temp;
            size--;
            return ret;
        }

        int Size(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }

        bool isFull(){
            return size==capacity;
        }	

    };

int main(){
    Stack<int> s(5);
    for (int i=0; i<5; i++){
        s.push(i);
    }
    cout<<s.Top()<<endl;
    cout<<s.pop()<<endl;

    for (int i=0; i<4; i++){
        cout<<s.pop()<<endl;
    }

    return 0;
}