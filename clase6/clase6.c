# include <stdio.h>
# include <stdlib.h>

#define CANTIDAD_OPCIONES 1

typedef struct nodo{
	int valor;
	struct nodo *padre;
	struct nodo *izquierda;
	struct nodo *derecha;
} nodo;

void menuPantalla(int *opcion);
void analizar();
void recorrer(nodo *n);
void inicializar(nodo *n, int i);
void hermanos(nodo *n);
void padre(nodo *n);
void asignarHijo(nodo *p, nodo *h, int id);
void ancestros(nodo *n);
void hijos(nodo *n);
void descendientes(nodo *n);
void preorden(nodo *n);
void inorden(nodo *n);
void postorden(nodo *n);
void terminal(nodo *n);

int main ()
{
  int opcion=1;

  /* ==================== */
  /* Menu del programa */
  /* ==================== */
  do{
    menuPantalla(&opcion);
    switch (opcion)
      {
      case 0: analizar(); break;
      }
  }while(opcion<CANTIDAD_OPCIONES);
  /* ======================= */

  return 0;
}

void menuPantalla(int *opcion){
  do{
    printf("MENU DEL PROGRAMA\n\n");
    printf("0:Analizar arbol\n");
    printf("1:Salir del programa\n");

    printf("ingresar una opcion\n");
    scanf("%d", opcion);
    while(getchar() !='\n');
  }while(*opcion<0 || *opcion>CANTIDAD_OPCIONES);

}

void analizar(){
	nodo vector[7];
	inicializar(&vector[0], 0);
	inicializar(&vector[1], 1);
	inicializar(&vector[2], 2);
	inicializar(&vector[3], 3);
	inicializar(&vector[4], 4);
	inicializar(&vector[5], 5);
	inicializar(&vector[6], 6);
	asignarHijo(&vector[0], &vector[1], 1);
	asignarHijo(&vector[1], &vector[2], 1);
	asignarHijo(&vector[1], &vector[3], 0);
	asignarHijo(&vector[0], &vector[4], 0);
	asignarHijo(&vector[4], &vector[5], 1);
	asignarHijo(&vector[4], &vector[6], 0);
	padre(&vector[2]);
	ancestros(&vector[2]);
	hijos(&vector[0]);
	hermanos(&vector[2]);
	hermanos(&vector[1]);
	hermanos(&vector[0]);
  descendientes(&vector[0]);
  recorrer(&vector[0]);
	terminal(&vector[6]);
}

void descendientes(nodo *n){
	int i = 0;
  i++;
  printf("Generacion:%d Descendientes: %d\n", i, n->valor);
  if(n->izquierda!=NULL){
    descendientes(n->izquierda);
  }
  if(n->derecha != NULL){
    descendientes(n->derecha);
  }
}

void asignarHijo(nodo *p, nodo *h, int id){
	h->padre = p;
	if(id == 1){
		p->izquierda = h;
	}else if(id == 0){
		p->derecha = h;
	}
}

void padre(nodo *n){
	nodo *aux;
	aux = n->padre;
	printf("El padre es %d\n", aux->valor);
}

void ancestros(nodo *n){
	nodo *aux;
	int i = 0;

	aux = n;
	while(aux->padre != NULL){
		i++;
		aux = aux->padre;
		printf("El ancestro de proximidad %d de %d es %d\n", i, n->valor, aux->valor);
	}
}

void hijos(nodo *n){
	nodo *aux;
	if(n->izquierda != NULL){
		aux = n->izquierda;
		printf("El hijo a la izquierda de %d es %d\n", n->valor, aux->valor);
	}else{
		printf("No tiene hijo a la izquierda\n");
	}
	if(n->derecha!=NULL){
		aux = n->derecha;
		printf("El hijo a la derecha de %d es %d\n",n->valor,aux->valor);
	}else{
		printf("No tiene hijo a la derecha\n");
	}
}

void recorrer(nodo *n){
	printf("Recorrido en Preorden:\n");
	preorden(n);
	printf("Recorrido en Inorden:\n");
	inorden(n);
	printf("Recorrido en Postorden:\n");
	postorden(n);
}

void preorden(nodo *n){
	printf("Nodo: %d\n", n->valor);
	if(n->izquierda!=NULL){
		preorden(n->izquierda);
	}
	if(n->derecha != NULL){
		preorden(n->derecha);
	}
}

void inorden(nodo *n){
	if(n->izquierda != NULL){
		inorden(n->izquierda);
	}
	printf("Nodo: %d\n", n->valor);
	if(n->derecha!=NULL){
		inorden(n->derecha);
	}
}

void postorden(nodo *n){
	if(n->izquierda != NULL){
		postorden(n->izquierda);
	}
	if(n->derecha != NULL){
		postorden(n->derecha);
	}
	printf("Nodo: %d\n", n->valor);
}

void hermanos(nodo *n){
	nodo *aux;
	int i = 0;
	if(n->padre != NULL){
		aux = n->padre;
		if(aux->izquierda != NULL){
			if(aux->izquierda != n){
				aux = aux->izquierda;
				printf("El hermano de %d es %d\n",n->valor,aux->valor);
				i = 1;
			}
		}
		if(aux->derecha != NULL){
			if(aux->derecha != n){
				aux = aux->derecha;
				printf("El hermano de %d es %d\n",n->valor, aux->valor);
				i = 1;
			}
		}
		if(i==0){printf("%d no tiene hermanos\n", n->valor);}
	}else{
		printf("%d no tiene padre\n", n->valor);
	}
}

void terminal(nodo *n){
	if(n->izquierda == NULL && n->derecha == NULL){printf("Es terminal");}
    else{printf("No es terminal");}
}

void inicializar(nodo *n, int i){
	nodo aux = {i, NULL, NULL, NULL};
	*n = aux;
}
