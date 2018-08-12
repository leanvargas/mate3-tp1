#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menuPantalla();

int main ()
{
    const char USUARIO[4]="123";
    const char CONTRASENA[4]="121";

    int valorDeHora=300;
    //cargar en una matriz los nombres de los analistas
    //cargar en una matriz los datos a ingresar, siendo las filas los analistas y las columnas los proyectos.

    char opcion='0';
    char contrasena[4];
    char usuario[4];
    int intentos=0;
    int datosIngresados= 0;


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

    //salgo del programa al haber hecho mas de 3 intentos
    if (intentos==3){
      return 0;
    }

    while(opcion!='9'){
      opcion = menuPantalla();
    }

    return 0;
}

void menu(char opcion){
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

char menuPantalla(){
  char opcion;

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

    printf("ingrese una opcion\n");
    scanf("%c", &opcion);
    while(getchar() !='\n');
  }while(opcion<'0' || opcion>'9');

  return opcion;

}
