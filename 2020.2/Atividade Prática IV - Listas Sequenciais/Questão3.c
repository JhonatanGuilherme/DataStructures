#include <stdio.h>
#include <stdlib.h>

#define MAX 10

char l[MAX]; 
int pos = 0;

void inserir(char *elemento);
void inserir_ord(char *elemento);
void remover(char *elemento);
int buscar(char *elemento);

char obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
  return 0;
}

void inserir (char *elemento) {
  if (MAX > pos) {
    l[pos++] = elemento[0];
    l[pos] = '\0';
  }
  else {
    printf("Não foi possível inserir.\n");
  }
}

void inserir_ord (char *elemento) {
  int a, i;
  if (pos < MAX) {
    for (i = 0; i < pos; i++) {
      if(l[i] == elemento[0])
        break;
    }

    for (a = pos; a > i; a--){
      l[a] = l[a - 1];
    }

    l[i] = elemento[0];
    l[pos + 1] = '\0';
    pos++;
  }
  else {
    printf("Não foi possível inserir.\n");
  }
}

int buscar (char *elemento) {
  for(int i = 0; i < pos; i++){
    if (elemento[0] == l[i])
      return i;
  }
  return -1;
}

void remover (char *elemento) {
  int p = buscar(elemento);
  if (p == -1)
    return;
  for (int i = p; i < pos; i++) {
    l[i] = l[i + 1];
  }
  pos--;
}

char obter (int indice) {
  if (indice < 0 || indice >= pos) {
    printf("Indice %d fora dos limites da Lista.\n", indice);
    exit(1);
  }
  return l[indice];
}

int tamanho() {
  return pos;
}

void imprimir() {
  printf("%s\n", l);
}

void apagar(){
  pos = 0;
}
