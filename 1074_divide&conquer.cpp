#include <iostream>
#include <cmath>
using namespace std;

int N,r,c;
int ans = 0;

void Z(int x, int y, int size){
    if (x == c && y == r){
        cout << ans;
        return;
    }
    else if (c<x+size && c>=x && r<y+size && r>=y){
        Z(x,y,size/2);
        Z(x+size/2,y,size/2);
        Z(x,y+size/2,size/2);
        Z(x+size/2,y+size/2,size/2);
    }
    else {
        ans += size*size;
    }
}

int main() {
    cin >> N >> r >> c;
    Z(0,0,pow(2,N));
}
