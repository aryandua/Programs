#include <iostream>

using namespace std;

int abs(int x) {
  if(x<0)
    return x*-1;
  return x;
}

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  if( (abs(y2-y1) + abs(x2-x1)) % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
}
