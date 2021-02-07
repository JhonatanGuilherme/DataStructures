#include <stdio.h>
#include <stdlib.h>

void calc_esfera(float R, float *area, float *volume) {
  const float pi = 3.1415;
  *area = 4 * pi * (R * R);
  *volume = ((4 / 3.0) * pi) * (R * R * R);
}

int main(void) {
  float raio, ar, vol;
  float *area = &ar, *volume = &vol;
  printf("Digite o valor do raio: \n");
  scanf("%f", &raio);
  calc_esfera(raio, area, volume);
  printf("Valor da Area: %f\nValor do volume: %f", ar, vol);

  return 0;
}
