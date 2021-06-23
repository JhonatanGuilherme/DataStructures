#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Passageiros {
  char nome[100];
  int poltrona, idade;
};

struct Passageiros P[44];

int main(void) {
  bool interromper = false;
  char S[8][100];
  int cont = 0, somaIdades = 0;

  for (int i = 0; i < 44; i++) {
    for (int j = 0; j < 8; j++) {
      scanf(" %[^\n]s", S[j]);
      setbuf(stdin, NULL);
      if (j == 0 && strcmp(S[j], "-1") == 0) {
        interromper = true;
        cont = i;
        break;
      }
      if (j == 5)
        P[i].poltrona = atoi(S[j]);
      else if (j == 6) {
        P[i].idade = atoi(S[j]);
        somaIdades += atoi(S[j]);
      }
      else if (j == 7)
        strcpy(P[i].nome, S[j]);
    }
    if (interromper)
      break;
  }

  somaIdades /= cont;

  for (int i = 0; i < cont; i++) {
    if (P[i].poltrona % 2 == 0 && P[i].idade > somaIdades)
      printf("%s\n", P[i].nome);
  }

  return 0;
}
