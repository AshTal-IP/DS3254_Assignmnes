#include <iostream>

using namespace std;

template <class T>
class MyArray {
  private:
    T* _arr;
    int _capacity;
    int _size;

  public:
    MyArray(int capacity) {
      _arr = new T[capacity];
      _capacity = capacity;
      _size = 0;
    }

    ~MyArray() {
      delete [] _arr;
    }

    int length() {
      return _size;
    }

    T& elementAt(int i) {
      return _arr[i];
    }

    void replace(int i, const T& x) {
      _arr[i] = x;
    }

    void append(const T& x) {
      _arr[_size] = x;
      _size++;
    }

    T& removeLast() {
      T& ret = _arr[_size - 1];
      _size--;
      return ret;
    }

    // void insert(int i, T& x) {
    // }

    void insert(int i, const T& x) {
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

    T& remove(int i) {
      T& ret = _arr[i];
      for (int j = i; j < _size-1; j++){
        _arr[j]=_arr[j+1];
      }
      _size--;
      return ret;
    }

    // T remove(int i) {
    // }
};

int main() {
  MyArray<int> arr(50);
  for(int i = 0; i < 10; i++) {
    arr.append(2*i);
  }

  // int x = arr.elementAt(0);
  int& x = arr.elementAt(0);
  x += 3;

  for(int i = 0; i < 10; i++) {
    cout << arr.elementAt(i) << " ";
  }
  cout << endl;
  return 0;
}
