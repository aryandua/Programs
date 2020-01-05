#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int arr[SIZE];
int N;
int READ;


void makequeue() {
  int N=0;
}

void insert(int x) {
  /* int *tmp = arr+N; */
  /* *(arr+N) = (int *) malloc(sizeof(int)); */
  arr[N] = x;
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

  int i;
  for(i=0;i<N;i++) {
    if(arr[i] == x)
      break;
  }

  if(i==N) {
    //printf("ATTEMPT TO DELETE NON-EXISTANT VALUE \n");
    return;
  }
  
  arr[i] = arr[N-1];
  N--;
}

void change(int x, int y) {
  int i;
  for(i=0;i<N;i++) {
    if(arr[i] == x) {
      arr[i] = y;
      return;
    }
  }
  //printf("ERROR! TRIED TO CHANGE NON-EXISTANT VALUE \n");
}

int getmin() {
  int i, min;
  min = 2147483640; //largest int, or almost
  for(i=0;i<N;i++) {
    if(arr[i] < min)
      min = arr[i];
  }
  return min;
}

int main() {
  
  FILE *fptr;
  fptr = fopen("./testcase.txt", "r");
  int r;
  int m;
  char c;
  int i;

  fscanf(fptr, "%d ", &READ);
  
  for(i=0;i<READ;i++) {
    //if(i%10000 == 0)
    //printf("%d\n",i);
    fscanf(fptr, "%c %d ",&c,&r);
    if(c == 'I') {
      insert(r);
      //printf("Inserting %d \n",r);
    }
    else if(c == 'D') {
      //   printf("Deleting %d \n",r);
      deleteval(r);
    }
    else {
      m=getmin();
      // printf("MIN=%d \n",m);
    }
  }
  m=getmin(); 
  //printf("MIN=%d \n",m); 
}
