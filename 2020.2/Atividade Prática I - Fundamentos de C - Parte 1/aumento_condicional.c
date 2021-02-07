#include <stdio.h>
#include <stdlib.h>

int main() {
  double percentual, salarioBase;

  scanf("%lf", &salarioBase);

  if (salarioBase <= 280)
    percentual = 0.20;
  else if (salarioBase <= 700)
    percentual = 0.15;
  else if (salarioBase < 1500)
    percentual = 0.10;
  else
    percentual = 0.05;

  printf("%.2lf\n", salarioBase);
  printf("%.0lf\n", percentual * 100);
  printf("%.2lf\n", salarioBase * percentual);
  printf("%.2lf\n", salarioBase + salarioBase * percentual);

  return 0;
}
