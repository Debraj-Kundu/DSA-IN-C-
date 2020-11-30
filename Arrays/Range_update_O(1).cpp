#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, q;
  cin>>n>>q;
  vector<int> vec(n, 0); 
  while(q--){
    int l, r;
    cin>>l>>r;
    vec[l]++;
    if(r+1<n) vec[r+1]--;
  }
  //prefix array
  for(int i=1; i<n; i++){
    vec[i] = vec[i-1]+vec[i];
  }
  for(auto x:vec){
    cout<<x<<' ';
  }

  return 0;
}