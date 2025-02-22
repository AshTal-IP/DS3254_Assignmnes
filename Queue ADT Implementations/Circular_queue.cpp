#include <iostream>

using namespace std;

template <class T>
class CircularQueue {
    private:
        T* _arr;
        int _capacity;
        int _size;
        int _front;
        int _rear;

       


        public:

        CircularQueue(int capacity){
            _arr = new T[capacity];
            _capacity = capacity+1;
            _size = 0;
            _front = 0;
            _rear = 0;
        }

        ~CircularQueue(){
            delete [] _arr;
        }
        
        bool isFull(){
            return (_rear+1)%_capacity == _front;
        }

        bool isEmpty(){
            return _front == _rear;
        }

        private:
        
        void revise_capacity(int new_capacity){
            T* new_arr = new T[new_capacity];
            for (int i = 0; i < _size; i++){
                new_arr[i] = _arr[(_front+i)%_capacity];
            }
            delete [] _arr;
            _arr = new_arr;
            _capacity = new_capacity;
            _front = 0;
            _rear = _size;
        }

        public:

        void enqueue(const T& x){
            if (isFull()){
                revise_capacity(_capacity*2);
            }
            _arr[_rear] = x;
            _rear = (_rear+1)%_capacity;
            _size++;
        }

        T& dequeue(){
            if (isEmpty()){
                throw "Queue is empty";
                
            }

            T& ret = _arr[_front];
            _front = (_front+1)%_capacity;
            _size--;
            if (_size <= _capacity/4){
                revise_capacity(_capacity/2);
            }
            return ret;
        }

        T& first(){
            if (isEmpty()){
                throw "Queue is empty";
            }
            return _arr[_front];
        }

        T& last(){
            if (isEmpty()){
                throw "Queue is empty";
            }
            return _arr[(_rear-1+_capacity)%_capacity];
        }

        int length(){
            return _size;
        }

};

int main(){
    CircularQueue<int> q(5);
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
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    return 0;
}