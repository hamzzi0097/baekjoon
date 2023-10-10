#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num = 666;
int cnt = 0;

int main(){
  cin >> N;
  while(1){
    int tmp=num;
    // 현재 숫자가 죽음의 수인지 확인하기
    while(1){
      // 마지막 3자리가 666인지 확인, 맞다면 cnt++
      if (tmp%1000 == 666){
        cnt++;
        break;
      }

      // 아니라면 마지막 자리 버림
      tmp/=10;

      // 666보다 작다면 break
      if (tmp<666) break;
    }

    // 찾고자하면 N번째 수가 맞다면 break
    if (cnt == N){
      cout << num;
      break;
    }

    // 아니라면 다음 수 탐색
    num++;
  }
}
