#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;



int main() {

  vector <int> arr;
  string S;
  int N;
  cin >> N;
  cin >> S;
  int count =0;
  for(int i=0;i<S.length();i++) {
    if(S[i] == '1' && S[i+1] == '0')
      count ++;
  }

  cout << count << endl;
  
}
