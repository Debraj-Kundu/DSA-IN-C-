#include<bits/stdc++.h>
using namespace std;

set<pair<float, float>> minGroups(float arr[], int n){
  int l=0, r=0;
  set<pair<float, float>> R;
  while(l<=n && r<=n){
    while(r <= n && (arr[r]-arr[l]) < 1){
      r++;
    }
    if((arr[r]-arr[l])>1){
      r--;
    }
    if(r>=n){
      r=n;
    }
    R.insert(make_pair(arr[l], arr[r]));
    l=r+1;
    r=l;
  }
  return R;
}

int main(){

  float arr[8]={3.0, 3.2, 3.8, 6.0, 6.8, 7.5, 9, 10.0};
  set<pair<float, float>>grps = minGroups(arr, 7);
  for(auto x:grps){
    if(x.first == x.second)
      cout << "["<<x.first << "]" << '\n';
    else
      cout << "["<<x.first << ", " << x.second<<"]" << '\n';
  }

  return 0;
}