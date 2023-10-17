#include <iostream>
#include <string>
using namespace std;

int left_cnt=0;
int alpabet_cnt[26]={0,};
string left_alpabet;
string name;
string pelindrom="";

int main() {
  cin >> name;
  
  for (int i=0; i<name.size(); i++){
    char c = name[i];
    string s;
    s+=c;
    if (alpabet_cnt[c-'A'] == 1){
      alpabet_cnt[c-'A'] = 0;   

      int input_pos=0;
      if (!pelindrom.empty()){
        for (int j=0; j<pelindrom.size()/2; j++){
          if(pelindrom[j]<c)
            input_pos++;
          else 
            break;
        } 
      }
      pelindrom.insert(input_pos, s);
      pelindrom.insert(pelindrom.size()-input_pos, s);
    }
    else {
      alpabet_cnt[c-'A']++;
    }
  }

  for (int i=0;i<26;i++){
    if(alpabet_cnt[i] > 0){
      left_cnt++;
      left_alpabet += i+'A';
    }

  }

  if (left_cnt == 0){
    //cout << "짝수\n";
    cout << pelindrom;
  }
  else if(left_cnt == 1){
    //cout << "홀수\n";
    pelindrom.insert(pelindrom.size()/2, left_alpabet);
    cout << pelindrom;
  }
  else {
    cout << "I'm Sorry Hansoo";
  }
}
