#include <stdio.h>
#include <stdlib.h>

int main() {
  float descontoINSS, salarioBase;

  scanf("%f", &salarioBase);

  if (salarioBase <= 1751.81)
    descontoINSS = salarioBase * 0.08;
  else if (salarioBase <= 2919.72)
    descontoINSS = salarioBase * 0.09;
  else if (salarioBase < 5839.45)
    descontoINSS = salarioBase * 0.11;
  else
    descontoINSS = 5839.45 * 0.11;

  printf("Desconto do INSS: R$ %f\n", descontoINSS);

  return 0;
}