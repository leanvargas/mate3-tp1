#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RELACION_SIZE 4
#define RELACION_PARES_SIZE 2

void menuPantalla(int *opcion);
void ingresoDeDatos(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void imprimirRelacion(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarDominio(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarRango(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);
void determinarReflexividad(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]);


int main ()
{
  int opcion=1;
  int relacion[RELACION_SIZE][RELACION_PARES_SIZE];

  /* ==================== */
  /* Menu del programa */
  /* ==================== */
  do{
    menuPantalla(&opcion);
    switch (opcion)
      {
      case 0: ingresoDeDatos(relacion); break;
      case 1: determinarDominio(relacion); break;
      case 2: determinarRango(relacion); break;
      case 3: determinarReflexividad(relacion); break;
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

void ingresoDeDatos(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i;

  printf("Ingresar relacion: \n");
  for(i=0;i<RELACION_SIZE;i++){
    printf("Par %d primer valor: \n", (i+2)/2);
    scanf("%d", &relacion[i][0]);
    while(getchar() !='\n');
    printf("Par %d segundo valor: \n", (i+2)/2);
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

/* void devolverDominio(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){ */
/*   int i, dominio[RELACION_SIZE]; */

/*   for(i=0;i<RELACION_SIZE;i++){ */
/*     dominio[i]=relacion[i][0]; */
/*   } */

/*   return dominio; */
/* } */

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

void determinarReflexividad(int relacion[RELACION_SIZE][RELACION_PARES_SIZE]){
  int i, j, dominio[RELACION_SIZE];
  int esReflexiva; //0 es true y 1 false

  //Dominio de la relacion
  for(i=0;i<RELACION_SIZE;i++){
    dominio[i] = relacion[i][0];
  }

  for(i=0;i<RELACION_SIZE;i++){
    //Lo seteo en NO es reflexiva para el siguien nro del dominio
    esReflexiva=1;
    for(j=0;j<RELACION_SIZE;j++){
      //si el primer valor del par en la relacion es = al primer valor del dominio
      // me fijo si el 2do tambien lo es. Si se recorre toda la relacion y ninguno lo es,
      // no es una relacion reflexiva
      if(relacion[j][0]==dominio[i]){
        if(relacion[j][1]==dominio[i]){
          esReflexiva=0;
          j=RELACION_SIZE;
        }
      }
    }
    //Si no es reflexiva, salgo del for
    if(esReflexiva==1){
      i=RELACION_SIZE;
    }

  }
    if(esReflexiva==0){
      printf("La relacion es reflexiva\n");
    }else{
      printf("La relacion NO es reflexiva\n");
    }

}
