#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double pH;
  scanf("%lf", &pH);

  if (pH < 7)
    printf("Acida\n");
  else if (pH > 7)
    printf("Basica\n");
  else
    printf("Neutra");

  return 0;
}
