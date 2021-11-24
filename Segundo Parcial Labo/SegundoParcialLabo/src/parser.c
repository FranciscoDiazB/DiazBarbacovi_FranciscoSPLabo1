/*
 * parser.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Lee linea a linea del archivo con datos, guarda los datos del archivo en una estructura de datos y los anieade a la lista.
 *
 * \param pList LinkedList* Puntero a la lista.
 * \param from pFile* puntero del archivo que se va a leer.
 * \return int Retorna 0 : si el path o la lista son NULL
 * 					   1 : si tuvo exito.
*/
int parser_LibrosdeArchivoTexto(FILE* pFile , LinkedList* pListaLibros)
{
	char id[150];
	char titulo[150];
	char autor[150];
	char precio[150];
	char editorial[150];
	eLibros* nuevoLibro;
	int cant;
	int exito = 0;

	if(pFile != NULL && pListaLibros != NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, editorial);

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, editorial);

			if( cant < 5){
				break;
			}

			nuevoLibro = new_LibroParametrosString(id, titulo, autor, precio, editorial);
			ll_add(pListaLibros, nuevoLibro);

			if(nuevoLibro != NULL){

				exito = 1;
			}
		}
	}
	return exito;
}

/** \brief Escribe en un archivo de texto, los datos que estan en la lista.
 *
 * \param pList LinkedList* Puntero a la lista.
 * \param from pFile* puntero del archivo donde se va a escribir.
 * \return int Retorna 0 : si el path o la lista son NULL
 * 					   1 : si tuvo exito.
*/
int escritura_ArchivoTexto(FILE* pFile , LinkedList* pListaLibros){

	eLibros* auxLibro = NULL;
	int exito = 0;
	int idLibro;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	float precio;
	char editorial[TAM_EDITORIAL];

	if(pFile != NULL && pListaLibros != NULL){

		fprintf(pFile, "id,titulo,autor,precio,editorial\n");

		for(int i = 0; i < ll_len(pListaLibros); i++){

			auxLibro = (eLibros*) ll_get(pListaLibros, i);
			libro_getId(auxLibro, &idLibro);
			libro_getAutor(auxLibro, autor);
			libro_getEditorial(auxLibro, editorial);
			libro_getPrecio(auxLibro, &precio);
			libro_getTitulo(auxLibro, titulo);

			fprintf(pFile, "%d,%s,%s,%.2f,%s\n", idLibro, titulo, autor, precio, editorial);
		}
		exito = 1;
	}
	return exito;
}
