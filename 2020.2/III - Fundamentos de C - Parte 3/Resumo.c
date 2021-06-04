// - Ponteiros
// - Funções

// Ponteiros são variáveis que apontam para um endereço de memória
// de outra variável.

// Somente utilizar ponteiros quando há uma atribuição de endereço.
// Quando um ponteiro é declarado, mas não inicializado, o recomendado
// é que seja atribuído o valor de NULL para o mesmo.

/*
  Considerando que foi criado uma variável na posição de memória
  0x000aa04, um ponteiro irá guardar esse valor. Quando acessado
  por *, o valor do determinado endereço será retornado.
*/

/*
  Há a possibilidade de utilizar operações aritméticas com ponteiros.
  Dessa forma, utilizando ponteiro + 1, irá acessar a sua posição
  mais 1 conjunto de bytes do seu determinado tipo. No caso de
  um ponteiro do tipo int, 4 bytes são levados em consideração.
*/

// Um ponteiro do tipo NULL é um ponteiro genérico, que pode apontar
// para qualquer tipo.

/*
  Alocação dinâmica de memória - Recurso essencial para alocar memória
  durante a execução do programa. Há duas principais funções, malloc()
  e free().

  - malloc() - retorna um ponteiro com memória alocada.
  - free() - libera a memória alocada de um ponteiro.
*/

/*
  Funções - 
*/

// Protótipo de função sum, definição é feita depois do main.
int sum(int a, int b);
char *copia_str(char *str1, char *str2);
void dobraNumero(int *num);
int fatorial(int num);
char *copiaStrRecursiva(char *str1, char *str2);

#include <stdio.h>
#include <stdlib.h> // Contém as funções de alocação de memória.
#include <string.h>

typedef struct {
  char nome[100];
  unsigned int tempoDeServico;
} sPessoa;

// *pessoas é um ponteiro que armazena um ou mais elementos da struct.
sPessoa *pessoas;

int main(void) {
  char *ch, ch1, *ch2; // ch/ch2 são ponteiros de char
  int a, *b, c; // b - ponteiro de int
  float af[100]; // Tecnicamente, é um ponteiro para a primeira posição da lista.

  int *p_a, *p;
  p_a = &a; // Atribuindo o endereço de a para p_a.
  p = NULL; // Atribuindo a constante NULL para p.
  
  int *p_p_a = p_a; // p_p_a recebe o endereço que p_a armazena.
  
  scanf("%d", &a); // Valor pode atribuído diretamente pra variável.
  printf("%d\n", *p_p_a);

  int x, y;
  int *pointerToX = &x, *pointerToY = &y;

  // Valor pode ser atribuído através do ponteiro, acessado por *.
  *pointerToX = 5; 
  *pointerToY = 15;

  printf("%d\n", x + y);

  // Utilizando um exemplo de array.
  int arr[] = {1, 2, 4, 8, 16, 32};
  int *p_arr = arr;

  printf("Imprimindo array: \n");
  for (int i = 0; i < 6; i++)
    printf("%d ", p_arr[i]);
  printf("\n");

  // Invertendo os valores de início e fim.
  int t = *p_arr;
  *p_arr = *(p_arr + 5);
  *(p_arr + 5) = t;

  printf("%d\n", t);
  printf("%d\n", *p_arr);

  printf("Invertendo valores extremos: \n");
  for (int i = 0; i < 6; i++)
    printf("%d ", p_arr[i]);
  printf("\n");

  // Utilizando um exemplo de struct.
  sPessoa admin = {"John", 3}, *p_admin = &admin;

  printf("Nome: %s\n", p_admin->nome);
  // Uma alternativa para ponteiro -> membro.
  printf("Tempo de servico: %d\n", (*p_admin).tempoDeServico);

  // Alocação dinâmica de memória

  int *ponteiro = NULL, tamanho;

  printf("Tamanho de array: ");
  scanf("%d", &tamanho);

  ponteiro = (int*) malloc(sizeof(int) * tamanho);

  for (int i = 0; i < tamanho; i++)
    ponteiro[i] = i;
  
  for (int i = 0; i < tamanho; i++)
    printf("%d ", ponteiro[i]);
  printf("\n");
  
  free(ponteiro);

  // Alocando memória de um registro.
  sPessoa *pessoa = (sPessoa*) malloc(sizeof(sPessoa));

  // Condição necessária para o caso da alocação ter falhado.
  if (!pessoa)
    exit(1);

  strcpy(pessoa->nome, "Maria");
  pessoa->tempoDeServico = 12;

  printf("Nome: %s\n", pessoa->nome);
  printf("Tempo de servico: %d\n", pessoa->tempoDeServico);

  // Ponteiro de ponteiro
  int i = 19, *p_i = &i, **p_p_i = &p_i;

  printf("%d ", i);
  printf("%d ", *p_i);
  printf("%d\n", **p_p_i);

  a = 5;
  c = 9;

  printf("A soma de a + c = %d\n", sum(a, c));

  char str[100];
  copia_str(str, "Testando uma manipulacao com strings");

  printf("%s\n", str);

  int num = 8;
  dobraNumero(&num); // Passando seu endereço como parâmetro.

  printf("%d\n", num);

  printf("%d\n", fatorial(num));

  copiaStrRecursiva(str, "Testando uma manipulacao recursiva com strings");
  printf("%s\n", str);

  return 0;
}

int sum(int a, int b) {
  return a + b;
}

char *copia_str(char *str1, char *str2) {
  char *str = str1;
  
  while (*str2) {
    *str1 = *str2;
    str1++, str2++;
  }
  *str1 = '\0';
  
  return str1;
}

void dobraNumero(int *num) {
  *num *= 2;
  return;
}

int fatorial(int num) {
  if (num == 0)
    return 1;
  
  return num * fatorial(num - 1);
}

char *copiaStrRecursiva(char *str1, char *str2) {
  if (!*str2) {
    *str1 = '\0';
    return NULL;
  }
  
  *str1 = *str2;
  copiaStrRecursiva(str1 + 1, str2 + 1);
}
