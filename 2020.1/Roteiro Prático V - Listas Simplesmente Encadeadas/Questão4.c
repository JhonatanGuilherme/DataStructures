#include <stdio.h>
#include <string.h>
#define MAX 100

int aux = 0, c = 0, cont = 0, contR, contP, contN;
char b[MAX];

struct Livro {
  int Codigo;
  char Titulo[MAX], Tipo[MAX], Autor[MAX];
};

struct Livro L[45];

struct Node {
  int Posicao, Codigo;
  struct Node *Next;
};

struct Node *getNode() {
  struct Node *pNode = (struct Node *)malloc(sizeof(struct Node *));
  return pNode;
}

struct Node **criaLista() {
  struct Node **Lista = (struct Node **)malloc(sizeof(struct Node *));
  if (*Lista != NULL)
    *Lista = NULL;
  return *Lista;
}

int insereElementoFinal(struct Node **Lista, struct Livro LivroAux) {
  if (Lista == NULL) {
    return 0;
  }
  struct Node *NodeAux = getnode();
  if (NodeAux == NULL) {
    return 0;
  }
  L[cont] = LivroAux;
  (*NodeAux).Posicao = cont;
  (*NodeAux).Next = NULL;
  if ((*Lista) == NULL) {
    *Lista = NodeAux;
  } else {
    struct Node *Aux;
    Aux = *Lista;
    while ((*Aux).Next != NULL) {
      Aux = (*Aux).Next;
    }
    (*Aux).Next = NodeAux;
  }

  return 1;
}

int consultaLista(struct Node **Lista, char Titulo[30], struct Livro *LivroAux) {
  if (Lista == NULL) {
    return 0;
  }
  struct Node *Aux = *Lista;
  while (Aux != NULL && strcmp(L[(*Aux).Posicao].Titulo, Titulo) != 0) {
    Aux = (*Aux).Next;
  }
  LivroAux = &L[(*Aux).Posicao];
  imprimeRegistro(&L[(*Aux).Posicao]);

  return 1;
}

void liberaLista(struct Node **Lista) {
  if (Lista != NULL) {
    struct Node *NodeAux;
    while ((*Lista) != NULL) {
      NodeAux = *Lista;
      *Lista = (**Lista).Next;
      free(NodeAux);
    }
    free(Lista);
  }
}

int main(void) {

  struct Node **listaRomance = criaLista();   //Início da Encadeada Romance
  struct Node **listaPolicial = criaLista();  //Início da Encadeada Policial
  struct Node **listaNaoFiccao = criaLista(); //Início da Encadeada NaoFiccao

  int a = 0;
  while (1) {
    printf("\n1 - Insercao\n");
    printf("2 - Retirada\n");
    printf("3 - Sair\n");
    printf("Digite: ");
    scanf("%d", &a);
    setbuf(stdin, NULL);

    if (a == 1) {
      if (cont >= 45)
        printf("Erro na insercao, biblioteca cheia.\n");
      else {
        struct Livro Livro;
        printf("Codigo: ");
        scanf("%d", &L[cont].Codigo);
        setbuf(stdin, NULL);
        printf("Titulo: ");
        fgets(L[cont].Titulo, MAX, stdin);
        setbuf(stdin, NULL);
        printf("Tipo (romance, policial ou naoficcao): ");
        fgets(L[cont].Tipo, MAX, stdin);
        setbuf(stdin, NULL);
        printf("Autor: ");
        fgets(L[cont].Autor, MAX, stdin);
        setbuf(stdin, NULL);
        a = 0;

        if (strcmp(L[cont].Tipo, "romance") == 0) {
          insereElementoFinal(listaRomance, Livro);
          contR++;
        } else if (strcmp(L[cont].Tipo, "policial") == 0) {
          insereElementoFinal(listaPolicial, Livro);
          contP++;
        } else if (strcmp(L[cont].Tipo, "naoficcao") == 0) {
          insereElementoFinal(listaNaoFiccao, Livro);
          contN++;
        }
        printf("\nLivro %s adicionado com sucesso. \n", L[cont].Titulo);
        cont++;
      }
    } else if (a == 2) {
      char aux2[MAX];
      printf("------------ Retirar Livro -------------\n");
      printf("Tipo (romance, policial ou naoficcao): ");
      fgets(b, MAX, stdin);
      setbuf(stdin, NULL);
      printf("Codigo: ");
      scanf("%d", &c);
      setbuf(stdin, NULL);

      if (strcmp(b, "romance") == 0) {
        if ((**listaRomance).Next == NULL) {
          printf("Lista vazia.");
        }
        else {
          int aux = 0;
          struct Node *NodeAux = *listaRomance;
          struct Node *NodeAux2 = NULL;
          for (int i = 0; i < contR; i++) {
            if (L[(*NodeAux).Posicao].Codigo == c) {
              strcpy(aux2, L[(*NodeAux).Posicao].Titulo);
              while ((*NodeAux).Next != NULL) {
                NodeAux2 = NodeAux;
                NodeAux = (*NodeAux).Next;
                if (L[(*NodeAux2).Posicao].Codigo == (*NodeAux2).Codigo) {
                  (*NodeAux2).Codigo = L[(*NodeAux).Posicao].Codigo;
                  (*NodeAux2).Posicao = contR;
                }
              }
            } else {
              NodeAux = (*NodeAux).Next;
            }
          }
        }
        contR--;
      }
      if (strcmp(b, "policial") == 0) {
        if (listaPolicial == NULL) {
          printf("Lista vazia.");
        } else {
          int aux = 0;
          struct Node *NodeAux = *listaPolicial;
          for (int i = 0; i < contR; i++) {
            if (L[(*NodeAux).Posicao].Codigo == c) {
              strcpy(aux2, L[(*NodeAux).Posicao].Titulo);
              while ((*NodeAux).Next != NULL) { }
            } else {
              NodeAux = (*NodeAux).Next;
            }
          }
        }
        contR--;
      }

      if (strcmp(b, "romance") == 0) {
        if (listaRomance == NULL) {
          printf("Lista vazia.");
        } else {
          int aux = 0;
          struct Node *NodeAux = *listaRomance;
          for (int i = 0; i < contR; i++) {
            if (L[(*NodeAux).Posicao].Codigo == c) {
              strcpy(aux2, L[(*NodeAux).Posicao].Titulo);
              while ((*NodeAux).Next != NULL) { }
            } else {
              NodeAux = (*NodeAux).Next;
            }
          }
        }
        contR--;
      }
      cont--;
      if (strlen(aux2) > 2)
        printf("\nLivro %s removido com sucesso.\n", aux2);
      else
        printf("\nErro.\n");
    }

    else if (a == 3)
      break;
  }

  return 0;
}
