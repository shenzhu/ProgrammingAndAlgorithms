/*
#include <iostream>
#include <cstring>
using namespace std;
*/

class Array2 {
 private:
  int** nums;
  int row;
  int col;
 public:
  Array2() {}

  Array2(int row, int col) : row(row), col(col) {
      nums = new int*[row];
      for (int i = 0; i < row; i++) {
          nums[i] = new int[col];
      }
  }

  Array2& operator=(Array2& rhs) {
      row = rhs.row;
      col = rhs.col;

      if (nums != NULL) {
          delete[] nums;
      }

      nums = new int*[row];
      for (int i = 0; i < row; i++) {
          nums[i] = new int[col];
      }

      for(int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
              nums[i][j] = rhs[i][j];
          }
      }

    return *this;
  }

  int* operator[](int i) {
      return nums[i];
  }

  int operator()(int i, int j) {
      return nums[i][j];
  }
};

/*

int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
*/