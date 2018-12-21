#ifndef FUNCAUX_PROGF_H_INCLUDED
#define FUNCAUX_PROGF_H_INCLUDED

#include "constantes.h"

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);

//tipoData lerData(void);

#endif // FUNCAUX_PROGF_H_INCLUDED

