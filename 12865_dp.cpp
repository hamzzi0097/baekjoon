#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int dp[100001][101];

// first == weight, second == value
pair<int,int> stuff[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> K;

  for(int i=1;i<=N;i++){
    cin >> stuff[i].first >> stuff[i].second;
  }

  // dp를 이용해 최대 가치 구하기
  for(int limit=1;limit<=K;limit++){
    for(int index=1;index<=N;index++){
      if(limit >= stuff[index].first){
        dp[limit][index] = max(dp[limit-stuff[index].first][index-1]+stuff[index].second, dp[limit][index-1]);
      }
      else {
        dp[limit][index] = dp[limit][index-1];
      }
      
      cout << dp[limit][index] << " ";
    }
    cout << "\n";
  }

  cout << dp[K][N];
}
