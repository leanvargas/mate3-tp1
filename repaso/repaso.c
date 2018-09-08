#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ========== NOTA =========== */
/* En Linux no funciona el gets y los scanf tienen que estar seguidos de un: */
/* while(getchar() !='\n'); */
/* Si se usa en windows, se puede usar un gets directamente. */
/*   ========================= */

#define CANTIDAD_ANALISTAS 2

void menuPantalla(int *opcion);
void horasTotalesPorAnalista(int c, char analistas[CANTIDAD_ANALISTAS][c], int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]);
int login(char *USUARIO, char *CONTRASENA);
void ingresoDeDatos(int valorDeHora[CANTIDAD_ANALISTAS], int c, char analistas[CANTIDAD_ANALISTAS][c], int *trabajosF, int trabajosC, int trabajos[*trabajosF][trabajosC]);
void imprimirDatosIngresados(int valorDeHora[CANTIDAD_ANALISTAS], int c, char analistas[CANTIDAD_ANALISTAS][c], int *trabajosF, int trabajosC, int trabajos[*trabajosF][trabajosC]);
void horasTotalesPorProyecto(int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]);
void horasPorProyectoPorAnalista(int c, char analistas[CANTIDAD_ANALISTAS][c], int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]);
void  QueAnalistaTrabajoMenosEnProyecto1(int c, char analistas[CANTIDAD_ANALISTAS][c], int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]);

int main ()
{
    char USUARIO[20]="123";
    char CONTRASENA[20]="123";

    //cargar en una matriz los nombres de los analistas, el nro de analista es el numero de fila + 1
    int analistasC=50;
    char analistas[CANTIDAD_ANALISTAS][analistasC];
    //el valor de la hora es un array donde la posicion + 1 es el nro de analista
    int valorDeHora[CANTIDAD_ANALISTAS];

    /* cargar en una matriz los datos a ingresar, siendo:
       1ra columna: Nro de trabajo
       2da columna: Numero de analista
       3er columna: Numero de proyecto
       4ta columna: Cantidad de hs trabajadas

       Supongo que los proyectos van del 1 al 15.
     */
    int trabajosF=1, trabajosC=4, trabajos[trabajosF][trabajosC];

    int opcion=0;

    /* =================== */
    /* Funcion de login */
    /* =================== */
    if (login(USUARIO, CONTRASENA)==3){
      printf("Se ingresaron mal el usuario y/o password\n");
      return 1;
    }
    /* ===================== */

    /* ==================== */
    /* Menu del programa */
    /* ==================== */
    do{
      menuPantalla(&opcion);
      switch (opcion)
        {
        case 0 :ingresoDeDatos(valorDeHora, analistasC, analistas, &trabajosF, trabajosC, trabajos); break;
        case 1: horasTotalesPorAnalista(analistasC, analistas, trabajosF, trabajosC, trabajos); break;
        case 2: horasPorProyectoPorAnalista(analistasC, analistas, trabajosF, trabajosC, trabajos); break;
        case 3: horasTotalesPorProyecto(trabajosF, trabajosC, trabajos); break;
        case 4: QueAnalistaTrabajoMenosEnProyecto1(analistasC, analistas, trabajosF, trabajosC, trabajos); break;
          /* case '5': SueldoDeCadaAnalista; break; */
          /* case '6': AnalistaQueCrobroMas; break; */
          /* case '7': cantAnalistaTrabajaronMenosDe5enAlgunProyecto; break; */
          /* case '8': sueldosDeAnalista; break; */
        }
    }while(opcion<9);
    /* ======================= */

    return 0;
}

int login(char *USUARIO, char *CONTRASENA){
  int intentos=0;
  char contrasena[20];
  char usuario[20];

  do{
    printf("Ingresar usuario: \n");
    scanf("%s", usuario);
    while(getchar() !='\n');
    printf("Ingresar contrasenia: \n");
    scanf("%s", contrasena);
    while(getchar() !='\n');
    intentos ++;
  }while(((strcmp(usuario, USUARIO) != 0) || (strcmp(contrasena, CONTRASENA) != 0)) && (intentos<3));

  return intentos;
}


