#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "STRUCTS_PF.h"

//Funcoes Bicicletas

// Inserir Bicicleta
void inserirBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas)
{
    int posicao;

    if(*qtdBicicletas < MAX_BICICLETAS)
    {
        do
        {
            printf("\n\n");
            lerString("\nDesignacao: ", vetorBicicletas[*qtdBicicletas].designacao,MAX_STRING);
            limpaBufferStdin();
            posicao = procuraBicicleta(vetorBicicletas, *qtdBicicletas, vetorBicicletas[*qtdBicicletas].designacao);

            if(posicao == -1)
            {
                lerString("\nModelo: ", vetorBicicletas[*qtdBicicletas].modelo,MAX_STRING);
                vetorBicicletas[*qtdBicicletas].estado = lerInteiro("\nInsira o estado:\n\t1 - Disponivel\n\t2 - Emprestada\n\t3 - Avariada\n\tInsira a opcao: ", 1, 3);
                vetorBicicletas[*qtdBicicletas].campus = lerInteiro("\nInsira o Campus:\n\t1 - Residencias\n\t2 - Campus1\n\t3 - Campus2\n\t4 - Campus5\n\tInsira a opcao: ", 1, 4);
                (*qtdBicicletas)++;
            }
            else
            {
                printf("\nAtencao: A Designacao Ja Existe\n");
            }
        }
        while(posicao != -1);
    }
    else
    {
        printf("\nAtencao: Antigimos o numero maximo de Bicicletas\n");
    }
}

// Procurar Bicicleta
int procuraBicicleta(tipoBicicleta vetorBicicleta[MAX_BICICLETAS], int qtdBicicletas, char designacao[MAX_STRING])
{
    int i, existeBicicleta = -1; // -1 caso nao exista bicicleta

    for (i=0; i < qtdBicicletas; i++)
    {
        if(strcmp(vetorBicicleta[i].designacao,designacao) == 0)
        {
            existeBicicleta = i;
            i = qtdBicicletas;
        }
    }
    return existeBicicleta;
}

// Ordenar Bicicletas Metodo do Borbulhamento STRING
void ordenarBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas)
{
    int i, j, haTrocas;
    tipoBicicleta aux;
    haTrocas=1;
    for(i=0; i <qtdBicicletas-1 && haTrocas!=0; i++)
    {
        haTrocas=0;
        for (j= 0; j < qtdBicicletas-i-1; j++)
        {
            if(strcmp(vetorBicicletas[j+1].designacao, vetorBicicletas[j].designacao) < 0)  // Por Ordem CRESCENTE
            {
                haTrocas=1;
                aux=vetorBicicletas[j];
                vetorBicicletas[j]=vetorBicicletas[j+1];
                vetorBicicletas[j+1]=aux;
            }
        }
    }
}


// Listar Bicicletas
void listarBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas)
{
    int i;

    if(qtdBicicletas == 0)
    {
        printf("\n\nNao Existem Bicicletas Inseridas\n");
    }
    else
    {
        printf("\n\n---------- Lista de todas as Bicicletas -----------\n\n");
        for(i=0; i<qtdBicicletas; i++);
        {
            printf("\nDesignacao: %s", vetorBicicletas[i].designacao);
            printf("\nModelo: %s", vetorBicicletas[i].modelo);
            printf("\nEstado: %d", vetorBicicletas[i].estado);
            printf("\nCampus: %d", vetorBicicletas[i].campus);

            /*
            if(vetorBicicletas[i].estado == 1)
            {
                printf(" - Disponivel");
            }
            else
            {
                if(vetorBicicletas[i].estado == 2)
                {
                    printf(" - Emprestada");
                }
                else
                {
                    printf(" - Avariada");
                }
            }
            printf("\Modelo: %d", vetorBicicletas[i].modelo);
            if(vetorBicicletas[i].modelo == 1)
            {
                printf(" - Residencias");
            }
            else
            {
                if(vetorBicicletas[i].modelo == 2)
                {
                    printf(" - Campus1");
                }
                else
                {
                    if(vetorBicicletas[i].modelo == 3)
                    {
                        printf(" - Campus2");
                    }
                    else
                    {
                        printf(" - Campus5");
                    }
                }
            }
        */
        }
    }
}

/*
// EscreveDadosBicicletas
void escreveDadosBicicletas(tipoBicicleta vetorBicicletas)
{
int i;

printf("\nDesignacao: %s", vetorBicicletas[i].designacao);
printf("\nModelo: %s", vetorBicicletas[i].modelo);
printf("\nEstado: %d", vetorBicicletas[i].estado);
if(vetorBicicletas[i].estado == 1)
{
printf(" - Disponivel");
}
else
{
if(vetorBicicletas[i].estado == 2)
{
printf(" - Emprestada");
}
else
{
printf(" - Avariada");
}
}
printf("\Modelo: %d", vetorBicicletas[i].modelo);
if(vetorBicicletas[i].modelo == 1)
{
printf(" - Residencias");
}
else
{
if(vetorBicicletas[i].modelo == 2)
{
printf(" - Campus1");
}
else
{
if(vetorBicicletas[i].modelo == 3)
{
    printf(" - Campus2");
}
else
{
    printf(" - Campus5");
}
}
}
}
*/


// Eliminar Bicicletas
