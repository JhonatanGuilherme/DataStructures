#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char a[20];
  int cont, cont2;
  scanf("%s", a);
  for (int i = 0; i < strlen(a); i++) {
    if (isdigit(a[i])){
      cont ++;
    }
    if (strlen(a) >= 6){
      cont2 ++;
    }
  }
  if ((cont >= 2) && (cont2 > 0)) {
    printf("SIM\n");
  } else {
    printf("NAO\n");
  }

  return 0;
}
