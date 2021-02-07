#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 999

int contador = 0;

struct livro {
  int na, doado;
  char titulo[30], autor[30];
};

struct livro a[MAX];

void Mostrar(struct livro b) {
  printf("Titulo: %s.\n", b.titulo);
  printf("Autor: %s.\n", b.autor);
  printf("Numero de acessos: %d.\n", b.na);
  if (b.doado == 0)
    printf("Doado: Nao.\n");
  else
    printf("Doado: Sim.\n");
}

void Adicionar(int i, struct livro b) {
  b.na = 0;
  printf("Titulo: ");
  scanf("%s", b.titulo);
  printf("Autor: ");
  fgets(b.autor, sizeof(b.autor), stdin);
  scanf("%s", b.autor);
  printf("Numero de acessos: ");
  scanf("%d", &b.na);
  b.doado = 0;
  a[i] = b;
  contador++;
  printf("\nLivro '%s' adicionado.\n", b.titulo);
}

void livro_por_autor(struct livro *b, int numero_de_livros, char aut[]) {
  for (int i = 0; i < numero_de_livros; i++) {
    if (strcmp((b + i)->autor, aut) == 0)
      Mostrar(*(b + i));
  }
}

void livro_por_titulo(struct livro *b, int numero_de_livros, char nome[]) {
  for (int i = 0; i < numero_de_livros; i++) {
    if (strcmp((b + i)->titulo, nome) == 0)
      Mostrar(*(b + i));
  }
}

void doar_um_livro(struct livro b) {
  b.doado = 1;
  contador -= 1;
}

int main(void) {
  int A = 1;
  while (A == 1) {
    printf("\nBiblioteca.\n");
    printf("\n> 1 - Exibir informacoes do livro.\n> 2 - Adicione um novo livro.\n");
    printf("> 3 - Exibir todos os livros na biblioteca de um autor em particular.\n");
    printf("> 4 - Exibir o numero de livros de um titulo especifico.\n");
    printf("> 5 - Exibir o numero total de livros na biblioteca.\n");
    printf("> 6 - Colocar em circulacao um livro.\n");
    printf("> 7 - Sair.\n");
    int C;
    printf("\nEscolha: ");
    scanf("%d", &C);

    if (C == 1) {
      char nome[100];
      printf("Titulo: ");
      scanf("%s", nome);
      printf("\n");
      for (int i = 0; i < contador; i++) {
        if (strcmp(a[i].titulo, nome) == 0)
          Mostrar(a[i]);
      }
    } else if (C == 2) {
      struct livro b;
      Adicionar(contador, b);
    } else if (C == 3) {
      char autor[100];
      printf("Autor: ");
      scanf("%s", autor);
      livro_por_autor(a, contador, autor);
    } else if (C == 4) {
      char titulo[100];
      printf("Titulo: ");
      scanf("%s", titulo);
      livro_por_titulo(a, contador, titulo);
    } else if (C == 5)
      printf("Numero total de livros: %d.\n", contador);
    else if (C == 6) {
      char titulo2[100];
      printf("Titulo: ");
      scanf("%s", titulo2);
      for (int i = 0; i < contador; i++) {
        if (a[i].titulo == titulo2)
          doar_um_livro(a[i]);
      }
    }
    else if (C == 7)
      A = 0;
  }

  return 0;
}
