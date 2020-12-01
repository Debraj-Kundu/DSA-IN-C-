#include <bits/stdc++.h> 
using namespace std; 

int partition(int arr[], int l, int r) 
{ 
	int pivot = arr[r], i=l;
  for(int j=l; j<=r-1; j++){
    if(arr[j] <= pivot){
      swap(arr[i++], arr[j]);
    }
  }
  std::swap(arr[i], arr[r]);
  return i;
} 

int kthSmallest(int arr[], int l, int r, int k) 
{ 
	if(k>0 && k<=r-l+1){
    int pi = partition(arr, l, r);
    if(pi-l == k-1)
      return arr[pi];
    if(pi-l > k-1)
      return kthSmallest(arr, l, pi-1, k);
    return kthSmallest(arr, pi+1, r, k+l-1-pi);
  }
	return INT_MAX; 
} 

int main() 
{ 
	int arr[] = { 7,10,4,3,20,15 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	cout << "K-th smallest element is "
		<< kthSmallest(arr, 0, n - 1, k); 
	return 0; 
} 
