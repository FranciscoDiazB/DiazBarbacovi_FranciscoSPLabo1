/*
 * libro.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Asus
 */
#include "linkedlist.h"
#define TAM_TITULO 128
#define TAM_AUTOR 50
#define TAM_EDITORIAL 50

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct{

	int id;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	float precio;
	char editorial[TAM_EDITORIAL];

}eLibros;

eLibros* new_Libro();
eLibros* new_LibroParametros(int id, char* titulo, char* autor, float precio, char* editorial);
eLibros* new_LibroParametrosString(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* editorialStr);

int libro_setId(eLibros* this,int id);
int libro_getId(eLibros* this,int* id);
int libro_setIdStr(eLibros* this, char* id);

int libro_setTitulo(eLibros* this,char* titulo);
int libro_getTitulo(eLibros* this,char* titulo);

int libro_setAutor(eLibros* this,char* autor);
int libro_getAutor(eLibros* this,char* autor);

int libro_setPrecio(eLibros* this,float precio);
int libro_getPrecio(eLibros* this,float* precio);
int libro_setPrecioStr(eLibros* this, char* precio);

int libro_setEditorial(eLibros* this,char* editorial);
int libro_getEditorial(eLibros* this,char* editorial);

int libro_mostrarUnLibro(LinkedList* list, int indice);

int libro_OrdenarAutor(void* thisA, void* thisB);
int libro_OrdenarPrecio(void* thisA, void* thisB);
int libro_OrdenarTitulo(void* thisA, void* thisB);

void libro_AplicarDescuentos(void* this);

int libro_FiltrarPrecioMayor500(void* this);
int libro_FiltrarPrecioMenor500(void* this);

#endif /* LIBRO_H_ */
