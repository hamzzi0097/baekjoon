#include <iostream>
using namespace std;

int N, M;
int total=0;
int arr[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  for(int i=1;i<=N;i++){
    int a;
    cin >> a;
    total+=a;
    arr[i]=total;
  }

  int a,b;
  for(int i=0;i<M;i++){
    cin >> a >> b;
    
    cout << arr[b]-arr[a-1] << "\n";
  }
}
