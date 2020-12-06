#include <bits/stdc++.h>
using namespace std;

void reArrange(int arr[], int n){
  for(int i=0; i<n; i++){
    arr[i] += (arr[arr[i]]%n)*n;
  }
  for(int i=0; i<n; i++){
    cout << arr[i] << ' ';
  }
  cout<<endl;
  for(int i=0; i<n; i++){
    arr[i] /= n;
  }
}

int main(){

  int arr[] = {4,0,2,1,3};
             //19 20 12 1 8 
  int n = sizeof(arr)/sizeof(arr[0]); 

  reArrange(arr, n);

  for(int i=0; i<n; i++){
    cout << arr[i] << ' ';
  }

  return 0;
}