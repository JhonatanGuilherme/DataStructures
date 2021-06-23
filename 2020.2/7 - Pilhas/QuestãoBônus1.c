#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPILHA {
  int *arr, MAX, pos;
};

void criar(struct sPILHA *p, int tam_MAX);
void apagar(struct sPILHA *p);
void push(struct sPILHA *p, int dado);
int pop(struct sPILHA *p);
int tamanho(struct sPILHA *p);
void imprimir(struct sPILHA *p);
void imprimirInvertido(char *s);

int main(void) {
  char str[101];
  printf("Entre com a string: ");
  scanf(" %[^\n]s", str);
  
  imprimirInvertido(str);
  
  return 0;
}

void criar(struct sPILHA *p, int tam_MAX) {
  p->arr = malloc(sizeof(int) * tam_MAX);
  p->MAX = tam_MAX;
  p->pos = 0;
}

void apagar(struct sPILHA *p) {
  free(p->arr);
  p->MAX = 0;
  p->pos = 0;
}

void push(struct sPILHA *p, int dado) {
  if (p->pos < p->MAX)
    p->arr[p->pos++] = dado;
  else
    printf("Nao foi possivel inserir %d. Pilha cheia.\n", dado);
}

int pop(struct sPILHA *p) {
  if (p->pos)
    return p->arr[--p->pos];
  printf("Nao ha elementos. Pilha vazia.\n");
  exit(1);
}

int tamanho(struct sPILHA *p) {
  return p->pos;
}

void imprimir(struct sPILHA *p) {
  printf("P[ ");
  for (int i = p->pos - 1; i >= 0; i--)
	  printf("%d ", p->arr[i]);
  printf("]\n");
}

void imprimirInvertido(char *s) {
  char *str = s;
  struct sPILHA p;
  criar(&p, strlen(str));

  while (*str) {
    push(&p, *str);
    if (*str == ' ') {
      pop(&p);
      while (tamanho(&p)) {
        printf("%c", pop(&p));
      }
      printf(" ");
    }
    str++;
  }
  
  while (tamanho(&p))
    printf("%c", pop(&p));
  printf("\n");
}
