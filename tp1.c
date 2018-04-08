#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct drogas
{
  char codigoDroga[3];
  float costo;
};

struct remedios
{
  char codigoRemedio[3];
  char codigoDroga[3];
  int cantidad; //cantidad de remedios disponibles
};

struct ventas
{
  int nroFactura;
  char codigoRemedio[3];
  int cantidadVendida;
};


int login(char *USUARIO, char *CONTRASENA);
void ingresarDatos(FILE *remediosFile, FILE *drogasFile, FILE *ventasFile);
char menu();
void facturacionTotal();

int main ()
{
    const char USUARIO[16]="123";
    const char CONTRASENA[11]="123";
    char opcion='0';
    char contrasena[11];
    char usuario[16];
    int intentos=0;
    int datosIngresados= 0;
    int i;

    FILE *remediosFile;
    FILE *drogasFile;
    FILE *ventasFile;
    /* struct remedios remedio[300]; //15 remedios distintos * 20 drogas como maximo cada remedio */
    /* struct drogas droga[200]; //200 drogas como maximo en el laboratorio */
    /* struct ventas venta[15]; //15 ventas como maximo, una por cada remedio del laboratorio */


    /* si la cantidad de remedios con distinto codigo es >15,
       no permitirle agregar mas */

    /* si la cantidad de drogas es > 200, no permitir agregar mas */



    do{
      printf("Ingresar usuario: \n");
      scanf("%s", usuario);
      //este while es porque el scanf no funciona en linux
      while(getchar() !='\n');
      printf("Ingresar contraseña: \n");
      scanf("%s", contrasena);
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
        ingresarDatos(remediosFile, drogasFile, ventasFile);
        datosIngresados=1;
      }else if (datosIngresados==1 && opcion=='0'){
        printf("Ya hay datos ingresados. \n");
      }else{
        switch (opcion)
          {
            /* case '1': emitir(); break; */
          case '2': facturacionTotal(remediosFile, drogasFile, ventasFile); break;
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

void ingresarDatos(FILE *remediosFile, FILE *drogasFile, FILE *ventasFile){
   /* ingresar en 3 archivos diferentes los datos que se piden. */
  char seguirCargando;

  struct remedios remedio;
  struct drogas droga;
  struct ventas venta;

  //cargo un remedio
  printf("----------- Datos del remedio ------------ \n");

  do{
    remediosFile = fopen("remedios.dat","wb+");
    fseek(remediosFile,0,SEEK_END);

    printf("ingresar codigo del remedio: \n");
    scanf("%s", remedio.codigoRemedio);
    while(getchar()!='\n');

    printf("Ingresar codigo de la droga: \n");
    scanf("%s", remedio.codigoDroga);
    while(getchar()!='\n');

    printf("Ingresar la cantidad: \n");
    scanf("%d", &remedio.cantidad);
    while(getchar()!='\n');

    fwrite(&remedio,sizeof(struct remedios),1,remediosFile);

    do{
      printf("Seguir cargando remedio?(s/n) \n");
      scanf("%c", &seguirCargando);
      while(getchar()!='\n');
    }while(seguirCargando!='s' && seguirCargando!='n');

  }while(seguirCargando=='s');
  fclose(remediosFile);

  //cargo una droga
  printf("----------- Datos de la droga ------------ \n");

  do{
    drogasFile = fopen("drogas.dat","wb+");
    fseek(drogasFile,0,SEEK_END);

    printf("Ingresar codigo de la droga: \n");
    scanf("%s", droga.codigoDroga);
    while(getchar()!='\n');

    printf("Ingresar costo de la droga: \n");
    scanf("%f", &droga.costo);
    while(getchar()!='\n');

    fwrite(&droga,sizeof(struct drogas),1,drogasFile);

    do{
      printf("Seguir cargando drogas?(s/n) \n");
      scanf("%c", &seguirCargando);
      while(getchar()!='\n');
    }while(seguirCargando!='s' && seguirCargando!='n');

  }while(seguirCargando=='s');
  fclose(drogasFile);

  //cargo una venta
  printf("----------- Datos de la venta ------------ \n");

  do{
    ventasFile = fopen("ventas.dat","wb+");
    fseek(ventasFile,0,SEEK_END);

    printf("Ingresar numero de factura: \n");
    scanf("%d", &venta.nroFactura);
    while(getchar()!='\n');

    printf("Ingresar codigo del remedio: \n");
    scanf("%s", venta.codigoRemedio);
    while(getchar()!='\n');

    printf("Ingresar cantidad de ventas: \n");
    scanf("%d", &venta.cantidadVendida);
    while(getchar()!='\n');

    fwrite(&venta,sizeof(struct ventas),1,ventasFile);

    do{
      printf("Seguir cargando ventas?(s/n) \n");
      scanf("%c", &seguirCargando);
      while(getchar()!='\n');
    }while(seguirCargando!='s' && seguirCargando!='n');

  }while(seguirCargando=='s');
  fclose(ventasFile);

}

void facturacionTotal(FILE *remediosFile, FILE * ventasFile, FILE *drogasFile){
  struct remedios remedio;
  struct drogas droga;
  struct ventas venta;

  float ventaTotal = 0;

  drogasFile= fopen("drogas.dat","rb");
  remediosFile= fopen("remedios.dat","rb");
  ventasFile= fopen("ventas.dat","rb");

  /* Agarro una venta */
  while(fread(&venta,sizeof(struct ventas),1,ventasFile)){
    /* Busco el remedio con ese codigo */
    while(fread(&remedio,sizeof(struct remedios),1,remediosFile)){
      if (strcmp(remedio.codigoRemedio, venta.codigoRemedio)==0){
        /* Busco la droga y almaceno el costo */
        while(fread(&droga,sizeof(struct drogas),1,drogasFile)){
          if (strcmp(remedio.codigoDroga, droga.codigoDroga)==0){
            ventaTotal +=droga.costo;
          }
        }
      }
    }
  }
  fclose(drogasFile);
  fclose(remediosFile);
  fclose(ventasFile);

  printf("El valor total de ventas es: %.2f \n", ventaTotal);
}
