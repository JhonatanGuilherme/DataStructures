#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void printString(char *a) {
  printf("Aquilo que ");

  for (int i = 0; i < strlen(a) - 3; i++) {
    printf("%c", a[i]);
  }
  printf(".\n");
}

int main(void) {
  char S[MAX];

  scanf("%s", S);
  setbuf(stdin, NULL);

  printString(S);

  return 0;
}
