#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int hpInimigo[3], ataque, energiaPorAtaque, energiaMax, energiaTotal;
  char S[2];

  scanf("%d %d %d %d", &hpInimigo[0], &hpInimigo[1], &hpInimigo[2], &energiaTotal);
  setbuf(stdin, NULL);
  energiaMax = energiaTotal;
  scanf("%s", S);
  setbuf(stdin, NULL);

  if (strcmp(S, "C") == 0) {
    ataque = 40;
    energiaPorAtaque = 15;
  }
  else if (strcmp(S, "V") == 0) {
    ataque = 50;
    energiaPorAtaque = 20;
  }

  int cont = 0;
  bool pedroDoente = false, pedroVivo = true;

  while (cont < 3 && pedroVivo) {
    hpInimigo[cont] = hpInimigo[cont] - ataque;
    energiaTotal = energiaTotal - energiaPorAtaque;
    if (hpInimigo[cont] <= 0)
      cont ++;
    if (energiaTotal < energiaMax * 0.3 && !pedroDoente)
      energiaPorAtaque = energiaPorAtaque * 2;
      pedroDoente = true;
    if (energiaTotal <= 0) {
      pedroVivo = false;
      break;
    }
    printf("%d", cont);
  }

  if (pedroVivo)
    printf("Eba! Pedro sobreviveu\n");
  else
    printf("Que pena... Era um jovem tao promissor\n");

  return 0;
}
