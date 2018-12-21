#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "STRUCTS_PF.h"

//Funcoes Bicicletas


void inserirBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas)
{

    lerString("\nDesignacao: ", vetorBicicletas[*qtdBicicletas].designacao,MAX_STRING);
    limpaBufferStdin();
    lerString("\nModelo: ", vetorBicicletas[*qtdBicicletas].modelo,MAX_STRING);
    limpaBufferStdin();
    vetorBicicletas[*qtdBicicletas].estado = lerInteiro("\nInsira o estado:\n\t1 - Disponivel\n\t2 - Emprestada\n\t3 - Avariada\n\tInsira a opcao: ", 1, 3);
    vetorBicicletas[*qtdBicicletas].campus = lerInteiro("\nInsira o Campus:\n\t1 - Residencias\n\t2 - Campus1\n\t3 - Campus2\n\t4 - Campus5\n\tInsira a opcao: ", 1, 4);
    (*qtdBicicletas)++;

}
