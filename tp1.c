#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct remedios
{
  char codigoRemedio[3];
  char codigoDroga[3];
  int cantidad;
};

struct drogas
{
  char codigoDroga[3];
  float costo;
};

struct ventas
{
  int nroFactura;
  char codigoRemedio[3];
  int cantidadVendida;
};


int login(char *USUARIO, char *CONTRASENA);
void ingresarDatos(FILE *remedios, FILE *drogas, FILE *ventas);
char menu();

int main ()
{
    const char USUARIO[16]="usuario";
    const char CONTRASENA[11]="contra1234";
    char opcion='0';
    char contrasena[11];
    char usuario[16];
    int intentos=0;
    int datosIngresados= 0;

    FILE *remedios;
    FILE *drogas;
    FILE *ventas;

    do{
      printf("Ingresar usuario: \n");
      scanf("%s", &usuario);
      //este while es porque el scanf no funciona en linux
      while(getchar() !='\n');
      printf("Ingresar contraseña: \n");
      scanf("%s", &contrasena);
      while(getchar() !='\n');
      intentos ++;
    }while(((strcmp(usuario, USUARIO) != 0) || (strcmp(contrasena, CONTRASENA) != 0)) && (intentos<3));

    //salgo del programa al haber hecho mas de 3 intentos
    if (intentos==3){
      opcion = '8';
    }

    while(opcion!='8'){
      opcion = menu();
      if (datosIngresados == 0 && opcion!='0'){
        printf("Debe ingresar datos primero\n");
      }else if (datosIngresados==0 && opcion=='0'){
        ingresarDatos(remedios, drogas, ventas);
        datosIngresados=1;
      }else if (datosIngresados==1 && opcion=='0'){
        printf("Ya hay datos ingresados. \n");
      }else{
        switch (opcion)
          {
            /* case '1': emitir(); break; */
            /* case '2': facturacionTotal(); break; */
            /* case '3': facturacionRemedio(); break; */
            /* case '4': maxDrogaPorPedido(); break; */
            /* case '5': maxDrogaPorRemedio(); break; */
            /* case '6': drogaMasBarata(); break; */
            /* case '7': mayorCantidadDrogasyRemedios(); break; */
          }
      }
    }

    return 0;
}

char menu(){
  char opcion;

  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Ingresar datos\n");
    printf("1:Emitir datos\n");
    printf("2:Facturacion Total\n");
    printf("3:Facturacion por Remedio\n");
    printf("4: Droga mas usada por remedios pedidos\n");
    printf("5:Droga mas usada por remedio\n");
    printf("6:Droga mas barata\n");
    printf("7:Mayor cantidad de unidades por Droga y Remedio\n");
    printf("8:Salir\n");

    printf("ingrese una opcion\n");
    scanf("%c", &opcion);
  }while(opcion<'0' || opcion>'8');

  return opcion;

}

void ingresarDatos(FILE *remedios, FILE *drogas, FILE *ventas){
   /* ingresar en 3 archivos diferentes los datos que se piden. */
  char seguirCargando;

  struct remedios remedio;
  struct drogas droga;
  struct ventas venta;

  do{
    remedios = fopen("remedios.txt","w+");
    fseek(remedios,0,SEEK_END);
    //creo un remedio
    printf("----------- Datos del remedio ------------ \n");

    printf("ingresar codigo del remedio: \n");
    scanf("%s",&remedio.codigoRemedio);
    while(getchar()!='\n');

    printf("Ingresar codigo de la droga: \n");
    scanf("%s", &remedio.codigoDroga);
    while(getchar()!='\n');

    printf("Ingresar la cantidad: \n");
    scanf("%d", &remedio.cantidad);
    while(getchar()!='\n');

    fwrite(&remedio,sizeof(struct remedios),1,remedios);

    printf("Seguir cargando remedios?(s/n) \n");
    scanf("%c", &seguirCargando);
    while(getchar()!='\n');

  }while(seguirCargando=='s');
  fclose(remedios);

  do{
    drogas = fopen("drogas.txt","w+");
    fseek(drogas,0,SEEK_END);
    //creo una droga
    printf("----------- Datos de la droga ------------ \n");

    printf("Ingresar codigo de la droga: \n");
    scanf("%s", &droga.codigoDroga);
    while(getchar()!='\n');

    printf("Ingresar costo de la droga: \n");
    scanf("%.2f", &droga.costo);
    while(getchar()!='\n');

    fwrite(&droga,sizeof(struct drogas),1,drogas);

    printf("Seguir cargando drogas?(s/n) \n");
    scanf("%c", &seguirCargando);
    while(getchar()!='\n');

  }while(seguirCargando=='s');
  fclose(drogas);

  do{
    ventas = fopen("ventas.txt","w+");
    fseek(ventas,0,SEEK_END);
    //creo una venta
    printf("----------- Datos de la venta ------------ \n");

    printf("Ingresar numero de factura: \n");
    scanf("%d", &venta.nroFactura);
    while(getchar()!='\n');

    printf("Ingresar codigo del remedio: \n");
    scanf("%s", &venta.codigoRemedio);
    while(getchar()!='\n');

    printf("Ingresar cantidad de ventas: \n");
    scanf("%d", &venta.cantidadVendida);
    while(getchar()!='\n');

    fwrite(&venta,sizeof(struct ventas),1,ventas);

    printf("Seguir cargando ventas?(s/n) \n");
    scanf("%c", &seguirCargando);
    while(getchar()!='\n');

  }while(seguirCargando=='s');

  fclose(ventas);
}
