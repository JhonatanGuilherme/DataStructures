#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char operacao[15];
  float A, B;

  scanf("%f", &A);
  setbuf(stdin, NULL);
  scanf("%f", &B);
  setbuf(stdin, NULL);
  scanf("%s", operacao);
  setbuf(stdin, NULL);

  printf("resultado = ");
  if (strcmp(operacao, "soma") == 0)
    printf("%.2f\n", A + B);
  else if (strcmp(operacao, "subtracao") == 0)
    printf("%.2f\n", A - B);
  else if (strcmp(operacao, "multiplicacao") == 0)
    printf("%.2f\n", A * B);
  else if (strcmp(operacao, "divisao") == 0)
    printf("%.2f\n", A / B);

  return 0;
}
