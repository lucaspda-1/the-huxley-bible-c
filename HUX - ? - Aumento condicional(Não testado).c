#include <stdio.h>

int main() {
  
  float salario,aumento;
  int reajuste;

  
  
  scanf("%f", &salario);

  
  if (salario <= 280) {
    reajuste = 20;
  } else if (salario <= 700) {
    reajuste = 15;
  } else if (salario <= 1500) {
    reajuste = 10;
  } else {
    reajuste = 5;
  }

  aumento = salario * reajuste / 100;

  
  printf("%.2f\n", salario);
  printf("%d\n", reajuste);
  printf("%.2f\n", aumento);
  printf("%.2f\n", salario + aumento);

  return 0;
}
