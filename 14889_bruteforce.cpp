#include <iostream>
#include <vector>
using namespace std;

int N;
int stat[20][20];
// 값의 차의 최댓값이 2000정도로 보여 그 이상의 값으로 설정
int min_val=10000;

// 각 팀의 index 정보를 담음
vector<int> a_team;
vector<int> b_team;

// 각 팀의 stat 합
int a_stat=0;
int b_stat=0;

void build_team(int seq){
  // 2팀의 스탯 차 출력 후, 종료
  if (seq == N){
    int diff = a_stat-b_stat;
    if (diff < 0) diff*=-1;
    if (min_val > diff) min_val = diff;
    //cout << diff << "\n";
    return;
  }

  // seq에 해당하는 인원을 a팀, b팀에 넣을 경우를 계산
  if (a_team.size() < N/2){
    int total=0;
    for (int i=0; i<a_team.size(); i++){
      total+=(stat[a_team[i]][seq]+stat[seq][a_team[i]]);
    }
    a_team.push_back(seq);
    a_stat+=total;
    build_team(seq+1);
    a_team.pop_back();
    a_stat-=total;
  }
  if (b_team.size() < N/2){
    int total=0;
    for(int i=0; i<b_team.size(); i++){
      total+=(stat[b_team[i]][seq]+stat[seq][b_team[i]]);
    }
    b_team.push_back(seq);
    b_stat+=total;
    build_team(seq+1);
    b_team.pop_back();
    b_stat-=total;
  }
}

int main(){
  cin >> N;
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      cin >> stat[i][j];
    }
  }

  build_team(0);

  //cout << a_team.size() << " " << b_team.size() << " " << b_stat << " " << a_stat;

  cout << min_val;
}
