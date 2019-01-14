#ifndef FUNCEMPRESTIMOS_PROGF_H_INCLUDED
#define FUNCEMPRESTIMOS_PROGF_H_INCLUDED

#include "constantes.h"


// Funcoes Emprestimos
void inserirEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos, tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas, tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes)                            // Inserir Emprestimo
int procuraEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int qtdEmprestimos, int codigoID)                // Procurar Emprestimo
void ordenarEmprestimos(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int qtdEmprestimos)                            // Ordenar Emprestimo
void listarEmprestimos(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos)                            // Listar Emprestimo
void consultarEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos)                          // Consultar Emprestimo

// Listar Lista de Espera
// Eliminar Utentes


#endif // CONSTANTES_H_INCLUDED
