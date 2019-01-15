#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "STRUCTS_PF.h"
#include "FuncBicicletas_ProgF.h"
#include "FuncUtentes_ProgF.h"
#include "FuncFicheiros_ProgF.h"


// Funcoes Emprestimos


// Vetor Estatico
// Inserir Emprestimo
/*
void inserirEmprestimo(tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos, tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas, tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes, int* qtdListaEspera)
{
    char comparaDesignacao[MAX_STRING];
    int posicaoEmprestimo, posicaoUtente, posicaoBicicleta, posicaoCampus, numID=0;

    int codigo;
    char temporarioBike[MAX_STRING];



    tipoEmprestimo temporario;

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
                codigo = lerInteiro("\nCodigo do Utente: ", 0, MAX_CODIGO_UTENTE);
                posicaoUtente = procuraUtente(vetorUtentes, *qtdUtentes, codigo);

                if(posicaoUtente==-1)
                {
                    printf("\nAtencao: O Codigo do Utente Nao foi Encontrado\n");
                    pausa();
                }
                else
                {
                    do
                    {
                        temporario.codigoUtente = vetorUtentes[posicaoUtente].codigo;




                        lerString("\nDesignacao da Bicicleta: ", temporarioBike, MAX_STRING);
                        posicaoBicicleta = procuraBicicleta(vetorBicicletas, *qtdBicicletas, temporarioBike);

                        if(posicaoBicicleta==-1)
                        {
                            printf("\nAtencao: A Designacao da Bicicleta Nao foi Encontrada\n");
                            pausa();
                        }
                        else
                        {
                            strcpy(temporario.designacaoBicicleta, vetorBicicletas[posicaoBicicleta].designacao);


                            temporario.campusOrigem = lerInteiro("\nInsira o Campus de Origem:\n\t1 - Residencias\n\t2 - Campus1\n\t3 - Campus2\n\t4 - Campus5\n\tInsira a opcao: ", 1, 4);
                            temporario.campusDestino = lerInteiro("\nInsira o Campus de Destino:\n\t1 - Residencias\n\t2 - Campus1\n\t3 - Campus2\n\t4 - Campus5\n\tInsira a opcao: ", 1, 4);

                            // validações se existe bike disponivel!!! neste campus
                            posicaoCampus = procuraBicicletaCampus(vetorBicicletas, *qtdBicicletas, temporario.campusOrigem);

                            if(posicaoCampus==-1)
                            {

                                (*qtdListaEspera)++;
                                printf("\nAtencao: Nao existe Bicicletas neste Campus Disponiveis");
                                printf("\nIra ter que aguardar na nossa Lista de Espera [%d]\n", *qtdListaEspera);



                                //tipoEmprestimo vetorEmprestimo[]
                            }
                            else
                            {

                                vetorEmprestimos=inserirEmprestimo(vetorEmprestimo, &qtdEmprestimos, temporario);

                                vetorBicicletas[posicaoBicicleta].estado = 2;
                                vetorBicicletas[posicaoBicicleta].contaEmprestimos++ ;

                                vetorUtentes[posicaoUtente].contaEmprestimos++;
                                // ver nº maximo de bikes por utente

                                // verificar o estado
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
        pausa();
    }
}
*/



// Inserir Emprestimo
tipoEmprestimo *inserirEmprestimo(tipoEmprestimo *vetorEmprestimos, int *qtdEmprestimos, tipoEmprestimo temporario)
{
    //int numID;

    tipoEmprestimo *auxiliar;
    auxiliar = vetorEmprestimos;

    vetorEmprestimos = realloc(vetorEmprestimos,((*qtdEmprestimos)+1) *sizeof(tipoEmprestimo));
    if (vetorEmprestimos == NULL)
    {
        printf ("Erro ao reservar memoria");
        vetorEmprestimos = auxiliar;
    }
    else
    {
        printf("\nNumero de Registo: %d", temporario.numeroRegisto);
        temporario.instanteEmprestimo = lerData();
        temporario.numeroRegisto = *qtdEmprestimos;

        vetorEmprestimos[*qtdEmprestimos] = temporario;
    }
    return vetorEmprestimos;
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


// Inserir Lista de Espera
tipoEmprestimo *inserirListaEspera(tipoEmprestimo *vetorListaEspera, int* qtdListaEspera, tipoEmprestimo temporario)
{
    tipoEmprestimo *auxiliar;
    auxiliar = vetorListaEspera;

    vetorListaEspera = realloc(vetorListaEspera,((*qtdListaEspera)+1) *sizeof(tipoEmprestimo));
    if (vetorListaEspera == NULL)
    {
        printf ("Erro ao reservar memoria");
        vetorListaEspera = auxiliar;
    }
    else
    {
        temporario.codigoUtente=vetorListaEspera[*qtdListaEspera].codigoUtente;
        strcpy(temporario.designacaoBicicleta, vetorListaEspera[*qtdListaEspera].designacaoBicicleta);
        temporario.campusOrigem=vetorListaEspera[*qtdListaEspera].campusOrigem;
        temporario.campusDestino=vetorListaEspera[*qtdListaEspera].campusDestino;

        vetorListaEspera[*qtdListaEspera] = temporario;
    }
    return vetorListaEspera;
}

// Listar Lista de Espera
void listarListaEspera(tipoEmprestimo vetorListaEspera[MAX_EMPRESTIMOS], int* qtdListaEspera)
{
    int a;

    if(*qtdListaEspera == 0)
    {
        printf("\n\nNao Existe Utentes na Lista de Espera\n");
    }
    else
    {
        for( a = 0; a < *qtdListaEspera; a++ )
        {
            printf("\nLista de Espera[%d]", a);
            printf("\n\tCodigo do Utente: %d", vetorListaEspera[a].codigoUtente);
            printf("\n\tDesignacao da Bicicleta: %s", vetorListaEspera[a].designacaoBicicleta);
            //printf("\n\tCampus de Origem: %d", vetorEmprestimo[a].campusOrigem);
            //printf("\n\tCampus de Destino: %d", vetorEmprestimo[a].campusDestino);

            //Campus Origem
            printf("\n\tCampus de Origem: ");
            if(vetorListaEspera[a].campusOrigem == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorListaEspera[a].campusOrigem == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorListaEspera[a].campusOrigem == 3)
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
            if(vetorListaEspera[a].campusDestino == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorListaEspera[a].campusDestino == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorListaEspera[a].campusDestino == 3)
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
