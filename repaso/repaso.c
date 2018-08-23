#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPantalla(int *opcion);
void menu(int opcion);
int login(char *USUARIO, char *CONTRASENA);

int main ()
{
    char USUARIO[20]="123";
    char CONTRASENA[20]="121";

    int valorDeHora, numProy;
    //cargar en una matriz los nombres de los analistas
    char analistas[10][50];
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

    while(opcion<=9){
      menuPantalla(&opcion);
      menu(opcion);
    }

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


void menu(int opcion){
      switch (opcion)
        {
        /* case '0': ingresoDeDatos; break; */
        /* case '1': horasTotalesPorAnalista; break; */
        /* case '2': horasPorProyectoPorAnalista; break; */
        /* case '3': horasTotalesPorProyecto; break; */
        /* case '4': QueAnalistaTrabajoMenosEnProyecto1; break; */
        /* case '5': SueldoDeCadaAnalista; break; */
        /* case '6': AnalistaQueCrobroMas; break; */
        /* case '7': cantAnalistaTrabajaronMenosDe5enAlgunProyecto; break; */
        /* case '8': sueldosDeAnalista; break; */
        }
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


