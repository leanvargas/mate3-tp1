#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct drogas
{
  int codigoDroga[200];
  float costo[200];
};

struct remedios
{
  int codigoRemedio;
  int codigoDroga[20];
  int cantidad[20]; //cantidad de droga usada
};

int login(char *USUARIO, char *CONTRASENA);
void ingresarDatos(struct drogas droga, struct remedios remedio[15]);
void facturacionTotal(struct drogas droga, struct remedios remedio[15]);
float costoDroga(struct drogas droga, int codigoDroga);
int calcularVenta(int codigoRemedio, int cantidadVendida, struct drogas droga, struct remedios remedio[15]);
void facturacionPorRemedio(struct drogas droga, struct remedios remedio[15]);
void calcularVentaPorRemedio(int codigoRemedio, int cantidadVendida, struct drogas droga, struct remedios remedio[15]);

char menu();


/* void facturacionPorRemedio(); */
/* void drogaMasBarata(); */
/* int cantRemediosTotales(); */
/* int cantidadDrogasXRemedio(); */
/* float buscarCostoDroga(); */

int main ()
{
    const char USUARIO[16]="123";
    const char CONTRASENA[11]="123";

    struct drogas droga;
    struct remedios remedio[15];

    char opcion='0';
    char contrasena[11];
    char usuario[16];
    int intentos=0;
    int datosIngresados= 0;

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
        ingresarDatos(droga, &remedio[15]);
        datosIngresados=1;
      }else if (datosIngresados==1 && opcion=='0'){
        printf("Ya hay datos ingresados. \n");
      }else{
        switch (opcion)
          {
          case '1': facturacionTotal(droga, &remedio[15]); break;
          case '2': facturacionPorRemedio(droga, &remedio[15]); break;
          /* case '4': maxDrogaPorPedido(); break; */
            /* case '5': maxDrogaPorRemedio(); break; */
          case '6': drogaMasBarata(struct drogas droga); break; 
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
    printf("1:Facturacion Total\n");
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

void ingresarDatos(struct drogas droga, struct remedios remedio[]){
   /* ingresar en 3 archivos diferentes los datos que se piden. */
  int cantidadDrogas=0;
  int i,j;
  //cargo una droga
  printf("----------- Datos de la droga ------------ \n");

  for(i=0;i<200;i++){
    printf("Ingresar codigo de la droga(entero entre 1 y 15): \n");
    scanf("%d", &droga.codigoDroga[i]);
    while(getchar()!='\n');

    printf("Ingresar costo de la droga: \n");
    scanf("%f", &droga.costo[i]);
    while(getchar()!='\n');
    

  //cargo un remedio
  printf("----------- Datos del remedio ------------ \n");

  for(i=0;i<15;i++){
    printf("ingresar codigo del remedio(entero entre 1 y 15): \n");
    scanf("%d", &remedio[i].codigoRemedio);
    while(getchar()!='\n');

    printf("Cuantos drogas va a tener el remedio? \n");
    scanf("%d", &cantidadDrogas);

    for(j=0;j<cantidadDrogas;j++){
      printf("Ingresar codigo de la droga(entero entre 1 y 200): \n");
      scanf("%d", &remedio[i].codigoDroga[i]);
      while(getchar()!='\n');

      printf("Ingresar la cantidad: \n");
      scanf("%d", &remedio[i].cantidad[i]);
      while(getchar()!='\n');
    }
  }


}

void facturacionTotal(struct drogas droga, struct remedios remedio[15]){
  float ventaTotal = 0;
  int nroFactura = 1;
  int codigoRemedio;
  int cantidadVendida;
  char seguirIngresando = 's';

  while(seguirIngresando=='s'){
    printf("Ingresar codigo de remedio de la factura %d: \n", nroFactura);
    scanf("%d", &codigoRemedio);
    while(getchar()!='\n');

    printf("Ingresar cantidad de remedios vendidos de la factura %d: \n", nroFactura);
    scanf("%d", &cantidadVendida);
    while(getchar()!='\n');

    ventaTotal += calcularVenta(codigoRemedio, cantidadVendida, droga, &remedio[15]);

    nroFactura++;
  }

  printf("El valor total de ventas es: %.2f \n", ventaTotal);
}

int calcularVenta(int codigoRemedio, int cantidadVendida, struct drogas droga, struct remedios remedio[15]){
  int i,j;
  float acum = 0;

  for(i=0;i<15;i++){
    if(remedio[i].codigoRemedio == codigoRemedio){
      for(j=0;j<20;j++){
        acum += costoDroga(droga, remedio[i].codigoDroga[j]) * cantidadVendida * 3;
      }
    }
  }

  return acum;
}

float costoDroga(struct drogas droga, int codDroga){
  // Busco el costo de la droga en el struct de drogas
  int i;
  float costoDroga;

  for(i=0;i<200;i++){
    if(droga.codigoDroga[i] == codDroga){
      costoDroga = droga.costo[i];
      i=200;
    }
  }

  return costoDroga;
}

void facturacionPorRemedio(struct drogas droga, struct remedios remedio[15]){
  int nroFactura = 1;
  int codigoRemedio;
  int cantidadVendida;
  char seguirIngresando = 's';

  while(seguirIngresando=='s'){
    printf("Ingresar codigo de remedio de la factura %d: \n", nroFactura);
    scanf("%d", &codigoRemedio);
    while(getchar()!='\n');

    printf("Ingresar cantidad de remedios vendidos de la factura %d: \n", nroFactura);
    scanf("%d", &cantidadVendida);
    while(getchar()!='\n');

    calcularVentaPorRemedio(codigoRemedio, cantidadVendida, droga, &remedio[15]);

    nroFactura++;
  }
}

void calcularVentaPorRemedio(int codigoRemedio, int cantidadVendida, struct drogas droga, struct remedios remedio[15]){
  int i,j;
  float acum = 0;

  for(i=0;i<15;i++){
    if(remedio[i].codigoRemedio == codigoRemedio){
      for(j=0;j<20;j++){
        acum += costoDroga(droga, remedio[i].codigoDroga[j]) * cantidadVendida * 3;
        printf("La facturacion por la venta del remedio %d es: %.2f", codigoRemedio, acum);
        i=15;
      }
    }
  }
}

/* ------------------------------------------------------------------ */
int cantRemediosTotales(FILE *remediosFile){
  /* devuelve la cantidad de remedios totales con diferente codigo de remedio*/
  struct remedios remedio1;
  struct remedios remedio2;

  int cantidadRemedios = 0, agregar = 1;
  int i,j;

  remediosFile= fopen("remedios.dat","rb");

  fseek(remediosFile,0,SEEK_END);
  cantidadRemedios = ftell(remediosFile)/sizeof(struct remedios);
  fseek(remediosFile,0,SEEK_SET);

  for(i=0;i<cantidadRemedios-1;i++){
    fread(&remedio1,i*sizeof(struct remedios),1,remediosFile);
    for(j=i+1;j<cantidadRemedios;j++){
      fread(&remedio2,j*sizeof(struct remedios),1,remediosFile);
      if(strcmp(remedio1.codigoRemedio,remedio2.codigoRemedio)==0){
        i=15;
        agregar = 0;
      }
    }
    if(agregar==1){
      cantidadRemedios ++;
    }
  }
    return cantidadRemedios;
}

int cantidadDrogasXRemedio(FILE *remediosFile, struct remedios remedio){
  /* devuelve la cantidad de drogas por remedio */
  /* Se asume que todos los remedios con el mismo codigo ingresados en el archivo, tienen drogas distintas. */
  struct remedios remedioAComparar;

  int cantidadRemedios = 0, cantidadDrogas = 0;
  int i;

  remediosFile= fopen("remedios.dat","rb");

  fseek(remediosFile,0,SEEK_END);
  cantidadRemedios = ftell(remediosFile)/sizeof(struct remedios);
  fseek(remediosFile,0,SEEK_SET);

  for(i=0;i<cantidadRemedios;i++){
    fread(&remedioAComparar,i*sizeof(struct remedios),1,remediosFile);
      if(strcmp(remedioAComparar.codigoRemedio,remedio.codigoRemedio)==0){
        cantidadDrogas ++;
      }
    }

  return cantidadDrogas;
}


void facturacionPorRemedio(FILE *remediosFile, FILE * ventasFile, FILE *drogasFile){
  struct remedios remedio;
  struct drogas droga;
  struct ventas venta;

  float  ventaPorRemedio= 0;

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
            ventaPorRemedio += ((droga.costo * 3) * remedio.cantidad) * venta.cantidadVendida; //200% de ganancia sobre el costo de la droga
          }
        }
      }
    }
    printf("El valor de la venta del remedio %s es: %.2f \n", remedio.codigoRemedio, ventaPorRemedio);
    ventaPorRemedio = 0;
  }
  fclose(drogasFile);
  fclose(remediosFile);
  fclose(ventasFile);

}


