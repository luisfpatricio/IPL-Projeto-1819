#ifndef FUNCBICICLETAS_PROGF_H_INCLUDED
#define FUNCBICICLETAS_PROGF_H_INCLUDED

#include "constantes.h"


//Funcoes Bicicletas
void inserirBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int* qtdBicicletas);                              // Inserir Bicicleta
int procuraBicicleta(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas, char designacao[MAX_STRING]);     // Procurar Bicicleta
void ordenarBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas);                               // Ordenar Bicicletas Metodo Borbulhamento
void listarBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas);                                // Listar Bicicletas
void consultarBicicleta(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas);   // Consultar Bicicleta

#endif // CONSTANTES_H_INCLUDED
