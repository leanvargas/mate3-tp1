#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_SIZE 4

void menuPantalla(int *opcion);
void matrizAleatoriaAdyacente(int matriz[MATRIX_SIZE][MATRIX_SIZE]);
void imprimirMatriz(int matriz[MATRIX_SIZE][MATRIX_SIZE]);


int main ()
{
  int opcion=1;
  int matriz[MATRIX_SIZE][MATRIX_SIZE];

  /* ==================== */
  /* Menu del programa */
  /* ==================== */
  do{
    menuPantalla(&opcion);
    switch (opcion)
      {
      case 0: matrizAleatoriaAdyacente(matriz); break;
      case 1: imprimirMatriz(matriz); break;
        /*      case 3: determinarReflexividad(conjunto, relacion); break;
      case 4: determinarAntisimetria(relacion); break;
      case 5: determinarTransitividad(relacion); break;
*/
      }
  }while(opcion<6);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Generar matriz aleatoria adyacente\n");
    printf("1:Imprimir matriz, aristas, lazos y grado de los vertices\n");
    printf("2:Determinar el rango de la relacion\n");
    printf("3:Determinar si una relacion es reflexiva\n");
    printf("4:Determinar si una relacion es anti simetrica\n");
    printf("5:Determinar si una relacion es transitiva\n");
    printf("7:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>7);

}

void matrizAleatoriaAdyacente(int matriz[MATRIX_SIZE][MATRIX_SIZE]){
  int i, j, numRandom;

  for(i=0;i<MATRIX_SIZE;i++){
    for(j=0;j<MATRIX_SIZE;j++){
	    if(i<j){
        numRandom = rand() % 2;
        matriz[i][j]=numRandom;
        matriz[j][i]=numRandom;
	    }else if(i==j){
        numRandom = rand() % 2;
        matriz[i][j]= numRandom;
	    }
    }
  }

}

void imprimirMatriz(int matriz[MATRIX_SIZE][MATRIX_SIZE]){
  int i, j, numUno=0, lazos=0, sumVertices=0;

  printf("-------------------- \n");

  for(j=0;j<MATRIX_SIZE;j++){
    numUno=0;
    for(i=0;i<MATRIX_SIZE;i++){
	    if(matriz[i][j]==1){
        numUno+=1;
      }
    }
    if(numUno==1){
      lazos+=1;
    }
  }

  for(i=0;i<MATRIX_SIZE;i++){
    numUno=0;
    for(j=0;j<MATRIX_SIZE;j++){
      if(matriz[i][j]==1){
        numUno+=1;
      }
    }
    printf("El grado del vertice %d es: %d \n", i+1,numUno);

    sumVertices+=numUno;
  }

  printf("\n");
  printf("-------------------- \n");

  printf("El numero de lazos es: %d \n", lazos);

  printf("El numero de aristas es: %d \n", sumVertices/2);
}
