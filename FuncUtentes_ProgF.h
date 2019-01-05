#ifndef FUNCBICICLETAS_PROGF_H_INCLUDED
#define FUNCBICICLETAS_PROGF_H_INCLUDED

#include "constantes.h"


//Funcoes Utentes
void inserirUtente(tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes);                      // Inserir Utente
int procuraUtente(tipoUtente vetorUtentes[MAX_UTENTES], int qtdUtentes, int codigo);            // Procurar Utente
void ordenarUtentes(tipoUtente vetorUtentes[MAX_UTENTES], int qtdUtentes);                      // Ordenar Vetor Utentes Metodo Borbulhamento (Inteiro)
void listarUtentes(tipoUtente vetorUtentes[MAX_UTENTES], int qtdUtentes);                      // Listar Utentes
void consultarUtente(tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes);                    // Consultar Utente

#endif // CONSTANTES_H_INCLUDED
