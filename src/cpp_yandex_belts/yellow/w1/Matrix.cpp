// https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
  Matrix(): m({}) {}
  Matrix(int num_rows, int num_cols) {
    Reset(num_rows, num_cols);
  }

  void Reset(int num_rows, int num_cols) {
    if ( (num_rows < 0) | (num_cols < 0) )
      throw out_of_range("");

    rows = num_rows;
    cols = num_cols;

    m.resize(num_rows);
    for ( int i=0; i < num_rows; ++i ) {
      m.at(i).resize(num_cols);
      for ( int j=0; j < num_cols; ++j ) {
        m[i][j] = 0;
      }
    }
  }

  int GetNumRows() const {
    return rows;
  }

  int GetNumColumns() const {
    return cols;
  }

  vector<int> GetSize() const {
    return {rows, cols};
  }

  // void CheckSize(int& rowIn, int& colIn) const {
  //   int row = this->GetNumRows();
  //   int col = this->GetNumColumns();
  //   if ( (rowIn != row) | (colIn != col) )
  //     throw out_of_range("");
  // }

  int At(int rowIn, int colIn) const {
    return m.at(rowIn).at(colIn);
  }

  int& At(int rowIn, int colIn) {
    return m.at(rowIn).at(colIn);
  }

private:
    vector<vector<int>> m;
    int rows = 0, cols = 0;
};

istream& operator>>(istream& stream, Matrix& m) {
  int row=0, col=0;
  stream >> row >> col;

  m.Reset(row, col);
  for ( int i=0; i < row; ++i ) {
    for ( int j=0; j < col; ++j ) {
      stream >> m.At(i, j);
    }
  }
  return stream;
}

ostream& operator<<(ostream& stream, const Matrix& m) {
  int row = m.GetNumRows(); 
  int col = m.GetNumColumns();
  stream << row << ' ' << col << '\n';

  for ( int i=0; i < row; ++i ) {
    for ( int j=0; j < col; ++j ) {
      stream << m.At(i, j) << ' ';
    }
    if ( i < (row - 1) )
      stream << '\n';
  }
  return stream;
}

bool operator==(const Matrix& l,  const Matrix& r) {
  vector<int> ls = l.GetSize();
  vector<int> rs = r.GetSize();

  if ( ((ls[0] == 0) && (rs[0] == 0)) | ((ls[1] == 0) && (rs[1] == 0)) 
     | ((ls[1] == 0) && (rs[0] == 0)) | ((ls[0] == 0) && (rs[1] == 0))) {
    return true;
  } 

  if ( (ls[0] == rs[0]) && (ls[1] == rs[1]) ) {
    for (int i=0; i < ls[0]; ++i) {
      for (int j=0; j < ls[1]; ++j) {
        if ( l.At(i, j) != r.At(i, j) )
          return false;
      }
    }
  } else {
    return false;
  }
  return true;

}

Matrix operator+(const Matrix l, const Matrix r) {
  vector<int> ls = l.GetSize();
  vector<int> rs = r.GetSize();
  Matrix sum;

  if ( ((ls[0] == 0) && (rs[0] == 0)) | ((ls[1] == 0) && (rs[1] == 0))
     | ((ls[1] == 0) && (rs[0] == 0)) | ((ls[0] == 0) && (rs[1] == 0)) ) {
    return sum;
  }

  sum.Reset(ls[0], ls[1]);
  if ( (ls[0] == rs[0]) && (ls[1] == rs[1]) ) {
    for (int i=0; i < ls[0]; ++i) {
      for (int j=0; j < ls[1]; ++j) {
        int& val = sum.At(i, j);
        val = l.At(i, j) + r.At(i, j);
      }
    }
  } else {
    throw invalid_argument("Matrices must be the same size: "+to_string(rs[0])+to_string(rs[1])+to_string(ls[0])+to_string(ls[1]));
  }
  return sum; 
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}