#include <stdio.h>
#include <stdlib.h>

int main() {
  double avela, caramelo, passas, valor, valorTotal;

  scanf("%lf", &avela);
  scanf("%lf", &caramelo);
  scanf("%lf", &passas);

  scanf("%lf", &valor);
  valorTotal = valor * avela;
  scanf("%lf", &valor);
  valorTotal = valorTotal + valor * caramelo;
  scanf("%lf", &valor);
  valorTotal = valorTotal + valor * passas;

  printf("Valor: R$%.2lf\n", valorTotal);

  return 0;
}
