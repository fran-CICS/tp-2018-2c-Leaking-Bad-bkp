/*
 * ElDiego.c
 *
 *  Created on: 8 sep. 2018
 *      Author: faromero
 */

#include "ElDiego.h"

int main() {
	configurar_logger();
	levantar_configuracion();
	configurar_signals();
	//Va a hacer el handshake con MDJ
	int socket_file_system=comunicarse_con_file_system();
	//Va a hacer el handshake con FM9
	int socket_memoria=comunicarse_con_memoria();
	//Va a quedarse escuchando al CPU
	pthread_t hilo_conexiones_entrantes=crear_hilo_conexiones_entrantes(socket_memoria, socket_file_system);
	//Va a comunicarse con S-AFA e interactuara con ese, FM9 y MDJ
	pthread_t hilo_conexiones_salientes=crear_hilo_conexiones_salientes(socket_memoria, socket_file_system);
	enlazar_hilos(hilo_conexiones_entrantes, hilo_conexiones_salientes);
	cerrar_socket_y_terminar(socket_file_system);
	cerrar_socket_y_terminar(socket_memoria);
	terminar_controladamente(EXIT_SUCCESS);
}

int comunicarse_con_file_system(){
	log_info(logger, strcat(SE_INTENTARA_CONECTAR_LA_IP_Y_PUERTO, MDJ), ip_mdj, puerto_mdj);
	int socket_mdj=conectarseA(ip_mdj, puerto_mdj);
	validar_comunicacion(socket_mdj, MDJ);
	realizar_handshake_con_mdj(socket_mdj);
	return socket_mdj;
}

void realizar_handshake_con_mdj(int socket_id){
	mandar_handshake_a(socket_id, FS, MDJ);
	recibir_handshake_de(socket_id, FS, MDJ);
}

int comunicarse_con_memoria(){
	log_info(logger, strcat(SE_INTENTARA_CONECTAR_LA_IP_Y_PUERTO, FM9), ip_fm9, puerto_fm9);
	int socket_fm9=conectarseA(ip_fm9, puerto_fm9);
	validar_comunicacion(socket_fm9, FM9);
	realizar_handshake_con_fm9(socket_fm9);
	return socket_fm9;
}

void realizar_handshake_con_fm9(int socket_id){
	mandar_handshake_a(socket_id, MEMORIA, FM9);
	recibir_handshake_de(socket_id, MEMORIA, FM9);
}
