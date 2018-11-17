#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_SIZE 4
#define OPCIONES_MENU 2

void menuPantalla(int *opcion);
void cantidadAcumuladaCadaAnio();
void mezclarSucesiones();

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
      case 1: mezclarSucesiones(); break;
      }
  }while(opcion<OPCIONES_MENU);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Cantidad de pesos acumulada por anio\n");
    printf("1:Mezclar 2 sucesiones\n");
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

void mezclarSucesiones(){
  int i, numPares[10], numImpares[10], sucesionesMezcladas[20];

  //Numeros pares
  for(i=0;i<10;i++){
    numPares[i] = i*2;
  }

  //Numeros impares
  for(i=0;i<10;i++){
    numImpares[i] = (i*2)+1;
  }

  printf("Sucesion numeros pares: \n");
  printf("%d", numPares[0]);
  for(i=1;i<10;i++){
    printf(" + ");
    printf("%d", numPares[i]);
  }
  printf("\n");

  printf("Sucesion numeros impares: \n");
  printf("%d", numImpares[0]);
  for(i=1;i<10;i++){
    printf(" + ");
    printf("%d", numImpares[i]);
  }
  printf("\n");

  printf("Sucesiones mezcladas de forma ascendente: \n");
  for(i=0;i<20;i++){
    if(i%2 == 0){
      sucesionesMezcladas[i]=numPares[i/2];
    }else{
      sucesionesMezcladas[i]=numImpares[(i-1)/2];
    }
  }

  printf("%d", sucesionesMezcladas[0]);
  for(i=1;i<20;i++){
    printf(" + ");
    printf("%d", sucesionesMezcladas[i]);
  }
  printf("\n");

  printf("Sucesiones mezcladas de forma descendente: \n");
  printf("%d", sucesionesMezcladas[19]);
  for(i=1;i<20;i++){
    printf(" + ");
    printf("%d", sucesionesMezcladas[19-i]);
  }
  printf("\n");

  printf("Sucesiones mezcladas de forma aleatoria: \n");
  for(i=1;i<20;i++){
    int temp = sucesionesMezcladas[i];
    int indice = rand() % 20;

    sucesionesMezcladas[i]=sucesionesMezcladas[indice];
    sucesionesMezcladas[indice]=temp;
  }

  printf("%d", sucesionesMezcladas[0]);
  for(i=1;i<20;i++){
    printf(" + ");
    printf("%d", sucesionesMezcladas[i]);
  }
  printf("\n");

}
