#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long N;
char input[10];

int main(){
  cin >> N;
  string s = to_string(N);
  for (int i=0;i<s.size();i++){
    input[i] = s[i];
  }
  sort(input,input+s.size(), greater<int>());
  for (int i=0;i<s.size();i++){
    cout << input[i];
  }
}
