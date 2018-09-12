/*
 * Contexto.h
 *
 *  Created on: 8 sep. 2018
 *      Author: utnso
 */

#ifndef CONTEXTO_H_
#define CONTEXTO_H_
#include <commons/log.h>
#include <commons/config.h>

extern t_log * logger;
extern char * path_archivo_log;
extern t_config * configuracion;
extern char * path_archivo_configuracion;
extern int puerto_de_escucha;
extern char * clave_puerto_de_escucha;
extern char * ip_safa;
extern char * clave_ip_safa;
extern int puerto_safa;
extern char * clave_puerto_safa;
extern char * ip_fm9;
extern char * clave_ip_fm9;
extern int puerto_fm9;
extern char * clave_puerto_fm9;
extern char * ip_mdj;
extern char * clave_ip_mdj;
extern int puerto_mdj;
extern char * clave_puerto_mdj;
extern int transfer_size;
extern char * clave_transfer_size;

static const char *FM9 = "FM9";
static const char *MDJ = "MDJ";
static const char *Cpu = "CPU";
static const char *SAFA = "SAFA";

static const char *SE_INTENTARA_CONECTAR_LA_IP_Y_PUERTO =
		"Se intentara conectar la ip %s , puerto %d de ";

#endif /* CONTEXTO_H_ */
