#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;



int main() {

  int a, b;
  cin >> a >> b;
  //int bsize = b*b*b;
  //int asize = a*a*a;
  int tmp = b/a;
  int ans = tmp*tmp*tmp;
  cout << ans << endl;

  
}
