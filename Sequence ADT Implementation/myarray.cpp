#include <iostream>

using namespace std;

class MyArray {
  private:
    int* _arr;
    int _capacity;
    int _size;

  public:
    MyArray(int capacity) {
      _arr = new int[capacity]; // Allocate an array of given capacity
      _capacity = capacity;
      _size = 0;
    }

    ~MyArray() {
      delete [] _arr;  // Free allocated memory
    }

    int length() {
      return _size;
    }

    int elementAt(int i) {
      if (i < 0 || i>=_size ){
        cout << "Index out of bounds" << endl;
        return -1;
      }
      return _arr[i];
    }

    void replace(int i, int x) {
      _arr[i] = x;
    }

 
   void append(int x) {
    _arr[_size] = x;
    _size++;
    }

    int removeLast() {
      int ret = _arr[_size - 1];
      _size--;
      return ret;
    }

    void insert(int i, int x) {
      if (i < 0 || i>=_size ){
        cout << "Index out of bounds" << endl;
        return;
      }
       for (int j = _size; j >i; j--){
        _arr[j]=_arr[j-1];

       }
       _arr[i]=x;
       _size++;

    }

    int remove(int i) {
      if (i < 0 || i>=_size ){
        cout << "Index out of bounds" << endl;
        return -1;
      }
      int ret = _arr[i];
      for (int j = i; j < _size-1; j++){
        _arr[j]=_arr[j+1];
      }
      _size--;
      return ret;
    }
    void insert(int i, int x) {
      if (i < 0 || i>=_size ){
        cout << "Index out of bounds" << endl;
        return;
      }
       for (int j = _size; j >i; j--){
        _arr[j]=_arr[j-1];

       }
       _arr[i]=x;
       _size++;
    }

    int remove(int i) {
      if (i < 0 || i>=_size ){
        cout << "Index out of bounds" << endl;
        return -1;
      }
      int ret = _arr[i];
      for (int j = i; j < _size-1; j++){
        _arr[j]=_arr[j+1];
      }
      _size--;
      return ret;
    }
};

int main() {
  MyArray arr(50);
  for(int i = 0; i < 10; i++) {
    arr.append(2*i);
  }

  for(int i = 0; i < 10; i++) {
    cout << arr.elementAt(i) << " ";
  }

  
  cout << endl;
  cout << arr.length() << endl;
  cout << arr.elementAt(9) << endl;

  cout << arr.removeLast() << endl;
  cout << arr.elementAt(9) << endl;
  cout << arr.length() << endl;
}
