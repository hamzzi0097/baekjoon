#include <iostream>
using namespace std;

bool isFirst = true;
int N;
int num[12];
int oper[4];
int min_val=0;
int max_val=0;

void calAns(int result, int cnt){
  // 연산 횟수가 연산자 수(N-1)과 같아지면 종료
  if (cnt == N-1){
    if (isFirst){
      min_val = result;
      max_val = result;
      isFirst = false;
    }
    else {
      if (min_val > result) min_val = result;
      if (max_val < result) max_val = result;
    }
    return;
  }
  
  // 각 연산자마다 연산 횟수가 남아있으면 연산 진행, 다음 함수에 결괏값 넘기기
  if (oper[0]>0){
    oper[0]--;
    calAns(result+num[cnt+1], cnt+1);
    oper[0]++;
  }
  if(oper[1]>0){
    oper[1]--;
    calAns(result-num[cnt+1], cnt+1);
    oper[1]++;
  }
  if(oper[2]>0){
    oper[2]--;
    calAns(result*num[cnt+1], cnt+1);
    oper[2]++;
  }
  if(oper[3]>0){
    oper[3]--;
    calAns(result/num[cnt+1], cnt+1);
    oper[3]++;
  }
}

int main(){
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> num[i];
  }
  for(int i=0; i<4; i++){
    cin >> oper[i];
  }

  calAns(num[0], 0);
  cout << max_val << "\n" << min_val;
}
