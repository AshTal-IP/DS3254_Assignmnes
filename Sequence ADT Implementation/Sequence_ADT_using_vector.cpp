#include <iostream>

using namespace std;

template <class T>
class Vector{
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

        Vector(int capacity=1){
            _arr = new T[capacity];
            _capacity = capacity;
            _size = 0;
        }

        ~Vector(){
            delete [] _arr;
        }

        int length(){
            return _size;
        }

        void append(const T& x){
            if (_size == _capacity){
                revise_capacity(_capacity*2);
            }
            _arr[_size] = x;
            _size++;
        }

        T& removeLast(){
            T& ret=_arr[_size-1];
            _size--;
            if (_size <= _capacity/4){
                revise_capacity(_capacity/2);
            }
            return ret;
        }
        
        T& elementAt(int i){
            return _arr[i];
        }

        void replaceAt(int i, const T& x){
            _arr[i] = x;
        }

        void insertAt(int i, const T& x){
            if (_size == _capacity){
                revise_capacity(_capacity*2);
            }
            for (int j = _size; j > i; j--){
                _arr[j] = _arr[j-1];
            }
            _arr[i] = x;
            _size++;
        }

        void remove(int i){
            for (int j = i; j < _size-1; j++){
                _arr[j] = _arr[j+1];
            }
            _size--;
            if (_size <= _capacity/4){
                revise_capacity(_capacity/2);
            }
        }

    


};

int main(){
    Vector<int> v(1);
    for (int i = 0; i < 10; i++){
        v.append(i);
    }
    for (int i = 0; i < v.length(); i++){
        cout << v.elementAt(i) << " ";
    }
    v.remove(3);
    v.insertAt(3, 100);
    v.replaceAt(3, 110);
    cout << endl;
    for (int i = 0; i < v.length(); i++){
        cout << v.elementAt(i) << " ";
    }
}