/*
 * segmentacion_pura.h
 *
 *  Created on: 28 nov. 2018
 *      Author: utnso
 */

#ifndef SEGMENTACION_PURA_H_
#define SEGMENTACION_PURA_H_

#include "contexto.h"
#include "utilidades_fm9.h"
#include "utilidades_para_listas.h"

struct entrada_tabla_segmentos{
	int base;
	int limite;
	char * archivo;
};
typedef struct entrada_tabla_segmentos t_entrada_tabla_segmentos;

struct tabla_segmentos{
	int pid;
	t_list * entradas;
};
typedef struct tabla_segmentos t_tabla_segmentos;

struct hueco{
	int base;
	int limite;
};
typedef struct hueco t_hueco;

extern t_list * tablas_de_segmentos;
extern t_list * lista_de_huecos;

void inicializar_lista_de_huecos();
bool es_un_proceso_conocido(void * tabla_segmentos);
int agregar_entrada_tabla_segmentos(tp_cargarEnMemoria nombre_archivo, t_list* entradas_segmentos, int nueva_base, int nuevo_limite);
int el_proceso_tiene_tabla_de_segmentos();
int agregar_nueva_tabla_segmentos_para_proceso(tp_cargarEnMemoria parte_archivo, int nueva_base, int nuevo_limite);
void crear_estructuras_esquema_segmentacion();
void cargar_parte_archivo_en_segmento(int DAM_fd);
void destruir_estructuras_esquema_segmentacion();
void eliminar_lista_de_entradas(void * tabla_segmentos);
t_archivo_cargandose* cargar_buffer_archivo(tp_cargarEnMemoria parte_archivo);
t_hueco* tomar_hueco_con_limite_mas_grande();
bool archivo_mas_grande_que_hueco(int tamanio_en_lineas_archivo,const t_hueco* hueco);
bool archivo_igual_al_hueco(int tamanio_archivo_en_linas,const t_hueco* hueco_usado);
t_hueco* tomar_hueco();
void actualizar_info_tabla_de_huecos(int tamanio_archivo_en_memoria, t_hueco* hueco);
int separar_en_lineas(t_archivo_cargandose * archivo_cargado, char** archivo_separado_en_lineas);
int actualizar_tabla_segmentos(tp_cargarEnMemoria parte_archivo, int nueva_base, int nuevo_limite);
void copiar_archivo_a_memoria_fisica(size_t tamanio_archivo_en_memoria, t_hueco* hueco, char* archivo_separado_en_lineas);
int crear_nueva_entrada_tabla_de_segmentos(tp_cargarEnMemoria parte_archivo, int nueva_base, int nuevo_limite);
void informar_carga_segmento_exitosa(int indice_entrada_archivo_en_tabla_segmentos, tp_cargarEnMemoria parte_archivo, int DAM_fd);
void buscar_informacion_administrativa_esquema_segmentacion_y_mem_real(int id);
int todavia_falta_mandar_pedazo_de_archivo(tp_cargarEnMemoria pedazo_actual, t_archivo_cargandose * archivo_cargandose);


#endif /* SEGMENTACION_PURA_H_ */