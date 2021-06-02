#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int T;

  scanf("%d", &T);
  setbuf(stdin, NULL);

  int M[T][T];
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < T; j++) {
      scanf("%d", &M[j][i]);
      setbuf(stdin, NULL);
    }
  }

  for (int i = 0; i < T; i++) {
    for (int j = 0; j < T; j++) {
      if (M[i][j] < 0)
        printf("%d", M[i][j] * 2);
      else
        printf("%d", M[i][j]);
      if (j < T - 1)
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}
