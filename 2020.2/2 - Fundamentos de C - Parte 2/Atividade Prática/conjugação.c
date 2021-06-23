#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char S[100];

  scanf("%s", S);
  setbuf(stdin, NULL);

  for (int i = 0; i < strlen(S) - 1; i++) {
    printf("%c", S[i]);
  }
  printf(" ");

  for (int i = 0; i < strlen(S) - 1; i++) {
    printf("%c", S[i]);
  }
  printf("ndo\n");

  return 0;
}
