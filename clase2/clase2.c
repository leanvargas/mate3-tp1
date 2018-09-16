#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcularFactorial();
int funcionFactorial(int num);
void menuPantalla(int *opcion);

int main ()
{
  int opcion=1;

  /* ==================== */
  /* Menu del programa */
  /* ==================== */
  do{
    menuPantalla(&opcion);
    switch (opcion)
      {
      case 0: calcularFactorial(); break;
      /* case 1: calcularFibonacci(num); break; */
      }
  }while(opcion<2);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Calcular factorial\n");
    printf("1:Calcular Fibonacci\n");
    printf("2:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>2);

}

void calcularFactorial(){
  int num;

  printf("Ingresar un numero:\n");
  scanf("%d", &num);
  while(getchar() !='\n');

  printf("El factorial de %d es: %d\n", num, funcionFactorial(num));

}

int funcionFactorial(int num){
  if(num>=1){
    return num*funcionFactorial(num-1);
  }else{
    return 1;
  }
}
