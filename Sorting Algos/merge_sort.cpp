#include <iostream>
#include <cstring>
#define ll long long


class Array{
    ll int* arr;
    ll int size;
public:
    Array(){
        arr = new ll int[0];
        size=0;
    }
    Array(ll int n){
        size = n;
        arr = new ll int[size];
        for(ll int i=0; i<size; i++){
            std::cin >> arr[i];
        }
    }
    void merge_sort(){
        mergeSort(arr, 0, size-1);
    }
    void mergeSort(ll int* arr, int l, int r);
    void merge(ll int* ,int, int, int);
    void print(){
        for(ll int i=0; i<size; i++){
            std::cout << arr[i] << ' ';
        }
    }
};
void Array::merge(ll int* arr, int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i] = this->arr[i+l];
    }
    for(int i=0; i<n2; i++){
        R[i] = this->arr[mid+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            this->arr[k++] = L[i++];
        }
        else if(R[j]<L[i]){
            this->arr[k++] = R[j++];
        }
    }
    while (i<n1){
        this->arr[k++]=L[i++];
    }
    while (j<n2){
        this->arr[k++]=R[j++];
    } 
}
void Array::mergeSort(ll int* arr, int l, int r){
  if(l<r){
    int mid = l+(r-l)/2;
    mergeSort(this->arr, l, mid);
    mergeSort(this->arr,mid+1,r);
    merge(this->arr, l, mid, r);
  }
}
int main()
{
    int n;
    std::cin >> n;
    Array arr(n);
    arr.merge_sort();
    arr.print();

   return 0;
}