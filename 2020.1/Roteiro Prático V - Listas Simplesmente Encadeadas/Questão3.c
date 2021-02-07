#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Livro {
  int Codigo;
  char Titulo[30], Tipo[30], Autor[60];
};

typedef struct Registro *ListaLivros;

//Definição do tipo lista
struct Registro {
  struct Livro Dados;
  struct Registro *Proximo;
};

typedef struct Registro Registro;

ListaLivros *criaLista() {
  ListaLivros *Lista = (ListaLivros *)malloc(sizeof(ListaLivros));
  if (Lista != NULL)
    *Lista = NULL;
  return Lista;
}

void imprimeRegistro(struct Livro *LivroAux);

void liberaLista(ListaLivros *Lista) {
  if (Lista != NULL) {
    Registro *no;
    while ((*Lista) != NULL) {
      no = *Lista;
      *Lista = (**Lista).Proximo;
      free(no);
    }
    free(Lista);
  }
}

int insereElementoFinal(ListaLivros *Lista, struct Livro LivroAux) {
  if (Lista == NULL) {
    return 0;
  }
  Registro *No = (Registro *)malloc(sizeof(Registro));
  if (No == NULL) {
    return 0;
  }
  (*No).Dados = LivroAux;
  (*No).Proximo = NULL;
  if ((*Lista) == NULL) {
    *Lista = No;
  } else {
    Registro *Aux;
    Aux = *Lista;
    while ((*Aux).Proximo != NULL) {
      Aux = (*Aux).Proximo;
    }
    (*Aux).Proximo = No;
  }

  return 1;
}

int consultaLista(ListaLivros *Lista, char Titulo[30], struct Livro *LivroAux) {
  if (Lista == NULL) {
    return 0;
  }
  Registro *Aux = *Lista;
  while (Aux != NULL && strcmp((*Aux).Dados.Titulo, Titulo) != 0) {
    Aux = (*Aux).Proximo;
  }
  LivroAux = &(*Aux).Dados;
  imprimeRegistro(&(*Aux).Dados);

  return 0;
}

void imprimeLista(ListaLivros *Lista) {
  if (Lista == NULL)
    return;
  Registro *Aux = *Lista;
  int i = 1;
  while (Aux != NULL) {
    printf("Informacoes do livro %d:\n", i++);
    printf("-------------------------------\n");
    printf("Codigo: %d\n\n", (*Aux).Dados.Codigo);
    printf("Titulo: %s\n", (*Aux).Dados.Titulo);
    printf("Tipo: %s\n", (*Aux).Dados.Tipo);
    printf("Autor: %s", (*Aux).Dados.Autor);
    printf("-------------------------------\n");
    Aux = (*Aux).Proximo;
  }
}

void imprimeRegistro(struct Livro *LivroAux) {
  printf("Informações do livro buscado:\n");
  printf("-------------------------------\n");
  printf("Código: %d\n\n", (*LivroAux).Codigo);
  printf("Título: %s\n", (*LivroAux).Titulo);
  printf("Tipo: %s\n", (*LivroAux).Tipo);
  printf("Autor: %s", (*LivroAux).Autor);
  printf("-------------------------------\n");
}

void troca(ListaLivros *Lista, int posInicial, int posFinal) {
  int cont = 0;
  Registro *aux = *Lista;
  Registro *pri = (Registro *)malloc(sizeof(Registro));
  Registro *sec = (Registro *)malloc(sizeof(Registro));
  Registro *antpri = (Registro *)malloc(sizeof(Registro));
  Registro *antsec = (Registro *)malloc(sizeof(Registro));
  Registro *aux6 = (Registro *)malloc(sizeof(Registro));

  while (aux != NULL) {
    printf("C = %d\n\n", cont);
    if (posInicial != 0) {
      if (posInicial == cont + 1) {
        antpri = aux;
      }
    }
    if (posInicial == cont) {
      pri = aux;
    }
    if (posFinal == cont) {
      sec = aux;
    }
    if (posFinal == cont + 1) {
      antsec = aux;
    }
    aux = (*aux).Proximo;
    cont++;
  }
  aux = *Lista;

  if (posInicial == 0)
    Lista = &sec;
  else
    (*antpri).Proximo = sec, printf("okay 1\n");
  (*aux6).Proximo = (*sec).Proximo, printf("okay 2\n");
  (*sec).Proximo = (*pri).Proximo, printf("okay 3\n");
  (*antsec).Proximo = pri, printf("okay 4\n");
  (*pri).Proximo = (*aux6).Proximo, printf("okay 5\n");
  imprimeLista(Lista);
}

int main(void) {
  // Criação da lista de livros
  ListaLivros *listaFinal = criaLista();

  int quantLivros;
  printf("Digite a quantidade de livros que deseja adicionar: ");
  scanf("%d", &quantLivros);
  setbuf(stdin, NULL);

  //Leitura dos elementos da lista
  for (int i = 0; i < quantLivros; i++) {
    struct Livro Livro;
    printf("Digite o codigo do livro: ");
    scanf("%d", &Livro.Codigo);
    setbuf(stdin, NULL);
    printf("Digite o titulo do livro: ");
    fgets(Livro.Titulo, MAX, stdin);
    setbuf(stdin, NULL);
    printf("Digite o tipo do livro: ");
    fgets(Livro.Tipo, MAX, stdin);
    setbuf(stdin, NULL);
    printf("Digite o autor do livro: ");
    fgets(Livro.Autor, MAX, stdin);
    setbuf(stdin, NULL);
    printf("\n");
    insereElementoFinal(listaFinal, Livro);
  }

  //Impressão elementos da lista
  imprimeLista(listaFinal);

  int quantBuscas;
  printf("Digite a quantidade de buscas que deseja fazer: ");
  scanf("%d", &quantBuscas);
  setbuf(stdin, NULL);

  struct Livro *LivroAux;

  //Leitura dos elementos da lista
  for (int i = 0; i < quantBuscas; i++) {
    char Titulo[30];
    printf("Digite o título do livro: ");
    fgets(Titulo, MAX, stdin);
    setbuf(stdin, NULL);
    consultaLista(listaFinal, Titulo, LivroAux);
  }
  int a = 0, b = 0;
  printf("Digite o primeiro index para troca de elementos: ");
  scanf("%d", &a);
  setbuf(stdin, NULL);
  printf("Digite o segundo index para troca de elementos: ");
  scanf("%d", &b);
  setbuf(stdin, NULL);
  troca(listaFinal, a, b);

  return 0;
}
