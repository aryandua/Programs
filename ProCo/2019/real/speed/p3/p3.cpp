#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

char mostFrequent(string text)
{
    int max=0;
    int count=0;
    char maxCharcter;
    for(char q=' ';q<='~';q++)
        
    {
        count = 0;
        for(int i=0; i<text.length();i++)
        {
            if(text[i]==q)
                count++;
        }
        
        if(count>max)
        {
            max=count;
            maxCharcter=q;
        }
    }
    
    return maxCharcter;
    
}

int main() {

  string S;
  cin >> S;

  char mf = mostFrequent(S);
  cout << mf << endl << S << endl;
  

  
}
