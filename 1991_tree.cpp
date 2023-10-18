#include <iostream>
using namespace std;

int N;
pair<int,int> tree[26];

// 전위순회
void preorder(int i){
  if (i == -1)
    return;

  cout << (char)(i+'A');
  preorder(tree[i].first);
  preorder(tree[i].second);
}

// 중위순회
void inorder(int i) {
  if (i == -1)
    return;
  
  inorder(tree[i].first);
  cout << (char)(i+'A');
  inorder(tree[i].second);
}

// 후위순회
void postorder(int i) {
  if (i == -1)
    return;
  
  postorder(tree[i].first);
  postorder(tree[i].second);
  cout << (char)(i+'A');
}

int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    char a,b,c;
    cin >> a >> b >> c;

    // 비어있는 노드는 -1로 처리
    if (b == '.')
      tree[a-'A'].first = -1;
    else
      tree[a-'A'].first = b-'A';

    if (c == '.')  
      tree[a-'A'].second = -1;
    else 
      tree[a-'A'].second = c-'A';
  }

  preorder(0);
  cout << "\n";
  inorder(0);
  cout << "\n";
  postorder(0);
}
