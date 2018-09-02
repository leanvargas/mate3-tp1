#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPantalla(int *opcion);
int login(char *USUARIO, char *CONTRASENA);
void ingresoDeDatos(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]);
void imprimirDatosIngresados(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]);

int main ()
{
    char USUARIO[20]="123";
    char CONTRASENA[20]="121";

    int valorDeHora;
    //cargar en una matriz los nombres de los analistas
    int analistasF=2, analistasC=50;
    char analistas[analistasF][analistasC];

    /* cargar en una matriz los datos a ingresar, siendo:
       1ra columna: Nro de trabajo
       2da columna: Numero de analista
       3er columna: Numero de proyecto
       4ta columna: Cantidad de hs trabajadas
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
          /* case '1': horasTotalesPorAnalista; break; */
          /* case '2': horasPorProyectoPorAnalista; break; */
          /* case '3': horasTotalesPorProyecto; break; */
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
  int i, j, numDeTrabajo=1;

  printf("Ingresar el valor de la hora: \n");
  scanf("%d", valorDeHora);
  while(getchar() !='\n');

  for(i=0;i<f;i++){
    printf("Ingresar analista nro: %d \n", i+1);
    scanf("%s", analistas[i]);
    while(getchar() !='\n');
  }

  for(i=0;i<*proyectosF;i++){
    for(j=0;j<proyectosC;j++){
      printf("Ingresar nro de trabajo: \n");
      scanf("%d", &numDeTrabajo);
      while(getchar() !='\n');
      if(numDeTrabajo==0){
        //dejo de cargar proyectos y agrego a proyectosF la cantidad de filas que tiene la matriz
        *proyectosF=i;
        i=0;
        j=proyectosC;
      }else{
        proyectos[i][j] = numDeTrabajo;
        printf("Ingresar nro de analista: \n");
        scanf("%d", &proyectos[i][j]);
        while(getchar() !='\n');
        printf("Ingresar nro de proyecto: \n");
        scanf("%d", &proyectos[i][j]);
        while(getchar() !='\n');
        printf("Ingresar nro de horas trabajadas: \n");
        scanf("%d", &proyectos[i][j]);
        while(getchar() !='\n');
      }
    }
  }

  imprimirDatosIngresados(valorDeHora, f, c, analistas, proyectosF, proyectosC, proyectos);
}

void imprimirDatosIngresados(int *valorDeHora, int f, int c, char analistas[f][c], int *proyectosF, int proyectosC, int proyectos[*proyectosF][proyectosC]){
  int i;

  printf("El valor de la hora es: %d\n", *valorDeHora);

  for(i=0;i<f;i++){
    printf("El analista nro %d es: %s\n", i+1, analistas[i]);
  }
  for(i=0;i<*proyectosF;i++){
    printf("Trabajos: \n");
    printf("Numero \t Analista \t Proyecto \t Horas Trabajadas \n");
    printf("%d \t %d \t\t %d \t\t %d \n", proyectos[i][0], proyectos[i][1], proyectos[i][2], proyectos[i][3]);
  }
}

