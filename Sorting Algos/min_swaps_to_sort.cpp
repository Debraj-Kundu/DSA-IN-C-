#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int minSwaps(vector<int> arr){
  int n = arr.size();
  int ans=0;
  vector<int> temp = arr;
  map<int, int> index;
  for(int i=0; i<n; i++){
    index[arr[i]] = i;
  }
  sort(begin(temp), end(temp));
  for(int i=0; i<n; i++){
    if(temp[i] != arr[i]){
      ans++;
      int init = arr[i];
      swap(arr, i, index[temp[i]]);
      index[init] = index[temp[i]];
      index[temp[i]] = i;
    }
  }
  return ans;
}

int main(){

  vector<int> a = {101, 758, 315, 730, 472, 619, 460, 479};
  cout << minSwaps(a);

  return 0;
}