#include <bits/stdc++.h>
using namespace std;

int smallestNumber(int n){ 
  if(n>=0&&n<=9)
    return n;
  stack<int> digits;
  for(int i=9; i>=2 && n>1; i--){
    while (n%i==0){
      digits.push(i);
      n = n/i;
    }
  }
  if(n != 1)
    return -1;
  int res=0;
  while(!digits.empty()){
    res = res*10+digits.top();
    digits.pop();
  }
  return res;
}

int main(){

  int n = 100; 
  cout << smallestNumber(n);

  return 0;
}