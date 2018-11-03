/*
 * funcionesSafa.h
 *
 *  Created on: 7 sep. 2018
 *      Author: utnso
 */

#ifndef SAFA_FUNCIONESSAFA_H_
#define SAFA_FUNCIONESSAFA_H_

#include "SAFA.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <curses.h>
#include <term.h>

int inicializarLog();
int ubicarArchivoDeConfiguracion(int argc,char** argv);
int levantarConfiguracionSAFA(char* ubicacionDelArchivoConfiguracion);
int inicializarVariablesSAFA();
int inicializarSemaforosSAFA();
int finalizarTodo();
void *funcionHiloComDMA(void *arg);
int esperarFinEscuchaDMA();
int iniciarEscuchaCPU();
void *funcionHiloComCPU(void *arg);
int escuchar();
int iniciarConsola();
void *funcionHiloConsola(void *arg);
char** parser_instruccion(char* linea);
t_DTB * crear_DTB(char* path);
int inicializarListas();
int iniciarPCP();
int iniciarPLP();
int liberarMemoria();
void *funcionHiloPLP(void *arg);
void *funcionHiloPlanif(void *arg);
int planificar_PLP();
int planificar();
int proximoDTBAPlanificar();
int calcularDTBAPlanificarConRR();
int calcularDTBAPlanificarConVRR();
int obtenerPrimerId(t_list* lista);
t_DTB* buscarDTBPorId(idDTB);
int enviarDTBaCPU(t_DTB * dtb, int sockCPU);

#endif /* SAFA_FUNCIONESSAFA_H_ */
