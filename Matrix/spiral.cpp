#include <iostream>
using namespace std;

void spiral(int mat[5][4]){
  int m=5, n=4;
  int sri=0,eri=0,sci,eci,itr;
  while(sri<m&&eri<n){
    for (int i=sri; i<n; i++)
        cout<<mat[sri][i]<<' ' ;
    sri++;
    for (int i = sri; i<m; i++)
        cout<<mat[i][n-1]<<' ';  
    n--;
    if(sri<m){
      for(int i = n-1; i >= eri; --i)   
        cout<<mat[m-1][i]<<' ';
      m--;
    }

    if(eri<n){
      for (int i = m-1; i >= sri; i--)   
        cout<<mat[i][eri]<<' ';  
      eri++;
    }
  }
}


int main(){

  int mat[5][4] = {
    1,  2,  3,  4, 
    5,  6,  7,  8,
    9,  10, 11, 12, 
    13, 14, 15, 16,
    17, 18, 19, 20
  };
  cout<<"Spiral: \n";
  spiral(mat);
  /*for(int i=0; i<5; i++){
    for(int j=0; j<4; j++){
      cout << mat[i][j]<<' ';
    }
    cout<<endl;
  }*/

  return 0;
}