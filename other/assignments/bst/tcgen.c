#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//functions:

int getsmartdelvalue(void);
int getsmartsearchvalue(void);
void addtotree(int num);
void deletefromtree(int del);

int intree[100];
int treecount;

int main() {
  srand(time(NULL));
  int num, opt;
  int i;
  char which;
  treecount=0;


 FILE *fptr = fopen("./testcase.txt", "w");

 num = (rand() % 100);
 fprintf(fptr, "I %d\n", num);
 intree[0] = num;
 treecount++;
 
 for(i=0;i<100;i++) {

   if(treecount == 0)
     opt = 0;

   else
     opt = rand() % 3;
   
   if(opt == 0) {
     num = rand() % 100;
     which = 'I';
     addtotree(num);
   }
   else if(opt == 1) {
     which = 'D';
     num = getsmartdelvalue();
   }
   else {
     which = 'S';
     num = getsmartsearchvalue();
   }
   fprintf(fptr, "%c %d\n",which,num);
 }
 fclose(fptr);

 // printf("treecount = %d\n",treecount);

 fptr = fopen("check1.txt", "w");
 for(i=0;i<treecount;i++)
   fprintf(fptr, "%d\n",intree[i]);
}

void addtotree(int num) {
  intree[treecount] = num;
  treecount++;
}

int getsmartdelvalue(void) {
  int probab = rand() % 10 + 1;

  if(probab <= 8) {
    int randindex = rand() % treecount;
    deletefromtree(randindex);
    return intree[randindex];
  }

  else {
    return (rand() % 100) + 100;
  }
}

int getsmartsearchvalue(void) {
  int probab = rand() % 10 + 1;

  if(probab <= 8) {
    int randindex = 0;
    randindex = rand() % treecount;
    return intree[randindex];
  }
  
  else 
    return ((rand() % 100) + 100);
}

void deletefromtree(int del) {
  int i;
  for(i = del; i<=treecount;i++)
    intree[i] = intree[i+1];
  treecount--;
}
