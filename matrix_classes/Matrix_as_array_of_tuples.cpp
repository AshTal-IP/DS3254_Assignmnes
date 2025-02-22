#include <iostream>

using namespace std;

template <class T>

class Matrix{
    private:
    // _arr is a pointer to an array of tuples
    // each tuple has 3 elements: row, column, and value
    // tuple<int, int, T> is a type
    // tuple<int, int, T>* is a pointer to an array of tuples
    // tuple is a template class from the standard library which can store multiple values of different types
    // tuple<int, int, T> is a tuple that stores 3 values: 2 integers and a value of type T which would be the value of the matrix at that position
        tuple<int, int, T>* _arr;
        int _capacity;
        int _size;

        void revise_capacity(int new_capacity){
            tuple<int, int, T>* new_arr = new tuple<int, int, T>[new_capacity];
            for (int i = 0; i < _size; i++){
                new_arr[i] = _arr[i];
            }
            delete [] _arr;
            _arr = new_arr;
            _capacity = new_capacity;
                
        }   

    public:

        Matrix(int capacity=1){
            _arr = new tuple<int, int, T>[capacity];
            _capacity = capacity;
            _size = 0;
        }

        ~Matrix(){
            delete [] _arr;
        }

        int length(){
            return _size;
        }

        void append(int row, int column, const T& x){
            if (_size == _capacity){
                revise_capacity(_capacity*2);
            }
            _arr[_size] = make_tuple(row, column, x);  // make_tuple is a function from the standard library that creates a tuple
            _size++;
        }

        T& valueAt(int row, int column){
            for (int i = 0; i < _size; i++){
                if (get<0>(_arr[i]) == row && get<1>(_arr[i]) == column){  // get<0> is a function from the standard library that gets the first element of a tuple
                    return get<2>(_arr[i]);
                }
            }
            throw "There's no element at that position";
        }

        void replaceAt(int row, int column, const T& x){
            for (int i = 0; i < _size; i++){
                if (get<0>(_arr[i]) == row && get<1>(_arr[i]) == column){
                    get<2>(_arr[i]) = x; // get<2> is a function from the standard library that gets the third element of a tuple, which is the value of the matrix at that position
                    return;
                }
            }
            throw "Such position doesn't exist";
        }

        void print(){
            for (int i = 0; i < _size; i++){
                cout << get<0>(_arr[i]) << " " << get<1>(_arr[i]) << " " << get<2>(_arr[i]) << endl;
            }
        }

};

int main(){
    Matrix<int> m(5);
    m.append(0, 0, 1);
    m.append(0, 1, 2);
    m.append(1, 0, 3);
    m.append(1, 1, 4);
    m.append(2, 2, 5);
    m.print();
    cout << m.valueAt(1, 1) << endl;
    m.replaceAt(1, 1, 6);
    m.print();
    return 0;
}

