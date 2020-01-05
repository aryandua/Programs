#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int arr[SIZE];
int N;

void makequeue() {
  int N=0;
}

int findpos(int x, int s, int e) {

  if(x < arr[0])
    return 0;
  if(x > arr[N-1])
    return N;

  if((e==s) || e-s==1) //base case for recursion
    return s;
  
  //If the code comes here it will only be for a normal (in middle) insertion
  int m = ((s+e)/2);
  if(arr[m] == x)
    return m;
  if(arr[m] < x)
    findpos(x, m+1, e);
  else
    findpos(x, s, m-1);
  
}

void insert(int x) {
  int i;
  int pos = findpos(x,0,N);
  for(i=N;i > (pos);i--)
    arr[i] = arr[i-1];
  arr[pos] = x;
  N++;
}

void deleteval(int x) {

  if(N==0) {
    //printf("ATTEMPT TO DELETE FROM EMPTY QUEUE!! \n");
    return;
  }
  if(N==1 && arr[0] == x) {
    N=0;
    return;
  }

  int i=findpos(x, 0, N);

  if(arr[i] != x) {
    // printf("ATTEMPT TO DELETE NON-EXISTANT VALUE \n");
    return;
  }

  int j;
  
  for(j=i;j < N-1; j++)
    arr[j] = arr[j+1];
  N--;
}

void change(int x, int y) {
  int i;
  for(i=0;i<N;i++) {
    if(arr[i] == x) {
      deleteval(x);
      insert(y);
      return;
    }
  }
  //printf("ERROR! TRIED TO CHANGE NON-EXISTANT VALUE \n");
}

int getmin() {
  if(N==0) {
    //printf("ATTEMPT TO GET MIN FOR EMPTY ARRAY \n");
    return -1;
  }
  else
    return arr[0];
}

int main() {
  FILE *fptr;
  fptr = fopen("./testcase.txt", "r");
  int x, r;
  x=1000000;
  int m;
  char c;
  fscanf(fptr, "%d ",&x);
  int i;
  for(i=0;i<x;i++) {
    //if(i%10000 == 0)
    // printf("%d\n",i);
    fscanf(fptr, "%c %d ",&c,&r);
    if(c == 'I') {
      insert(r);
      //printf("Inserting %d \n",r);
    }
    else if(c == 'D') {
      //printf("Deleting %d \n",r);
      deleteval(r);
    }
    else if(c == 'M') {
      m=getmin();
      //printf("MIN=%d \n",m);
    }
    else {
      printf("ERROR! \n");
      return 1;
    }
  }
  m=getmin();
  //printf("MIN=%d \n",m);
}
