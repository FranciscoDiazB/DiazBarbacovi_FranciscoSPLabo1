/*
 * libro.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


eLibros* new_Libro(){

   eLibros* this = (eLibros*) malloc (sizeof(eLibros));

   if(this != NULL){

        libro_setId(this, 0);
        libro_setTitulo(this, " ");
        libro_setAutor(this, " ");
        libro_setPrecio(this, 0);
        libro_setEditorial(this, " ");
   }

   return this;
}

eLibros* new_LibroParametros(int id, char* titulo, char* autor, float precio, char* editorial){

	eLibros* this = NULL;

	this =	new_Libro();

	if(this != NULL){

		if(!(   libro_setId(this, id) &&
				libro_setTitulo(this, titulo) &&
				libro_setAutor(this, autor) &&
				libro_setPrecio(this, precio) &&
				libro_setEditorial(this, editorial)))
		{
			printf("\nFallaron Setters\n");
			free(this);
			this = NULL;
		}
	}

	return this;
}

eLibros* new_LibroParametrosString(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* editorialStr){

	eLibros* this = NULL;

	this =	new_Libro();

	if(this != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && editorialStr != NULL && precioStr != NULL){

		if(!(   libro_setIdStr(this, idStr) &&
				libro_setTitulo(this, tituloStr) &&
				libro_setAutor(this, autorStr) &&
				libro_setPrecioStr(this, precioStr) &&
				libro_setEditorial(this, editorialStr)))
		{
			printf("\nFallaron Setters\n");
			free(this);
			this = NULL;
		}
	}

	return this;
}

int libro_setId(eLibros* this,int id){

	int retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int libro_setIdStr(eLibros* this, char* id){

	int retorno = 0;

	if(this != NULL && id != NULL){

		this->id = atoi(id);
		retorno = 1;
	}

	return retorno;
}

int libro_getId(eLibros* this,int* id){

	int retorno = 0;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
	}

	return retorno;
}


int libro_setTitulo(eLibros* this,char* titulo){

	int retorno = 0;

	if(this != NULL && titulo != NULL){

		if(strlen(titulo) < TAM_TITULO){

			strcpy(this->titulo, titulo);
			retorno = 1;
		}
	}

	return retorno;
}

int libro_getTitulo(eLibros* this,char* titulo){

	int retorno = 0;

	if(this != NULL && titulo != NULL){

		if(strlen(titulo) < TAM_TITULO){

			strcpy(titulo, this->titulo);
			retorno = 1;
		}
	}

	return retorno;
}

int libro_setAutor(eLibros* this,char* autor){

	int retorno = 0;

	if(this != NULL && autor != NULL){

		if(strlen(autor) < TAM_AUTOR){

			strcpy(this->autor, autor);
			retorno = 1;
		}

	}

	return retorno;

}


int libro_getAutor(eLibros* this,char* autor){

	int retorno = 0;

	if(this != NULL && autor != NULL){

		if(strlen(autor) < TAM_AUTOR){

			strcpy(autor, this->autor);
			retorno = 1;
		}
	}

	return retorno;
}

int libro_setPrecio(eLibros* this,float precio){

	int retorno = 0;

	if(this != NULL && precio > 0){

		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int libro_setPrecioStr(eLibros* this, char* precio){

	int retorno = 0;

	if(this != NULL && precio != NULL){

		this->precio = atof(precio);
		retorno = 1;
	}

	return retorno;
}

int libro_getPrecio(eLibros* this,float* precio){

	int retorno = 0;

	if(this != NULL && precio != NULL){

		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

int libro_setEditorial(eLibros* this,char* editorial){

	int retorno = 0;

	if(this != NULL && editorial != NULL){

		if(strlen(editorial) < TAM_EDITORIAL){

			strcpy(this->editorial, editorial);
			retorno = 1;
		}
	}

	return retorno;

}


int libro_getEditorial(eLibros* this,char* editorial){

	int retorno = 0;

	if(this != NULL && editorial != NULL){

		if(strlen(editorial) < TAM_EDITORIAL){

			strcpy(editorial, this->editorial);
			retorno = 1;
		}
	}

	return retorno;
}

int libro_mostrarUnLibro(LinkedList* pListaLibros, int indice){

	eLibros* auxLibro = NULL;
	int exito = 0;
	int idLibro;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	float precio;
	char editorial[TAM_EDITORIAL];

	if( pListaLibros != NULL && indice >= 0){

		auxLibro = (eLibros*) ll_get(pListaLibros, indice);
		libro_getId(auxLibro, &idLibro);
		libro_getAutor(auxLibro, autor);
		libro_getEditorial(auxLibro, editorial);
		libro_getPrecio(auxLibro, &precio);
		libro_getTitulo(auxLibro, titulo);

		printf("%d\t%50s\t\t%-10s\t\t$%5.2f\t\t\t%-80s\n", idLibro, titulo, autor, precio, editorial);
		exito = 1;
	}

	return exito;
}

int libro_OrdenarAutor(void* thisA, void* thisB){

	char editA[TAM_EDITORIAL];
	char editB[TAM_EDITORIAL];

	int exito = 0;

	libro_getAutor((eLibros*) thisA, editA);
	libro_getAutor((eLibros*) thisB, editB);

	if(stricmp(editA, editB) > 0){

		exito = 1;
	}
	else if(stricmp(editA, editB) < 0){

		exito = -1;
	}
	return exito;
}

int libro_OrdenarPrecio(void* thisA, void* thisB){

	float precioA;
	float precioB;

	int exito = 0;

	libro_getPrecio((eLibros*) thisA, &precioA);
	libro_getPrecio((eLibros*) thisB, &precioB);

	if(precioA > precioB){

		exito = 1;
	}
	else if(precioA < precioB){

		exito = -1;
	}
	return exito;
}

int libro_OrdenarTitulo(void* thisA, void* thisB){

	char tituloA[TAM_EDITORIAL];
	char tituloB[TAM_EDITORIAL];

	int exito = 0;

	libro_getTitulo((eLibros*) thisA, tituloA);
	libro_getTitulo((eLibros*) thisB, tituloB);

	if(stricmp(tituloA, tituloB) > 0){

		exito = 1;
	}
	else if(stricmp(tituloA, tituloB) < 0){

		exito = -1;
	}
	return exito;
}

void libro_AplicarDescuentos(void* this){

	float precio;
	char editorial[TAM_EDITORIAL];


	if(this != NULL){

		libro_getEditorial((eLibros*) this, editorial);

		if(stricmp("SIGLO XXI EDITORES", editorial) == 0){

			libro_getPrecio((eLibros*) this, &precio);

			if(precio <= 200){

				precio = precio * 0.9;
				libro_setPrecio((eLibros*) this, precio);
			}
		}
		else if(stricmp("Planeta", editorial) == 0){

			libro_getPrecio((eLibros*) this, &precio);

			if(precio >= 300){

				precio = precio * 0.8;
				libro_setPrecio((eLibros*) this, precio);
			}
		}
	}
}

int libro_FiltrarPrecioMayor500(void* this){

	float precio;
	int exito = 0;

	if(this != NULL){

		libro_getPrecio((eLibros*) this, &precio);

		if(precio >= 500){

			exito = 1;
		}
	}
	return exito;
}

int libro_FiltrarPrecioMenor500(void* this){

	float precio;
	int exito = 0;

	if(this != NULL){

		libro_getPrecio((eLibros*) this, &precio);

		if(precio < 500){

			exito = 1;
		}
	}
	return exito;
}
