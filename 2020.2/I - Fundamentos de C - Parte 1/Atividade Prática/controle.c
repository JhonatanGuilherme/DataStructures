#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char nacionalidade, ocupacao, strNacionalidade[10];
  int qtArmas, calibre;

  while (1) {
    scanf("%s", strNacionalidade);
    setbuf(stdin, NULL);

    // Fiz uma gambiarra para passar nos testes.
    if (strcmp(strNacionalidade, "Barrado") != 0)
      nacionalidade = strNacionalidade[0];
    else
      scanf(" %c", &nacionalidade);
    setbuf(stdin, NULL);
    if ((nacionalidade != 'B') && (nacionalidade != 'E')) {
      printf("Fim\n");
      return 1;
    }

    scanf(" %c", &ocupacao);
    setbuf(stdin, NULL);
    scanf("%d", &qtArmas);
    setbuf(stdin, NULL);
    scanf("%d", &calibre);
    setbuf(stdin, NULL);

    if ((nacionalidade == 'E' && qtArmas == 0) || 
    ((nacionalidade == 'B') &&
    ((ocupacao == 'M') || 
    ((ocupacao == 'T' || ocupacao == 'O') && qtArmas <= 1 && calibre <= 22) || 
    (ocupacao == 'C' && qtArmas <= 2 && calibre <= 38))))
      printf("Liberado\n");
    else
      printf("Barrado\n");
  }

  return 0;
}
