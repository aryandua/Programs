#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000
int READ;
int arr[SIZE];
int N = 0;


void insert(int val) {

  // printf("Inserting %d \n",val);
  arr[N] = val;
  int tmp;
  int i=N;
  N++;

  while(arr[i] < arr[i/2]) {
    if(arr[i] < arr[i/2]) {
      tmp = arr[i/2];
      arr[i/2] = arr[i];
      arr[i] = tmp;
      i /= 2;
    }

    else
      break;
  }
  
}

void deleteval(int i) {

  //  printf("Deleting %d \n ",arr[i]);
  
  if( (i >= N) || (i < 0) ) {
    //printf("ERROR CANNOT DELETE NON-EXISTANT VALUE!!! \n");
    return;
  }
  // "i" is the variable with index of element to delete.
  int tmp = arr[N-1];
  arr[N-1] = arr[i];
  arr[i] = tmp;
  N--;

  //swap it with the rightmost element, and remove the new last element

  if(N==0) // If that empties queue, I am done.
    return;

  
  if(arr[i/2] > arr[i]) { //If new location of right most swapped node should be higher up
    while(arr[i] < arr[i/2]) {
      if(arr[i] < arr[i/2]) {
	tmp = arr[i/2];
	arr[i/2] = arr[i];
	arr[i] = tmp;
	i /= 2;
      }
      
      else
	return;
    }
  }


  if( ((((2*i)+1)) >= N) && (((2*i)+2) >= N) ) // Check if node is already a leaf.
    return;


  
    //If code Hasn't returned by now, I need to heapify down.

  while(  ( (arr[i] > arr[(2*i)+1]) && ((2*i+1) < N) ) || (arr[i] > arr[(2*i)+2]) && ((2*i+2) < N) ) {
    
    if( (arr[i] > arr[(2*i)+1]) && ( (2*i) + 1) < N ) {
      tmp = arr[i];
      arr[i] = arr[(2*i)+1];
      arr[(2*i)+1] = tmp;
      i = ((2*i)+1);
    }
    
    else if( (arr[i] > arr[(2*i)+2]) && ( (2*i) + 2) < N ){
      tmp = arr[i];
      arr[i] = arr[(2*i)+2];
      arr[(2*i)+2] = tmp;
      i = ((2*i)+2);
    }
    
    if( ((((2*i)+1)) >= N) && (((2*i)+2) >= N) ) //means node has reached rock bottom.
      return;   
  
  }
}

int getmin(void) {
  return arr[0];
}

int main() {
  FILE *fptr;
  fptr = fopen("./testcase.txt", "r");
  int r;
  int m;
  char c;
  int i;

  fscanf(fptr, "%d ",&READ);
  
  for(i=0;i<READ;i++) {
    //if(i%1000000 == 0)
    //printf("%d\n",i);
    fscanf(fptr, "%c %d ",&c,&r);
    if(c == 'I') {
      //printf("Inserting %d \n",r);
      insert(r);
    }
    else if(c == 'D') {
      //printf("Deleting %d \n",arr[r]);
      deleteval(r);
    }
    else if(c == 'M') {
      m=getmin();
      //printf("MIN=%d \n",m);
    }
    else {
      printf("ERROR!! \n");
      return 1;
    }
  }
  m=getmin(); 
  printf("MIN=%d \n",m); 
}
