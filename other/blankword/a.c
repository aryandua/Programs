#include <stdio.h>
#include <string.h>

int main() {
  FILE *fptr;
  fptr = fopen("allwords.txt", "r");
  int i;
  char currword[100];
  for(i=0;i<466544;i++) {
    fscanf(fptr, "%s\n",currword);
    if(currword[8] == 't' && currword[0] == 'n' && currword[6] == 'e' && (strlen(currword) == 9)) {
      printf("%s\n",currword);
    }
  }
  fclose(fptr);
}
