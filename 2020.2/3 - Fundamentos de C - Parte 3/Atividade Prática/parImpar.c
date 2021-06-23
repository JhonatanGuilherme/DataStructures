#include <stdio.h>
#include <string.h>
#define MAX 15

int printList(int counter, int *list) {
  if (list[0] % 2 == 0) {
    for (int i = 0; i < counter; i++) {
      printf("par[%d] = %d\n", i, list[i]);
    }
  } else {
    for (int i = 0; i < counter; i++) {
      printf("impar[%d] = %d\n", i, list[i]);
    }
  }
  
  return 0;
}

int main(void) {
  int counterI = 0, counterP = 0, value, valuesI[MAX], valuesP[MAX];

  for (int i = 0; i < 15; i++) {
    scanf("%d", &value);
    //setbuf(stdin, NULL);
    if (value % 2 == 0) {
      valuesP[counterP] = value;
      counterP ++;
    } else {
      valuesI[counterI] = value;
      counterI ++;
    }
    if (counterI >= 5)
      counterI = printList(counterI, valuesI);
    if (counterP >= 5)
      counterP = printList(counterP, valuesP);
  }

  printList(counterI, valuesI);
  printList(counterP, valuesP);

  return 0;
}