void DrogaRemediosVendidos(FILE *remediosFile, FILE * ventasFile, FILE *drogasFile){
  struct remedios remedio;
  struct ventas venta;

  char listaCodigoDrogas[200][3]; //200 filas de drogas x el codigo de la droga
  int listaCantidadDrogas[200];
  char drogaMasUsada[3];
  int i;

  //Lleno el array con drogas vacias
  for(i=0;i<200;i++){
    strcpy(listaCodigoDrogas[i], "");
    listaCantidadDrogas[i] = 0;
  }

  ventasFile = fopen("ventas.dat","rb");
  remediosFile = fopen("remedios.dat","rb");

  while(fread(&venta,sizeof(struct ventas),1,ventasFile)){
    while(fread(&remedio,sizeof(struct remedios),1,remediosFile)){
      for(i=0;i<200;i++){
        if(strcmp(listaCodigoDrogas[i], "")!=0){
          if(strcmp(remedio.codigoDroga, listaCodigoDrogas[i])){
            listaCantidadDrogas[i] += remedio.cantidad;
            i = 200;
          }
        }
      }
    }
  }

 fclose(remediosFile);
 fclose(ventasFile);

 strcpy(drogaMasUsada, buscarDrogasMasUsada(listaCantidadDrogas, listaCodigoDrogas, 200));

 printf("La drogas mas usada en los medicamentos vendidos es: %s \n", drogaMasUsada);

}

