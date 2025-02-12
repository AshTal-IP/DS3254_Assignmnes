#include <iostream>

using namespace std;

class Matrix {
    private:
        int _rows;
        int _cols;
        int* _data;

    public:
     Matrix(int r, int c): _rows(r), _cols(c) {
         _data = new int[r*c];
     }

    ~Matrix() {
            delete [] _data;
        }

    int rows() const { return _rows; }
    int cols() const { return _cols; }

    int& operator()(const int i, const int j) const {
        return _data[i*_cols + j];
    }

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i=0; i < m._rows;i++){
            for (int j=0; j < m.cols(); j++){
                out << m(i,j) << " ";
            }
            out << endl;
        }
        return out;
    }

};



int main(){
    Matrix m(3,3);
    for (int i=0; i < m.rows(); i++){
        for (int j=0; j < m.cols(); j++){
            m(i,j) = i+j+1;
        }
    }
    cout << m;
    return 0;
}