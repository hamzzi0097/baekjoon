#include <iostream>
#include <algorithm>
using namespace std;

int N,k;
int arr[1001];

int main(){
  cin >> N >> k;
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }

  sort(arr,arr+N,greater<>());

  cout << arr[k-1];
}
