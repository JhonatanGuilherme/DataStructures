#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char c1[2], c2[2], palavra[100], lista[100];
  int a;
  printf("Digite o primeiro caractere: ");
  scanf("%c", c1);
  c1[1] = getchar();
  printf("Digite o segundo caractere: ");
  scanf("%c", c2);
  c2[1] = getchar();
  printf("Digite a quantidade de caracteres da palavra: ");
  scanf("%d", &a);
  getchar();
  printf("Digite a Palavra: ");
  for (int i = 0; i < a; i++) {
    palavra[i] = getchar();
  }
  for (int i = 0; i < a + 2; i++) {
    if (i == 0) {
      lista[i] = c1[0];
    } else if (i < a + 1) {
      lista[i] = palavra[i - 1];
    } else {
      lista[i] = c2[0];
      break;
    }
  }
  for (int i = 0; i < a + 2; i++) {
    printf("%c", lista[i]);
  }

  return 0;
}
