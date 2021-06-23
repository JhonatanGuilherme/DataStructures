#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int cont, cont2, N[2];

  scanf("%d %d", &N[0], &N[1]);
  setbuf(stdin, NULL);
  int M[N[0]][N[1] + 1];

  for (int i = 0; i < N[0]; i++) {
    for (int j = 0; j < N[1]; j++) {
      scanf("%d", &M[i][j]);
      setbuf(stdin, NULL);
      cont += M[i][j];
    }
    M[i][N[1]] = cont;
    cont = 0;
  }

  cont = 2147483647;
  cont2 = 0;
  for (int i = 0; i < N[0]; i++) {
    if (M[i][N[1]] < cont) {
      cont = M[i][N[1]];
      cont2 = i;
    }
  }

  printf("%d\n", cont2 + 1);

  return 0;
}
