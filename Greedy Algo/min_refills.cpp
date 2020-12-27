#include <iostream>
using namespace std;

int minRefills(int targetDist, int limit, int gas_station[], int n){
  int numRefills=0, currRefills=0;
  int distCovered = limit;
  while(distCovered < targetDist){
    if(currRefills >= n || gas_station[currRefills] > distCovered){
      return -1;
    }
    while(currRefills < n-1 && (gas_station[currRefills+1]) <= distCovered){
      currRefills++;
    }
    numRefills++;
    distCovered = gas_station[currRefills]+limit;
    currRefills++;
  }
  return numRefills;
}

int main(){

  int arr[] = {200, 375, 550, 750};
  cout << minRefills(950, 400, arr, 4);

  return 0;
}