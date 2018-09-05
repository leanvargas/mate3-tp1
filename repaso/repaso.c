#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPantalla(int *opcion);
void horasTotalesPorAnalista(int f, int c, char analistas[f][c], int proyectosF, int proyectosC, int proyectos[proyectosF][proyectosC]);
int login(char *USUARIO, char *CONTRASENA);
void ingresoDeDatos(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]);
void imprimirDatosIngresados(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]);
void horasTotalesPorProyecto(int proyectosF, int proyectosC, int proyectos[proyectosF][proyectosC]);

int main ()
{
    char USUARIO[20]="123";
    char CONTRASENA[20]="123";

    int valorDeHora;
    //cargar en una matriz los nombres de los analistas, el nro de analista es el numero de fila + 1
    int analistasF=2, analistasC=50;
    char analistas[analistasF][analistasC];

    /* cargar en una matriz los datos a ingresar, siendo:
       1ra columna: Nro de trabajo
       2da columna: Numero de analista
       3er columna: Numero de proyecto
       4ta columna: Cantidad de hs trabajadas

       Se supone que los proyectos van del 1 al 15, que puede haber 15 en total nada mas
     */
    int proyectosF=1, proyectosC=4, proyectos[proyectosF][proyectosC];

    int opcion=0, datosIngresados=0;

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
        case 0 :ingresoDeDatos(&valorDeHora, analistasF, analistasC, analistas, &proyectosF, proyectosC, proyectos); break;
        case 1: horasTotalesPorAnalista(analistasF, analistasC, analistas, proyectosF, proyectosC, proyectos); break;
        /* case 2: horasPorProyectoPorAnalista(analistasF, analistasC, analistas, proyectosF, proyectosC, proyectos); break; */
        case 3: horasTotalesPorProyecto(proyectosF, proyectosC, proyectos); break;
          /* case '4': QueAnalistaTrabajoMenosEnProyecto1; break; */
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
    //este while es porque el scanf no funciona en linux
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

void ingresoDeDatos(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]){
  //Se ingresa la variable proyectosF como puntero ya que se va a modificar dependiendo la cant de trabajos que haya
  int i, numDeTrabajo=1;

  printf("Ingresar el valor de la hora: \n");
  scanf("%d", valorDeHora);
  while(getchar() !='\n');

  for(i=0;i<f;i++){
    printf("Ingresar analista nro: %d \n", i+1);
    scanf("%s", analistas[i]);
    while(getchar() !='\n');
  }

  i=0;
  printf("Ingresar nro de trabajo: \n");
  scanf("%d", &numDeTrabajo);
  while(getchar() !='\n');
  do{
    proyectos[i][0] = numDeTrabajo;
    printf("Ingresar nro de analista: \n");
    scanf("%d", &proyectos[i][1]);
    while(getchar() !='\n');
    printf("Ingresar nro de proyecto: \n");
    scanf("%d", &proyectos[i][2]);
    while(getchar() !='\n');
    printf("Ingresar nro de horas trabajadas: \n");
    scanf("%d", &proyectos[i][3]);
    while(getchar() !='\n');
    printf("Ingresar nro de trabajo: \n");
    scanf("%d", &numDeTrabajo);
    while(getchar() !='\n');
    i++;
  }while(numDeTrabajo!=0);
  *proyectosF=i;

  imprimirDatosIngresados(valorDeHora, f, c, analistas, proyectosF, proyectosC, proyectos);
}



void imprimirDatosIngresados(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]){
  int i;

  printf("El valor de la hora es: %d\n", *valorDeHora);

  for(i=0;i<f;i++){
    printf("El analista nro %d es: %s\n", i+1, analistas[i]);
  }

  printf("Trabajos: \n");
  for(i=0;i<*proyectosF;i++){
    printf("Numero \t Analista \t Proyecto \t Horas Trabajadas \n");
    printf("%d \t %d \t\t %d \t\t %d \n", proyectos[i][0], proyectos[i][1], proyectos[i][2], proyectos[i][3]);
  }
}

void horasTotalesPorAnalista(int f, int c, char analistas[f][c], int proyectosF, int proyectosC, int proyectos[proyectosF][proyectosC]){
  int i, j, horasAcumuladas=0, nroAnalista;

  for(i=0;i<f;i++){
    nroAnalista=i+1;
    for(j=0;j<proyectosF;j++){
      if(nroAnalista==proyectos[j][1]){
        horasAcumuladas+=proyectos[j][3];
      }
    }
    printf("El analista nro %d trabajo %d horas\n", i+1, horasAcumuladas);
    horasAcumuladas=0;
  }
}

void horasTotalesPorProyecto(int proyectosF, int proyectosC, int proyectos[proyectosF][proyectosC]){
  int i, j, horasAcumuladas=0, nroProyecto;

  for(i=0;i<15;i++){
    nroProyecto=i+1;
    for(j=0;j<proyectosF;j++){
      if(nroProyecto==proyectos[j][2]){
        horasAcumuladas+=proyectos[j][3];
      }
    }
    if(horasAcumuladas!=0){
      printf("Se trabajo %d horas en el proyecto %d\n", horasAcumuladas, nroProyecto);
      horasAcumuladas=0;
    }
  }
}
