/*
 * contexto.c
 *
 *  Created on: 29 nov. 2018
 *      Author: utnso
 */

#include "contexto.h"

int MODO_EJECUCION;
int TAMANIO_MEMORIA;
int TAMANIO_MAX_LINEA;
int TAMANIO_PAGINA;
char * PUERTO_ESCUCHA;
t_log * logger;
char * MEMORIA_FISICA;
int GLOBAL_SEGUIR = 1;
pthread_t threadConsola;
t_list * archivos_cargandose = NULL;
t_list * archivos_devolviendose = NULL;
t_conexion_cpu conexiones_cpu[MAX_CLIENTES];
char * path_archivo_para_comparar;

t_list * tablas_de_segmentos=NULL;
t_list * bitmap_marcos_libres=NULL;

t_list * lista_de_huecos=NULL;