// Dado un array con structs de drogas, devuelve el codigo de la droga mas usada. No funciona, no se como devolver un array
char *buscarDrogasMasUsada(int listaCantidadDrogas[], char listaCodigoDrogas[][3], int longitudArray){
  char droga[3];
  int cantidad = -999;

  int i;

  for(i=0;i<longitudArray;i++){
    if(listaCantidadDrogas[i]>cantidad){
      strcpy(droga, listaCodigoDrogas[i]);
      cantidad = listaCantidadDrogas[i];
    }
  }

  return droga;
}

float buscarCostoDroga(FILE *drogasFile, char codigoDroga[3]){
  struct drogas droga;

  float costo;

  drogasFile = fopen("drogas.dat","rb");
  while(fread(&droga,sizeof(struct drogas),1,drogasFile)){
    if(strcmp(droga.codigoDroga, codigoDroga)==0){
      costo = droga.costo;
    }
  }

  return costo;
}

void drogaMasBarata(struct drogas droga){
  float menor_costo=999999;
  int droga_barata;

  for(i=0;i<200;i++) {
	  if(droga.costo[i]<menor_costo){
		menor_costo=droga.costo[i];
		droga_barata=droga.codigoDroga[i];		
	  }
  }

  printf("La droga mas barata es: %s", droga_barata);

}
