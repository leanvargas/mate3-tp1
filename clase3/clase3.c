#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPantalla(int *opcion);
void verificarPrimo();

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
      case 0: verificarPrimo(); break;
      }
  }while(opcion<1);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Verificar numero primo\n");
    printf("1:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>1);

}

void verificarPrimo(){
  int i, num, esPrimo=0; //0 es true, 1 es false

  printf("Ingresar un numero entero positivo:\n");
  scanf("%d", &num);
  while(getchar() !='\n');

  if(num>2){
    for(i=2;i<num;i++){
      if(num%i==0){
        esPrimo=1;
        i=num;
      }
    }
  }

  if(esPrimo==0){
    printf("El numero %d es primo\n", num);
  }else{
    printf("El numero %d NO es primo\n", num);
  }

}
