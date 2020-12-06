#include <iostream>
using namespace std;

int findEle(int* arr, int n){
  int idx = 0;
  for(int i=0; i<n; i++){
    if(arr[i] > 0){
      swap(arr[idx++], arr[i]);
    }
  }
  for(int i=0; i<idx; i++){
    if(arr[abs(arr[i])-1] > 0 && abs(arr[i])-1 < n){
      arr[abs(arr[i])-1] = -1* arr[abs(arr[i])-1];
    }
  }
  for(int i=0; i<idx; i++){
    if(arr[i] > 0){
      return i+1;
    }
  }
  return n+1;
}

int main(){

  int arr[] = {0,-10,1,3,-20};
  cout << findEle(arr, 5);

  return 0;
}