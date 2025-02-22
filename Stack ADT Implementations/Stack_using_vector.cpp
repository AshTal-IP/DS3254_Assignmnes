#include <iostream>

using namespace std;

template <class T>
class Stack {
    private:
        T* _arr;
        int _capacity;
        int _size;

        void revise_capacity(int new_capacity){
            T* new_arr = new T[new_capacity];
            for (int i = 0; i < _size; i++){
                new_arr[i] = _arr[i];
            }
            delete [] _arr;
            _arr = new_arr;
            _capacity = new_capacity;
                
        }

        public:

        Stack(int capacity=1){
            _arr = new T[capacity];
            _capacity = capacity;
            _size = 0;
        }

        ~Stack(){
            delete [] _arr;
        }

        int length(){
            return _size;
        }

        void push(const T& x){
            if (_size == _capacity){
                revise_capacity(_capacity*2);
            }
            _arr[_size] = x;
            _size++;
        }

        T& pop(){
            T& ret=_arr[_size-1];
            _size--;
            if (_size <= _capacity/4){
                revise_capacity(_capacity/2);
            }
            return ret;
        }

        T& top(){
            return _arr[_size-1];
        }

        bool isEmpty(){
            return _size == 0;
        }


        bool isFull(){
            return _size == _capacity;
        }
};

int main(){
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.length() << endl;
    cout << s.pop() << endl;
    cout << s.length() << endl;
    cout << s.top() << endl;

    return 0;

}