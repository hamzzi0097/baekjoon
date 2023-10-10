#include <iostream>
using namespace std;

int N;
int num = 100;
int cnt = 0;

int main(){
  cin >> N;
  if (N < 100) cnt=N;
  else {
    int a,b,c;
    cnt = 99;
    while(1){
      // num이 한수인지 판단
      a = num/100;
      b = num%100/10;
      c = num%10;
      if (a-b==b-c) cnt++;
      
      // 다음 수가 N을 초과하면 break
      num++;
      if (num>N || num==1000) break;
    }
  }
  cout << cnt;
}
