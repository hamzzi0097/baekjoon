#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];
int avg=0;

int main(){
  for(int i=0; i<5; i++){
    cin >> arr[i];
    avg += arr[i];
  }

  avg /= 5;
  sort(arr, arr+5);

  cout << avg << "\n" << arr[2];
}
