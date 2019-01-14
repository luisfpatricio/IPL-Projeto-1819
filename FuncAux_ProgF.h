#ifndef FUNCAUX_PROGF_H_INCLUDED
#define FUNCAUX_PROGF_H_INCLUDED

#include "constantes.h"
#include "STRUCTS_PF.h"

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void iniciaZeros(tipoBicicleta vetorBicicleta[MAX_BICICLETAS], tipoUtente vetorUtente[MAX_UTENTES], tipoEmprestimo *vetorEmprestimos, int* qtdEmprestimos);
void libertaMemoria(void);
tipoData lerData(void);
void limpaBufferStdin(void);
void pausa();
void barra();
void limpaEcra();


//tipoData lerData(void);

#endif // FUNCAUX_PROGF_H_INCLUDED

