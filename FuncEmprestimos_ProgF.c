#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "STRUCTS_PF.h"
#include "FuncBicicletas_ProgF.h"
#include "FuncUtentes_ProgF.h"


// Funcoes Emprestimos

// Inserir Emprestimo
void inserirEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos, tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas, tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes, int* qtdListaEspera)
{
    char comparaDesignacao[MAX_STRING];
    int posicaoEmprestimo, posicaoUtente, posicaoBicicleta, posicaoCampus, numID=0;

    if(*qtdEmprestimos == MAX_EMPRESTIMOS)
    {
        printf("\nAtencao: Antigimos a quantidade maxima de Emprestimos\n");
    }
    else
    {
        if(*qtdBicicletas == 0 || *qtdUtentes == 0)
        {
            //printf("\nNao existe Bicicletas [%d] ou Utentes [%d] inseridos\n\n", *qtdBicicletas, *qtdUtentes);
            printf("\nQuantidade Bicicletas: %d\nQuantidade Utentes: %d", *qtdBicicletas, *qtdUtentes);
            if(*qtdBicicletas == 0)
            {
                printf("\n\nNao Existem Bicicletas Inseridas");
            }
            if(*qtdUtentes == 0)
            {
                printf("\nNao Existem Utentes Inseridos");
            }
            pausa();
        }
        else
        {
            do
            {
                vetorEmprestimo[*qtdEmprestimos].numeroRegisto = numID+1;
                posicaoEmprestimo = procuraEmprestimo(vetorEmprestimo, *qtdEmprestimos, vetorEmprestimo[*qtdEmprestimos].numeroRegisto);
                printf("\n\nPosicaoEmprestimo = %d", posicaoEmprestimo);
                printf("\nNumero de Registo: %d", vetorEmprestimo[posicaoEmprestimo].numeroRegisto);
                printf("\n\n*qtdEmprestimo = %d", *qtdEmprestimos);
                printf("\nNumero de Registo: %d", vetorEmprestimo[*qtdEmprestimos].numeroRegisto);

                if(posicaoEmprestimo != -1)
                {
                    printf("\nERRO: O Numero de Registo Ja Existe\n");
                }
                else
                {
                    do
                    {
                        vetorEmprestimo[*qtdEmprestimos].codigoUtente = lerInteiro("\nCodigo do Utente: ", 0, MAX_CODIGO_UTENTE);
                        posicaoUtente = procuraUtente(vetorUtentes, *qtdUtentes, vetorEmprestimo[*qtdEmprestimos].codigoUtente);

                        if(posicaoUtente==-1)
                        {
                            printf("\nAtencao: O Codigo do Utente Nao foi Encontrado\n");
                            pausa();
                        }
                        else
                        {
                            do
                            {
                                lerString("\nDesignacao da Bicicleta: ", vetorEmprestimo[*qtdEmprestimos].designacaoBicicleta, MAX_STRING);
                                posicaoBicicleta = procuraBicicleta(vetorBicicletas, *qtdBicicletas, vetorEmprestimo[*qtdEmprestimos].designacaoBicicleta);

                                if(posicaoBicicleta==-1)
                                {
                                    printf("\nAtencao: A Designacao da Bicicleta Nao foi Encontrada\n");
                                    pausa();
                                }
                                else
                                {
                                    vetorEmprestimo[*qtdEmprestimos].instanteEmprestimo = lerData();
                                    vetorEmprestimo[*qtdEmprestimos].campusOrigem = lerInteiro("\nInsira o Campus de Origem:\n\t1 - Residencias\n\t2 - Campus1\n\t3 - Campus2\n\t4 - Campus5\n\tInsira a opcao: ", 1, 4);
                                    vetorEmprestimo[*qtdEmprestimos].campusDestino = lerInteiro("\nInsira o Campus de Destino:\n\t1 - Residencias\n\t2 - Campus1\n\t3 - Campus2\n\t4 - Campus5\n\tInsira a opcao: ", 1, 4);

                                    // validações se existe bike disponivel!!! neste campus
                                    posicaoCampus = procuraBicicletaCampus(vetorBicicletas, *qtdBicicletas, vetorEmprestimo[*qtdEmprestimos].campusOrigem);

                                    if(posicaoCampus==-1)
                                    {
                                        (*qtdListaEspera)++;
                                        printf("\nAtencao: Nao existe Bicicletas neste Campus Disponiveis");
                                        printf("\nIra ter que aguardar na nossa Lista de Espera [%d]\n", *qtdListaEspera);
                                    }
                                    else
                                    {
                                        (*qtdEmprestimos)++;
                                        printf("\nRegisto Efectuado com Sucesso\n\n");
                                    }

                                }
                            }
                            while(posicaoBicicleta==-1);
                        }
                    }
                    while(posicaoUtente==-1);
                }
            }
            while(posicaoEmprestimo != -1);
        }
    }
    pausa();
}
// Procurar Emprestimo
int procuraEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int qtdEmprestimos, int codigoID)
{
    int i, existeEmprestimo = -1; // -1 caso nao exista Emprestimo

    for (i=0; i < qtdEmprestimos; i++)
    {
        if(vetorEmprestimo[i].numeroRegisto == codigoID)
        {
            existeEmprestimo = i;
            i = qtdEmprestimos;
        }
    }
    return existeEmprestimo;
}
// Ordenar Emprestimo Metodo do Borbulhamento INTEIRO
void ordenarEmprestimos(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int qtdEmprestimos)
{
    int i, j, haTrocas;
    tipoEmprestimo aux;
    haTrocas=1;
    for(i=0; i <qtdEmprestimos-1 && haTrocas!=0; i++)
    {
        haTrocas=0;
        for (j= 0; j < qtdEmprestimos-i-1; j++)
        {
            if(vetorEmprestimo[j+1].numeroRegisto < vetorEmprestimo[j].numeroRegisto)  // Por Ordem CRESCENTE
            {
                haTrocas=1;
                aux=vetorEmprestimo[j];
                vetorEmprestimo[j]=vetorEmprestimo[j+1];
                vetorEmprestimo[j+1]=aux;
            }
        }
    }
}
// Listar Emprestimo
void listarEmprestimos(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos)
{
    int i;
    int a;

    if(*qtdEmprestimos == 0)
    {
        printf("\n\nNao Existem Emprestimos Inseridos\n");
    }
    else
    {
        for( a = 0; a < *qtdEmprestimos; a++ )
        {
            printf("\nEmprestimo[%d]", a);
            printf("\n\tNumero do Emprestimo: %d", vetorEmprestimo[a].numeroRegisto);
            printf("\n\tCodigo do Utente: %d", vetorEmprestimo[a].codigoUtente);
            printf("\n\tDesignacao da Bicicleta: %s", vetorEmprestimo[a].designacaoBicicleta);
            printf("\n\tData do Emprestimo: %d-%d-%d", vetorEmprestimo[a].instanteEmprestimo.dia, vetorEmprestimo[a].instanteEmprestimo.mes, vetorEmprestimo[a].instanteEmprestimo.ano);
            printf("\n\tHora do Emprestimo: %d:%d", vetorEmprestimo[a].instanteEmprestimo.hora, vetorEmprestimo[a].instanteEmprestimo.minuto);
            //printf("\n\tCampus de Origem: %d", vetorEmprestimo[a].campusOrigem);
            //printf("\n\tCampus de Destino: %d", vetorEmprestimo[a].campusDestino);

            //Campus Origem
            printf("\n\tCampus de Origem: ");
            if(vetorEmprestimo[a].campusOrigem == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorEmprestimo[a].campusOrigem == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorEmprestimo[a].campusOrigem == 3)
                    {
                        printf("3 - Campus2");
                    }
                    else
                    {
                        printf("4 - Campus5");
                    }
                }
            }
            //Campus Destino
            printf("\n\tCampus de Destino: ");
            if(vetorEmprestimo[a].campusDestino == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorEmprestimo[a].campusDestino == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorEmprestimo[a].campusDestino == 3)
                    {
                        printf("3 - Campus2");
                    }
                    else
                    {
                        printf("4 - Campus5");
                    }
                }
            }
            barra();
        }
    }
    pausa();
}
// Consultar Emprestimo
void consultarEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos)
{
    int posicao, comparaCodigo=0;

    if(*qtdEmprestimos == 0)
    {
        printf("\nNao Existem Emprestimos inseridos!\n\n");
    }
    else
    {
        printf("\n\t\Consultar Emprestimo\n");
        comparaCodigo = lerInteiro("\Numero de Registo: ",0, MAX_ID_EMPRESTIMOS);
        posicao = procuraEmprestimo(vetorEmprestimo, *qtdEmprestimos, comparaCodigo);

        if(posicao == -1)
        {
            printf("\nCodigo nao encontrado!\n");
        }
        else
        {
            // Teste Ver o valor da posicao
            /*
            printf("\nPosicao: %d", posicao);
            pausa();
            */
            printf("\n\nEmprestimo[%d]", posicao);
            printf("\n\tNumero Registo: %d", vetorEmprestimo[posicao].numeroRegisto);
            printf("\n\tCodigo do Utente: %d", vetorEmprestimo[posicao].codigoUtente);
            printf("\n\tDesignacao da Bicicleta: %s", vetorEmprestimo[posicao].designacaoBicicleta);
            printf("\n\tData do Emprestimo: %d-%d-%d", vetorEmprestimo[posicao].instanteEmprestimo.dia, vetorEmprestimo[posicao].instanteEmprestimo.mes, vetorEmprestimo[posicao].instanteEmprestimo.ano);
            printf("\n\tHora do Emprestimo: %d:%d", vetorEmprestimo[posicao].instanteEmprestimo.hora, vetorEmprestimo[posicao].instanteEmprestimo.minuto);
            printf("\n\tCampus de Origem: %d");
            //Campus Origem
            printf("\n\tCampus de Origem: ");
            if(vetorEmprestimo[posicao].campusOrigem == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorEmprestimo[posicao].campusOrigem == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorEmprestimo[posicao].campusOrigem == 3)
                    {
                        printf("3 - Campus2");
                    }
                    else
                    {
                        printf("4 - Campus5");
                    }
                }
            }
            printf("\n\tCampus de Destino: %d");
            //Campus Destino
            printf("\n\tCampus de Destino: ");
            if(vetorEmprestimo[posicao].campusDestino == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorEmprestimo[posicao].campusDestino == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorEmprestimo[posicao].campusDestino == 3)
                    {
                        printf("3 - Campus2");
                    }
                    else
                    {
                        printf("4 - Campus5");
                    }
                }
            }
        }
    }
    pausa();
}
// Eliminar Emprestimo
