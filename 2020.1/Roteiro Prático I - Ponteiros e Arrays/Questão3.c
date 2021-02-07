#include <stdio.h>

int main(void) {

  int A[10], cont;
  double media;

  for (int i = 0; i < 10; i ++){
    printf("Digite sua nota: ");
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < 10; i ++){
    media += A[i];
    if (A[i] > 69){
      cont ++;
    }  
  }
  printf("%.1lf\n%d\n", (media / 10), cont);

  return 0;
}
