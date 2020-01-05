#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5692962
//functions:

int getsmartdelvalue(void);
void addtoqueue(int num);
void deletefromqueue(int del);

int inqueue[SIZE];
int queuecount;

int main() {
  srand(time(NULL));
  int num, opt;
  int i;
  char which;
  queuecount=0;


 FILE *fptr = fopen("./testcase.txt", "a");

 num = (rand() % SIZE);
 fprintf(fptr, "%d \n", SIZE);
 fprintf(fptr, "I %d\n", num);
 inqueue[0] = num;
 queuecount++;
 
 for(i=0;i<SIZE;i++) {

   if(queuecount == 0)
     opt = 0;

   else
     opt = rand() % 3;
   
   if(opt == 0) {
     num = rand() % SIZE;
     which = 'I';
     addtoqueue(num);
   }
   else if(opt == 1) {
     which = 'D';
     num = getsmartdelvalue();
   }
   else {
     which = 'M';
     num = 0;
   }
   fprintf(fptr, "%c %d \n",which,num);
 }
 fclose(fptr);
 int min = 2147483640;
 for(i=0;i<queuecount;i++) {
   if(inqueue[i] < min)
     min = inqueue[i];
 }

 printf("MIN = %d \n");
 
}

void addtoqueue(int num) {
  inqueue[queuecount] = num;
  queuecount++;
}

int getsmartdelvalue(void) {
  int probab = rand() % 100 + 1;

  if(probab <= 99) {
    int randindex = rand() % queuecount;
    deletefromqueue(randindex);
    return randindex;
  }

  else {
    return (rand() % SIZE) + SIZE;
  }
}

void deletefromqueue(int del) {
  int i;
  for(i = del; i<=queuecount;i++)
    inqueue[i] = inqueue[i+1];
  queuecount--;
}
