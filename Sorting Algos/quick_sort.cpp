#include <iostream>
#include <cstring>
#include <algorithm>
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
    void quick_sort(){
        quickSort(arr, 0, size-1);
    }
    void quick_sort(bool rev){
        quickSort(arr, 0, size-1);
        if(rev){
            int l=0, r=size-1;
            while(l<r){
                std::swap(arr[l], arr[r]);
                l++;
                r--;
            }
        }
    }
    void print(){
        for(ll int i=0; i<size; i++){
            std::cout << arr[i] << ' ';
        }
    }
};

int Array::partition(ll int* arr, int l, int r)
{
    ll int pivot = arr[r];
    ll int i = l-1;
    for(ll int j=l; j<r; j++)
    {
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[r]);
    return i+1;
}

void Array::quickSort(ll int* arr, int l, int r)
{
    if(l<r){
        int mid = l+(r-l)/2;
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main()
{
    int n;
    std::cin >> n;
    Array arr(n);
    arr.quick_sort();
    arr.print();

   return 0;
}
