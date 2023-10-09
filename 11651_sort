#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> coord[100001];

bool comp(pair<int,int> p1, pair<int,int> p2){
  if (p1.second < p2.second) return true;
  else if (p1.second > p2.second) return false;
  else {
    if (p1.first < p2.first) return true;
    else return false;
  }
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> coord[i].first >> coord[i].second;
  }

  sort(coord, coord+N, comp);

  for (int i=0; i<N; i++)
  {
    cout << coord[i].first << " " << coord[i].second << "\n";    
  }
}
