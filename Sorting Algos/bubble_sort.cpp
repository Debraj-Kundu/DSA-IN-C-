#include <iostream>
#include <cstring>
#define ll long long

class Array{
    ll int arr[10000];
    ll int size;
public:
    Array(){
        memset(arr, 0, 0);
        size=0;
    }
    Array(ll int n){
        size = n;
        for(ll int i=0; i<size; i++){
            std::cin >> arr[i];
        }
    }
    void bubble_sort(){
        int i,j;
        for(i=0; i<size-1; i++){
            for(j=0; j<size-i-1; j++){
                if(arr[j] > arr[j+1]){
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    void bubble_sort(bool rev){
        if(rev){
            int i,j;
            for(i=0; i<size-1; i++){
                for(j=0; j<size-i-1; j++){
                    if(arr[j] < arr[j+1]){
                        std::swap(arr[j], arr[j+1]);
                    }
                }
            }
        }
        else{
            ll int i,j;
            for(i=0; i<size-1; i++){
                for(j=0; j<size-i-1; j++){
                    if(arr[j] > arr[j+1]){
                        std::swap(arr[j], arr[j+1]);
                    }
                }
            }
        }
    }
    void print(){
        for(ll int i=0; i<size; i++){
            std::cout << arr[i] << ' ';
        }
    }
};

int main()
{
    int n;
    std::cin >> n;
    Array arr(n);
    arr.bubble_sort();
    arr.print();

   return 0;
}
