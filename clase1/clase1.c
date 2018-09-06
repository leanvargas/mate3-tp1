#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RELACION_SIZE 4

void menuPantalla(int *opcion);
void ingresoDeDatos(int pares, int relacion[RELACION_SIZE][pares]);
/* la relacion: AxB = {(1,2), (3,4)} Se escribe como: 1 2 (enter) 3 4 (enter) */


int main ()
{
  int pares=2, opcion=1;
  int relacion[RELACION_SIZE][pares];

  /* ==================== */
  /* Menu del programa */
  /* ==================== */
  do{
    menuPantalla(&opcion);
    switch (opcion)
      {
      case 0: ingresoDeDatos(pares, relacion); break;
      /* case 1: determinarDominio(); */
      /* case 2: determinarRango(); */
      /* case 3: determinarReflexividad(); */
      /* case 4: determinarAntisimetria(); */
      /* case 5: determinarTransitividad(); */
      }
  }while(opcion<6);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Ingresar relacion\n");
    printf("1:Determinar el dominio de la relacion\n");
    printf("2:Determinar el rango de la relacion\n");
    printf("3:Determinar si una relacion es reflexiva\n");
    printf("4:Determinar si una relacion es anti simetrica\n");
    printf("5:Determinar si una relacion es transitiva\n");
    printf("6:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>6);

}

void ingresoDeDatos(int pares, int relacion[RELACION_SIZE][pares]){
  int i;

  for(i=0;i<RELACION_SIZE;i++){
    printf("Ingresar relacion: \n");
    printf("Par %d, valor %d: \n", i, i%2+1);
  }
}
