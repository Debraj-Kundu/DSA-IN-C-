#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int n, int x){
  int l=0,r=n;
  while(l<r){
    int mid = l+(r-l)/2;
    if(x<=arr[mid]){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  return l;
}
int upperBound(int arr[], int n, int x){
  int l=0, r=n;
  while(l<r){
    int mid = l+(r-l)/2;
    if(x >= arr[mid]){
      l = mid+1;
    }else{
      r = mid;
    }
  }
  return l;
}
int main(){

  int arr[] = {1,1,2,2,2,2,3,3,4,5};
  int lb = lowerBound(arr, 10, 2);
  int ub = upperBound(arr, 10, 2);
  cout << lb << " " << ub;

  return 0;
}