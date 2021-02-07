#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int verifyListInt(char *s) {

  char aux[] = " ";
  int lenList = strlen(s);
  printf("Strlen: %d.\n", lenList);

  for (int i = 0; i < lenList; i++) {
    if ((isdigit(s[i]) == 0) && (s[i] != aux[0])) {
      return 0;
    }
  }

  int cont = 0;
  int cont2 = 0;
  char *p = strtok(s, " ");

  while (p != NULL) {
    p = strtok(NULL, " ");
    cont++;
  }

  printf("Cont: %d.\n", cont);
  return cont; // Retorna len dos inteiros.
}

int *splitInt(char *s, int *size) {

  //int a = size;
  *size = verifyListInt(s);
  printf("Size: %d.\n", size);

  if (size == 0) {
    printf("Null.\n");
    return NULL;
  }

  int cont = 0;
  int *pList = malloc((*size) * sizeof(int));
  char *pTok = strtok(s, " ");
  //pList[cont] = atoi(pTok);

  while (pTok != NULL) {
    printf("%s\n", pList[cont]);
    pTok = strtok(NULL, " ");
    pList[cont] = atoi(pTok);
    cont++;
  }

  for (int i = 0; i < *size; i++) {
    printf("pList %d: %d\n", i, pList[i]);
  }

  return pList;
}

int main() {
  char ent[100];
  scanf("%[^\n]s", ent);
  int size = 0;
  int *entInt = splitInt(ent, &size);
  if (entInt == NULL) {
    printf("String invalida.\n");
    return 1;
  }
  printf("Size: %d\n", size);
  for (int i = 0; i < size; i++) {
    printf("Entrada%d: %d\n", i, entInt[i]);
  }

  system("pause");
  return (0);
}
