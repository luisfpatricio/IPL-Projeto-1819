#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "STRUCTS_PF.h"

// Funcoes Bicicletas

// Inserir Bicicleta
void inserirBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas)
{
    int posicao;

    if(*qtdBicicletas == MAX_BICICLETAS)
    {
        printf("\nAtencao: Antigimos a quantidade maxima de Bicicletas\n");
    }
    else
    {
        do
        {
            lerString("\nDesignacao: ", vetorBicicletas[*qtdBicicletas].designacao,MAX_STRING);
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
}

// Procurar Bicicleta
int procuraBicicleta(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas, char designacao[MAX_STRING])
{
    int i, existeBicicleta = -1; // -1 caso nao exista bicicleta

    for (i=0; i < qtdBicicletas; i++)
    {
        if(strcmp(vetorBicicletas[i].designacao,designacao) == 0)
        {
            existeBicicleta = i;
            i = qtdBicicletas;
        }
    }
    return existeBicicleta;
}

// Procura Campus da Bicicleta
int procuraBicicletaCampus(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int qtdBicicletas, int campus)
{
    int i, existeCampus = -1; // -1 caso nao exista utente

    for (i=0; i < qtdBicicletas; i++)
    {
        if(vetorBicicletas[i].campus == campus)
        {
            existeCampus = i;
            i = qtdBicicletas;
        }
    }
    return existeCampus;
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
void listarBicicletas(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas)
{
    int i;
    int a;

    if(*qtdBicicletas == 0)
    {
        printf("\n\nNao Existem Bicicletas Inseridas\n");
    }
    else
    {
        for( a = 0; a < *qtdBicicletas; a++ )
        {
            printf("\n\nBicicleta[%d]", a);
            printf("\n\tDesignacao: %s", vetorBicicletas[a].designacao);
            printf("\n\tModelo: %s", vetorBicicletas[a].modelo);
            //printf("\n\tEstado: %d", vetorBicicletas[a].estado);
            //printf("\n\tCampus: %d", vetorBicicletas[a].campus);

            // ESTADO
            printf("\n\tEstado: ");
            if(vetorBicicletas[a].estado == 1)
            {
                printf("1 - Disponivel");
            }
            else
            {
                if(vetorBicicletas[a].estado == 2)
                {
                    printf("2 - Emprestada");
                }
                else
                {
                    printf("3 - Avariada");
                }
            }
            //Campus
            printf("\n\tCampus: ");
            if(vetorBicicletas[a].campus == 1)
            {
                printf("1 - Residencias");
            }
            else
            {
                if(vetorBicicletas[a].campus == 2)
                {
                    printf("2 - Campus1");
                }
                else
                {
                    if(vetorBicicletas[a].campus == 3)
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

// Consultar Bicicletas
void consultarBicicleta(tipoBicicleta vetorBicicletas[MAX_BICICLETAS], int *qtdBicicletas)
{
    int posicao;
    char comparaDesignacao[MAX_STRING];

    if(*qtdBicicletas == 0)
    {
        printf("\nNao Existem Bicicletas inseridas!\n\n");
    }
    else
    {
        printf("\n\t\t\tConsultar Bicicletas\n");
        lerString("\nDesignacao: ", comparaDesignacao,MAX_STRING);
        posicao = procuraBicicleta(vetorBicicletas, *qtdBicicletas, comparaDesignacao);

        if(posicao == -1)
        {
            printf("\nDesignacao nao encontrada!\n");
        }
        else
        {
            // Teste Ver o valor da posicao
            /*
            printf("\nPosicao: %d", posicao);
            pausa();
            */
            printf("\n\nBicicleta[%d]", posicao);
            printf("\n\tDesignacao: %s", vetorBicicletas[posicao].designacao);
            printf("\n\tModelo: %s", vetorBicicletas[posicao].modelo);
            printf("\n\tEstado: %d", vetorBicicletas[posicao].estado);
            printf("\n\tCampus: %d", vetorBicicletas[posicao].campus);
        }
    }
    pausa();
}

// Eliminar Bicicletas
