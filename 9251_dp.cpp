#include <iostream>
#include <algorithm>
using namespace std;

string s1;
string s2;
int lcs[1001][1001];

void dp(int i, int j){
  // lcs 값 연산
  if (i == 0 || j == 0){
    lcs[i][j] = 0;
  }
  
  else if (s1[i-1] == s2[j-1]){
    lcs[i][j] = lcs[i-1][j-1] + 1;
  }

  else {
    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
  }

  //cout << lcs[i][j] << " ";
  
  // 다음 함수 호출
  if(j == s2.length()){
    if(i == s1.length()){
      cout << lcs[i][j];
      return;
    }
    
    //cout << "\n";
    dp(i+1,0);
  }
  else {
    dp(i, j+1);
  }
}

int main() {
  cin >> s1 >> s2;

  dp(0,0);
}