void menuPantalla(int *opcion){

  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Ingresar datos\n");
    printf("1:Horas totales por analista\n");
    printf("2:Total horas trabajadas por analista por proyecto\n");
    printf("3:Total horas trabajadas sobre cada proyecto\n");
    printf("4:Que analista trabajo menos en el proyecto 1\n");
    printf("5:Sueldo de cada analista\n");
    printf("6:Nombre del analista que cobro mas\n");
    printf("7:Cant analista que trabajaron menos de 5hs en algun proyecto\n");
    printf("8:Sueldos en forma descendente de los analistas\n");
    printf("9:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>9);

}

void ingresoDeDatos(int valorDeHora[CANTIDAD_ANALISTAS], int c, char analistas[CANTIDAD_ANALISTAS][c], int *trabajosF, int trabajosC, int trabajos[*trabajosF][trabajosC]){
  //Se ingresa la variable trabajosF como puntero ya que se va a modificar dependiendo la cant de trabajos que haya
  int i, numDeTrabajo=1;

  for(i=0;i<CANTIDAD_ANALISTAS;i++){
    printf("Ingresar nombre del analista nro: %d \n", i+1);
    scanf("%s", analistas[i]);
    while(getchar() !='\n');
    printf("Ingresar valor de hora del analista nro: %d \n", i+1);
    scanf("%d", &valorDeHora[i]);
    while(getchar() !='\n');
  }

  i=0;
  printf("Ingresar nro de trabajo: \n");
  scanf("%d", &numDeTrabajo);
  while(getchar() !='\n');
  while(numDeTrabajo!=0){
    trabajos[i][0] = numDeTrabajo;
    printf("Ingresar nro de analista: \n");
    scanf("%d", &trabajos[i][1]);
    while(getchar() !='\n');
    printf("Ingresar nro de proyecto: \n");
    scanf("%d", &trabajos[i][2]);
    while(getchar() !='\n');
    printf("Ingresar nro de horas trabajadas: \n");
    scanf("%d", &trabajos[i][3]);
    while(getchar() !='\n');
    printf("Ingresar nro de trabajo: \n");
    scanf("%d", &numDeTrabajo);
    while(getchar() !='\n');
    i++;
  }
  *trabajosF=i;

  imprimirDatosIngresados(valorDeHora, c, analistas, trabajosF, trabajosC, trabajos);
}



void imprimirDatosIngresados(int valorDeHora[CANTIDAD_ANALISTAS], int c, char analistas[CANTIDAD_ANALISTAS][c], int *trabajosF, int trabajosC, int trabajos[*trabajosF][trabajosC]){
  int i;

  for(i=0;i<CANTIDAD_ANALISTAS;i++){
    printf("El analista nro %d es: %s . Y el valor de la hora es de: %d\n", i+1, analistas[i], valorDeHora[i]);
  }

  printf("Trabajos: \n");
  for(i=0;i<*trabajosF;i++){
    printf("Numero \t Analista \t Proyecto \t Horas Trabajadas \n");
    printf("%d \t %d \t\t %d \t\t %d \n", trabajos[i][0], trabajos[i][1], trabajos[i][2], trabajos[i][3]);
  }
}

void horasTotalesPorAnalista(int c, char analistas[CANTIDAD_ANALISTAS][c], int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]){
  int i, j, horasAcumuladas=0;

  for(i=0;i<CANTIDAD_ANALISTAS;i++){
    //el nro de analista es i+1
    for(j=0;j<trabajosF;j++){
      if(i+1==trabajos[j][1]){
        horasAcumuladas+=trabajos[j][3];
      }
    }
    printf("El analista %s trabajo %d horas\n", analistas[i], horasAcumuladas);
    horasAcumuladas=0;
  }
}

void horasPorProyectoPorAnalista(int c, char analistas[CANTIDAD_ANALISTAS][c], int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]){
  int i, j, k, horasAcumuladas=0;

  //el nro de analista es i+1
  for(i=0;i<CANTIDAD_ANALISTAS;i++){
    //recorro los 15 proyectos
    for(j=1;j<16;j++){
      for(k=0;k<trabajosF;k++){
        if(i+1==trabajos[k][1]){
          if(j==trabajos[k][2]){
            horasAcumuladas+=trabajos[k][3];
          }
        }
      }
      if(horasAcumuladas!=0){
        printf("El analista %s trabajo %d horas en el proyecto %d\n", analistas[i], horasAcumuladas, j);
        horasAcumuladas=0;
      }
    }
  }
}

void horasTotalesPorProyecto(int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]){
  int i, j, horasAcumuladas=0, nroProyecto;

  for(i=0;i<15;i++){
    nroProyecto=i+1;
    for(j=0;j<trabajosF;j++){
      if(nroProyecto==trabajos[j][2]){
        horasAcumuladas+=trabajos[j][3];
      }
    }
    if(horasAcumuladas!=0){
      printf("Se trabajo %d horas en el proyecto %d\n", horasAcumuladas, nroProyecto);
      horasAcumuladas=0;
    }
  }
}

void  QueAnalistaTrabajoMenosEnProyecto1(int c, char analistas[CANTIDAD_ANALISTAS][c], int trabajosF, int trabajosC, int trabajos[trabajosF][trabajosC]){
  //Si hay mas de un analista que trabajo la misma cantidad de horas, se devuelve el primero encontrado.
  int i, k, horasAcumuladas=0, analistaMenosTrabajo=1, horasAnalistaMenosTrabajo=0;

  //el nro de analista es i+1
  for(i=0;i<CANTIDAD_ANALISTAS;i++){
    for(k=0;k<trabajosF;k++){
      if(i+1==trabajos[k][1]){
        if(1==trabajos[k][2]){
          horasAcumuladas+=trabajos[k][3];
        }
      }
    }
    if(horasAcumuladas < horasAnalistaMenosTrabajo){
      analistaMenosTrabajo = i+1;
      horasAnalistaMenosTrabajo = horasAcumuladas;
    }
  }
  printf("El analista que menos trabajo en el proyecto 1 es: %s\n", analistas[analistaMenosTrabajo]);
}
