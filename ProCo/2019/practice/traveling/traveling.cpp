#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  int x;
  cin >> N;
  vector < vector <int> > gr(3);
  for(int i=0;i<3;i++) {
    for(int j=0;j<N;j++) {
      cin >> x;
      gr[i].push_back(x);
    }
  }

  for(int i=0;i<N-1;i++) {
    if(!( ((gr[0][i] == 0) && (gr[0][i+1] == 0)) || ((gr[1][i] == 0) && (gr[1][i+1] == 0)) || ((gr[2][i] == 0) && (gr[2][i+1] == 0)) )) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  
}
