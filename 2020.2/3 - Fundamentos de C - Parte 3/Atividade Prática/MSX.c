#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void upperString(char *string) {
  int count = 0;
  while (string[count] != '\0') {
    if (string[count] >= 'a' && string[count] <= 'z') {
      string[count] = string[count] - 32;
    }
    count++;
  }
}

int main(void) {
  char *string = NULL;
  string = (char *)malloc(sizeof(char) * 75);
  while (1)
  {
    gets(string);
    if (strcmp(string, "the end!") == 0)
    {
      break;
    }
    upperString(string);
    printf("%s\n", string);
  }
  free(string);
  
  return 0;
}
