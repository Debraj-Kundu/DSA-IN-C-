#include <iostream>
using namespace std;

void rotate(int mat[][4]) { 
  int N = 4;
  // Consider all squares one by one 
  for (int i = 0; i < N / 2; i++) { 
    // Consider elements in group of 4 in 
    // current square 
    for (int j = i; j < N-i-1; j++) { 
      // store current cell in temp variable 
      int temp = mat[i][j]; 

      // move values from top-right to top-left
      mat[i][j] = mat[j][N-1-i]; 

      // move values from bottom-right to top-right 
      mat[j][N-1-i] = mat[N-1-i][N-1-j]; 

      // move values from bottom-left to bottom-right
      mat[N-1-i][N-1-j] = mat[N-1-j][i]; 

      // assign temp to bottom-left 
      mat[N-1-j][i] = temp; 
    } 
  } 
} 

int main(){

  int mat[4][4] = {
    1,  2,  3,  4, 
    5,  6,  7,  8,
    9,  10, 11, 12, 
    13, 14, 15, 16 
  };
  cout<<"Orignnal: \n";
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      cout << mat[i][j]<<' ';
    }
    cout<<endl;
  }
  rotate(mat);
  cout<<"Final: \n";
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      cout << mat[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}
