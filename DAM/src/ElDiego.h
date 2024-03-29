/*
 * ElDiego.h
 *
 *  Created on: 8 sep. 2018
 *      Author: faromero
 */

#ifndef ELDIEGO_H_
#define ELDIEGO_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <commons/log.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <lqvg/com.h>
#include "ConexionesEntrantes.h"
#include "Contexto.h"
#include "Utilidades.h"

int comunicarse_con_memoria();
int comunicarse_con_safa();
int comunicarse_con_file_system();
void cerrar_sockets_de_servidores(int socket_memoria, int socket_safa, int socket_file_system);
void realizar_handshake_con_fm9(int socket_id);
void realizar_handshake_con_safa(int socket_id);
void realizar_handshake_con_mdj(int socket_id);
void mostrar_mensaje_previa_conexion_con_fm9();
void mostrar_mensaje_previa_conexion_con_safa();
void mostrar_mensaje_previa_conexion_con_mdj();

#endif /* ELDIEGO_H_ */
