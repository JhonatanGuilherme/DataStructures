#include <stdio.h>

void reduz(float *x, float *y) {
  printf("%.2f %.2f\n", *(x) - *(y), *(y));
}

int main(void) {
  float x, y;
  scanf("%f %f", &x, &y);
  reduz(&x, &y);

  return 0;
}