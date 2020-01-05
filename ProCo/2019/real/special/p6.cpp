#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {

  int N;
  cin >> N;
  vector <int> arr(N);

  for(int i=0;i<N;i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  int sum = 0, ans = 0;
  while(arr.size() != 1) {
    sum = (arr[0]+arr[1]);
    arr[0] = sum;
    arr.erase(arr.begin()+1);
    ans += sum;
  }

  cout << ans << endl;
  
}
