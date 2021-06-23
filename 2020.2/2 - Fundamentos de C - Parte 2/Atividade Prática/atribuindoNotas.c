#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char gabarito[100], resposta[100];
  int cont, T, tamCerto;

  scanf("%d", &T);
  setbuf(stdin, NULL);
  tamCerto = T * 2 - 1;
  while (1) {
    scanf(" %[^\n]s", gabarito);
    setbuf(stdin, NULL);
    if (strcmp(gabarito, "sair") == 0)
      return 1;
    else if (strlen(gabarito) != tamCerto) {
      printf("Gabarito de tamanho errado. Entre com o novo gabarito:\n");
      continue;
    }
    break;
  }
  while (1) {
    scanf(" %[^\n]s", resposta);
    setbuf(stdin, NULL);
    if (strcmp(resposta, "sair") == 0)
      return 1;
    else if (strlen(resposta) != tamCerto) {
      printf("Tamanho da resposta diferente do tamanho do gabarito.\n");
      continue;
    } else {
      cont = 0;
      for (int i = 0; i < tamCerto; i += 2) {
        if (gabarito[i] == resposta[i])
          cont++;
      }
      printf("Percentual de acertos: %.1f\n", (cont * 100.0) / T);
      break;
    }
  }
  
  return 0;
}
