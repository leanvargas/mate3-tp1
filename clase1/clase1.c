#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RELACION_SIZE 4
#define RELACION_PARES_SIZE 2
#define CONJUNTO_SIZE 4

void menuPantalla(int *opcion);
void ingresoDeDatos(int conjunto[CONJUNTO_SIZE], int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void imprimirRelacion(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarDominio(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarRango(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarReflexividad(int conjunto[CONJUNTO_SIZE], int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarAntisimetria(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarTransitividad(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
int verificarPar(int numDominio, int numRango, int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);


int main ()
{
  int opcion=1;
  int relacion[RELACION_SIZE][RELACION_PARES_SIZE];
  int conjunto[CONJUNTO_SIZE];

  /* ==================== */
  /* Menu del programa */
  /* ==================== */
  do{
    menuPantalla(&opcion);
    switch (opcion)
      {
      case 0: ingresoDeDatos(conjunto, relacion); break;
      case 1: determinarDominio(relacion); break;
      case 2: determinarRango(relacion); break;
      case 3: determinarReflexividad(conjunto, relacion); break;
      case 4: determinarAntisimetria(relacion); break;
      case 5: determinarTransitividad(relacion); break;
      }
  }while(opcion<6);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Ingresar datos\n");
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

void ingresoDeDatos(int conjunto[CONJUNTO_SIZE], int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i;

  printf("Ingresar conjunto: \n");
  for(i=0;i<CONJUNTO_SIZE;i++){
    printf("Valor %d: \n", (i+1));
    scanf("%d", &conjunto[i]);
    while(getchar() !='\n');
  }

  printf("Ingresar relacion: \n");
  for(i=0;i<RELACION_SIZE;i++){
    printf("Par %d primer valor: \n", i+1);
    scanf("%d", &relacion[i][0]);
    while(getchar() !='\n');
    printf("Par %d segundo valor: \n", i+1);
    scanf("%d", &relacion[i][1]);
    while(getchar() !='\n');
  }

  imprimirRelacion(relacion);
}

void imprimirRelacion(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i;

  printf("Relacion AxB={ ");
  for(i=0;i<RELACION_SIZE;i++){
    printf("(%d,%d) ", relacion[i][0], relacion[i][1]);
  }
  printf("}\n");
}

void determinarDominio(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i;

  printf("El dominio de la relacion ");
  imprimirRelacion(relacion);
  printf("es: \n");

  printf("{ ");
  for(i=0;i<RELACION_SIZE;i++){
    printf("%d ", relacion[i][0]);
  }
  printf("}\n");
}

void determinarRango(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i;

  printf("El rango de la relacion ");
  imprimirRelacion(relacion);
  printf("es: \n");

  printf("{ ");
  for(i=0;i<RELACION_SIZE;i++){
    printf("%d ", relacion[i][1]);
  }
  printf("}\n");
}

void determinarReflexividad(int conjunto[CONJUNTO_SIZE], int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i, j, dominio[RELACION_SIZE];
  int encontroPar; //0 es true y 1 false

  //Dominio de la relacion
  for(i=0;i<RELACION_SIZE;i++){
    dominio[i] = relacion[i][0];
  }

  for(i=0;i<CONJUNTO_SIZE;i++){
    encontroPar=1;
    for(j=0;j<RELACION_SIZE;j++){
      if(conjunto[i]==relacion[j][0] && conjunto[i]==relacion[j][1]){
        encontroPar=0;
        j=RELACION_SIZE;
      }
    }
    //Si no es reflexiva, salgo del for
    if(encontroPar==1){
      i=RELACION_SIZE;
    }

  }
    if(encontroPar==0){
      printf("La relacion es reflexiva\n");
    }else{
      printf("La relacion NO es reflexiva\n");
    }

}

void determinarAntisimetria(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i, j, numDominio, numRango;
  int esAntisimetrica; //0 es true y 1 false

  for(i=0;i<RELACION_SIZE;i++){
    esAntisimetrica=1;
    if(relacion[i][0]!=relacion[i][1]){
      esAntisimetrica = verificarPar(relacion[i][1], relacion[i][0], relacion);
      if(esAntisimetrica==0){
        i=RELACION_SIZE;
      }
    }
  }
  if(esAntisimetrica==1){
    printf("La relacion es antisimetrica\n");
  }else{
    printf("La relacion NO es antisimetrica\n");
  }

}

void determinarTransitividad(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i, j, numDominio, numRango;
  int esTransitiva; //0 es true y 1 false

  for(i=0;i<RELACION_SIZE;i++){
    esTransitiva=1;
    numDominio=relacion[i][0];
    numRango=relacion[i][1];
    for(j=0;j<RELACION_SIZE;j++){
      if(relacion[j][0]==numRango){
        numRango=relacion[j][1];
        esTransitiva = verificarPar(numDominio, numRango, relacion);
        j=RELACION_SIZE;
      }
    }
    if(esTransitiva==1){
      i=RELACION_SIZE;
    }
  }
  if(esTransitiva==0){
    printf("La relacion es transitiva\n");
    printf("mierda\n");
  }else{
    printf("La relacion NO es transitiva\n");
  }

}

int verificarPar(int numDominio, int numRango, int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i, test, tienePar=1; //0=encontro el par, 1 = no lo encontro

  for(i=0;i<RELACION_SIZE;i++){
    test = (relacion[i][0]==numDominio && relacion[i][1]==numRango);
    if(test){
      i=RELACION_SIZE;
      tienePar=0;
    }
  }

    return tienePar;
}
