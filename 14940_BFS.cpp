#include <iostream>
#include <queue>`
using namespace std;

int n,m;
int map[1001][1001];
bool is_visited[1001][1001] = {0,};
pair<int,int> goal_spot;

void get_distance(int i, int j){
  queue<pair<int,int>> q;
  is_visited[i][j] = 1;
  q.push({i,j});

  while(!q.empty()){
    pair<int,int> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    
    // 다음 지점이 범위 내에 존재하고, 방문한 적이 없고, 0이 아니라면 방문
    if(x+1 < n && is_visited[x+1][y] == 0 && map[x+1][y] != 0){
      is_visited[x+1][y] = 1;
      q.push({x+1,y});
      map[x+1][y] = map[x][y]+1;
    }
    if (x-1 >= 0 && is_visited[x-1][y] == 0 && map[x-1][y] != 0){
      is_visited[x-1][y] = 1;
      q.push({x-1,y});
      map[x-1][y] = map[x][y]+1;
    }
    if (y+1 < m && is_visited[x][y+1] == 0 && map[x][y+1] != 0){
      is_visited[x][y+1] = 1;
      q.push({x,y+1});
      map[x][y+1] = map[x][y]+1;
    }
    if (y-1 >= 0 && is_visited[x][y-1] == 0 && map[x][y-1] != 0){
      is_visited[x][y-1] = 1;
      q.push({x,y-1});
      map[x][y-1] = map[x][y]+1;
    }
  }
}
    
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> map[i][j];
      if (map[i][j] == 2){
        goal_spot = {i,j};
        map[i][j] = 0;
      }
    }
  }

  get_distance(goal_spot.first, goal_spot.second);

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(is_visited[i][j] == 0 && map[i][j] == 1){
        map[i][j] = -1;
      }
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}
