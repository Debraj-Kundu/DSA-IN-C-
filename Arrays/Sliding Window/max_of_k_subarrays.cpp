#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSubarrayElement(int *arr, int n, int k){
  deque<pair<int, int>> dq;//(value, index)
    vector<int> ans;
    for(int i=0; i<n; i++){
      if(!dq.empty() && dq.front().second <= (i-k)) // if it is inside window or not
        dq.pop_front();
      while(!dq.empty() && dq.back().first < arr[i]) // maintaining desc order
        dq.pop_back();
      dq.push_back(make_pair(arr[i], i));
      if(i>=(k-1)) //poping when gets out of the window
        ans.push_back(dq.front().first);
    }
    return ans;
}

int main(){

  int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
  int k=4;
  vector<int> ans =  maxSubarrayElement(arr, 10, k);
  for(auto x:ans)
    cout << x << " ";

  return 0;
}