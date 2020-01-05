#include <stdio.h>
#include <stdlib.h>

#define SIZE 100,000,000

int N;

struct l {
  int val;
  struct l* next;
};

typedef struct l ll;

ll *head;

void makequeue() {
  head = NULL;
}

void insert(int x) {
  ll *tmp = head;
  ll *tmp2;
  
  if(head == NULL) {
    head = (ll*) malloc(sizeof(ll));
    head->val = x;
    head->next = NULL;
    return;
  }

  if(head->next == NULL && x > head->val) {
    head->next = (ll*) malloc(sizeof(ll));
    head->next->val = x;
    head->next->next = NULL;
  }

  if(x < head->val) {
    tmp2 = (ll*) malloc(sizeof(ll));
    tmp2->val = x;
    tmp2->next = head;
    head = tmp2;
    return;
  }
  
  int done = 0;


  while(tmp->next->val < x) {
    tmp=tmp->next;
    if(tmp->next == NULL) {
      tmp->next = (ll*) malloc(sizeof(ll));
      tmp->next->val = x;
      tmp->next->next = NULL;
      done = 1;
      break;
    }
  }
  
  if(!done) {
    tmp2 = (ll*) malloc(sizeof(ll));
    tmp2->val = x;
    tmp2->next = tmp->next;
    tmp->next = tmp2;
  }
}

int getmin() {
  return head->val;
}

void deleteval(int x) {
  ll *tmp, *tmp2;
  tmp=head;
  int wrong = 0;
  
  if(x == 0) { // If I have to delete head
    tmp2 = head;
    head = head->next;
    free(tmp2);
    return;
  }

  
  
  int count=0;
  if(x < 0) {
    //printf("ATTEMPT TO DELETE NON-EXISTANT NODE!!! \n");
    return;
  }
  else {
    while(count != x) { // Keep going until you have to delete next node
      tmp = tmp->next;
      count ++;
      if(tmp->next == NULL) { // THis means x isn't in the list
	//printf("ATTEMPT TO DELETE NON-EXISTANT NODE!!! \n");
	wrong = 1;
	break;
      }
    }
    
    if(!wrong) { // will only come here for normal case
      tmp2 = tmp->next;
      tmp->next = tmp->next->next;
      free(tmp2);
    }
  }
  
}

void change(int x, int y)  { // Changes first value x to y
  ll* tmp = head;
  while(tmp!=NULL) {
    if(tmp->val == x)
      break;
    tmp = tmp->next;
  }
  if(tmp == NULL) {
    //printf("CANNOT CHANGE NON-EXISTANT VALUE \n");
    return;
  }
  deleteval(x);
  insert(y);
}
   
int main() {
  
  FILE *fptr;
  fptr = fopen("./testcase.txt", "r");
  int r;
  int m;
  char c;
  int i;

  fscanf(fptr, "%d ", &N);
  
  for(i=0;i<N;i++) {
    // if(i%10000 == 0)
    //printf("%d\n",i);
    fscanf(fptr, "%c %d ",&c,&r);
    if(c == 'I') {
      //printf("Inserting %d \n",r);
      insert(r);
    }
    else if(c == 'D') {
      //printf("Deleting %d \n",r);
      deleteval(r);
    }
    else if(c == 'M') {
      //printf("Getting Min \n");
      m=getmin();
      //printf("MIN=%d \n",m);
    }
    else {
      printf("ERROR \n");
      return 1;
    }
  }
  m=getmin(); 
  //printf("MIN=%d \n",m); 
}
