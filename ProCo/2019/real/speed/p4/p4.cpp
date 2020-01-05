#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int posx=0;
int posy=0;
int dir=0; //North - 0, East - 1, South - 2, West - 3

vector <int> posat;
string steps;

inline void getpos() {
  posx = 0;
  posy = 0;
  dir = 0;
  for(int i=0;i<steps.length();i++) {
    if(steps[i] == 'F' && dir  == 0)
      posy++;
    else if(steps[i] == 'B' && dir == 0)
      posy--;
    
    else if(steps[i] == 'F' && dir == 1)
      posx++;
    else if(steps[i] == 'B' && dir == 1)
      posx--;

    else if(steps[i] == 'F' && dir == 2)
      posy--;
    else if(steps[i] == 'B' && dir == 2)
      posy++;

    else if(steps[i] == 'F' && dir == 3)
      posx--;
    else if(steps[i] == 'B' && dir==3)
      posx++;


    else if(steps[i] == 'L') {
      dir--;
      if(dir == -1)
	dir = 3;
    }

    else if(steps[i] == 'R') {
      dir++;
      if(dir == 4)
	dir = 0;
    }

    else
      return;

    posat[i] = dir;

  }
}


int main() {

  int n, x, y;
  char D;
  int d1;
  
  
  cin >> n >> x >> y >> D;

  if(D == 'N')
    d1 = 0;
  if(D=='E')
    d1 = 1;
  if(D=='S')
    d1 = 2;
  if(D=='W')
    d1 = 3;
  cin >> steps;
  posat.resize(n);
  getpos();
  if((posx == x) && (posy == y) && (dir == d1)) {
    cout << 0 << endl;
    return 0;
  }

  for(int i=0;i<n;i++) {
    
    if(steps[i] == 'F') {
      steps[i] = 'B';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " B" << endl;
	return 0;
      }

      steps[i] = 'L';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " L" << endl;
	return 0;
      }
      
      steps[i] = 'R';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " R" << endl;
	return 0;
      }
      steps[i] = 'F';
    }


    if(steps[i] == 'B') {
      steps[i] = 'F';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " F" << endl;
	return 0;
      }

      steps[i] = 'L';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " L" << endl;
	return 0;
      }
      
      steps[i] = 'R';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " R" << endl;
	return 0;
      }
      steps[i] = 'B';
    }
    
    
    if(steps[i] == 'L') {
      steps[i] = 'F';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " F" << endl;
	return 0;
      }
      
      steps[i] = 'B';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " B" << endl;
	return 0;
      }
      
      steps[i] = 'R';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " R" << endl;
	return 0;
      }
      steps[i] = 'L';
    }
    
  
    if(steps[i] == 'R') {
      steps[i] = 'F';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " F" << endl;
	return 0;
      }
      
      steps[i] = 'L';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " L" << endl;
	return 0;
      }
      
      steps[i] = 'B';
      getpos();
      if((posx == x) && (posy == y) && (dir == d1)) {
	cout << i+1 << " B" << endl;
	return 0;
      }
      steps[i] = 'R';
    }
  }
  cout << -1 << endl;
}
  

  
