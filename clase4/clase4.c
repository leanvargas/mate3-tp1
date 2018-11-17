#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_SIZE 4
#define OPCIONES_MENU 2

void menuPantalla(int *opcion);
void cantidadAcumuladaCadaAnio();

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
      case 0: cantidadAcumuladaCadaAnio(); break;
        //      case 1: imprimirMatriz(matriz); break;
        /*      case 3: determinarReflexividad(conjunto, relacion); break;
      case 4: determinarAntisimetria(relacion); break;
      case 5: determinarTransitividad(relacion); break;
*/
      }
  }while(opcion<OPCIONES_MENU);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Cantidad de pesos acumulada por anio\n");
    printf("1:\n");
    printf("2:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>OPCIONES_MENU);

}

void cantidadAcumuladaCadaAnio(){
  float pesos=0;
  int i, porcentaje=0, anios=0;

  printf("Cantidad de pesos a invertir: \n");
  scanf("%f", &pesos);
  while(getchar() !='\n');

  printf("Porcentaje de interes anual: \n");
  scanf("%d", &porcentaje);
  while(getchar() !='\n');

  printf("Anios de inversion: \n");
  scanf("%d", &anios);
  while(getchar() !='\n');

  for(i=0;i<anios;i++){
    pesos=pesos + (pesos * porcentaje /100);
    printf("Los pesos acumulados en el anio %d son: %0.2f \n", i+1, pesos);
  }
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
