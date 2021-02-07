#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Registro *Lista;

struct Registro {
  char no[1];
  struct Registro *prox;
};

typedef struct Registro Registro;

Lista *criar() {
  Lista *list = (Lista *)malloc(sizeof(Lista));
  if (list != NULL) {
    *list = NULL;
  }

  return list;
}

int insert(Lista *list, char aux[2]) {
  if (list == NULL) {
    return 0;
  }
  Registro *No = (Registro *)malloc(sizeof(Registro));
  if (No == NULL) {
    return 0;
  }
  (*No).no[0] = aux[0];
  (*No).prox = NULL;
  if ((*list) == NULL) {
    *list = No;
  } else {
    Registro *Aux1;
    Aux1 = *list;
    while ((*Aux1).prox != NULL) {
      Aux1 = (*Aux1).prox;
    }
    (*Aux1).prox = No;
  }

  return 1;
}

int concat(Lista *list, char a[2], char b[2]) {
  Registro *Auxa = (Registro *)malloc(sizeof(Registro));
  Registro *Auxb = (Registro *)malloc(sizeof(Registro));
  if (Auxa == NULL || Auxb == NULL) {
    return 0;
  }
  (*Auxa).no[0] = a[0];
  (*Auxa).prox = *list;
  (*Auxb).no[0] = b[0];
  (*Auxb).prox = NULL;
  *list = Auxa;
  Registro *Aux1 = *list;
  while ((*Aux1).prox != NULL) {
    Aux1 = (*Aux1).prox;
  }
  (*Aux1).prox = Auxb;

  return 1;
}

void imprimir(Lista *list) {
  Registro *aux = *list;
  while (aux != NULL) {
    printf("%c", (*aux).no[0]);
    aux = (*aux).prox;
  }
  printf("\n");
}

int main(void) {
  Lista *listEnd = criar();
  char c1[2], c2[2], palavra[2];
  int a;
  printf("Digite o primeiro caractere: ");
  scanf("%c", c1);
  setbuf(stdin, NULL);
  printf("Digite o segundo caractere: ");
  scanf("%c", c2);
  setbuf(stdin, NULL);
  printf("Digite a quantidade de caracteres da palavra: ");
  scanf("%d", &a);
  setbuf(stdin, NULL);
  printf("Digite a Palavra: ");
  for (int i = 0; i < a; i++) {
    palavra[0] = getchar();
    insert(listEnd, palavra);
    //setbuf(stdin, NULL);
  }
  concat(listEnd, c1, c2);
  imprimir(listEnd);

  return 0;
}
