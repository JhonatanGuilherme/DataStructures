#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int count = 0;

int maior(char *x, char *y) {
  if (x[count] == '\0')
    return 2;
  if (y[count] == '\0')
    return 1;
  if (strlen(x) > strlen(y))
    return 1;
  if (strlen(y) > strlen(x))
    return 2;
  if (x[count] == y[count]) {
    count++;
    return maior(x, y);
  } else if (x[count] > y[count])
    return 1;
  else
    return 2;
}

int main(void) {
  char x[MAX], y[MAX];

  scanf(" %[^\n]s", x);
  scanf(" %[^\n]s", y);

  if (maior(x, y) == 1)
    printf("%s\n", x);
  else
    printf("%s\n", y);

  return 0;
}
