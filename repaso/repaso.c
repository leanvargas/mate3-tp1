#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPantalla(int *opcion);
int login(char *USUARIO, char *CONTRASENA);
void ingresoDeDatos(int *valorDeHora, int f, int c, char analistas[f][c]);
void imprimirDatosIngresados(int *valorDeHora, int f, int c, char analistas[f][c]);

int main ()
{
    char USUARIO[20]="123";
    char CONTRASENA[20]="121";

    int valorDeHora, numProy;
    //cargar en una matriz los nombres de los analistas
    int analistasF=2, analistasC=50;
    char analistas[analistasF][analistasC];
    //cargar en una matriz los datos a ingresar, siendo las filas los analistas y las columnas los proyectos.
    int proyectos[numProy][4];

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
        case 0 :ingresoDeDatos(&valorDeHora, analistasF, analistasC, analistas); break;
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

void ingresoDeDatos(int *valorDeHora, int f, int c, char analistas[f][c]){
  int i=0;

  printf("Ingresar el valor de la hora \n");
  scanf("%d", valorDeHora);
  while(getchar() !='\n');

  for(int i;i<f;i++){
    printf("Ingresar analista nro %d \n", i+1);
    scanf("%s", analistas[i]);
    while(getchar() !='\n');
  }

  imprimirDatosIngresados(valorDeHora, f, c, analistas);
}

void imprimirDatosIngresados(int *valorDeHora, int f, int c, char analistas[f][c]){
  int i=0;

  printf("El valor de la hora es: %d\n", *valorDeHora);

  for(int i;i<f;i++){
    printf("El analista nro %d es: %s\n", i+1, analistas[i]);
  }
}

