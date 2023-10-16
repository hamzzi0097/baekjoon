#include <iostream>
using namespace std;

int hour, minute;
int time_required;

int main() {
  cin >> hour >> minute >> time_required;
  minute += time_required;

 while (minute >= 60) {
    minute-=60;
    hour+=1;
 }
  if (hour >= 24) 
    hour -= 24;
  cout << hour << " " << minute;
}
