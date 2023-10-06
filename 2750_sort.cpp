#include <iostream>
#include <algorithm>
using namespace std;

int N;
int input[1001];
int main(){
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> input[i];
  }

  sort(input,input+N);

  for(int i=0; i<N; i++){
    cout << input[i] << "\n";
  }
}
