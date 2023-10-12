#include <iostream>
using namespace std;

int N;
pair<int,int> p[50];

int main(){
  cin >> N;
  for (int i=0;i<N;i++){
    cin >> p[i].first >> p[i].second;
  }

  for (int i=0;i<N;i++){
    int rank_cnt=1;
    for (int j=0;j<N;j++){
      if (i==j) continue;
      if (p[i].first < p[j].first && p[i].second < p[j].second) rank_cnt++;
    }
    cout << rank_cnt << " ";
  }
}
