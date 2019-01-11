#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "STRUCTS_PF.h"

//Funcoes Utentes

// Inserir Utente
void inserirUtente(tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes)
{
    int posicao;

    if(*qtdUtentes == MAX_UTENTES)
    {
        printf("\nAtencao: Atingimos a quantidade maxima de Utentes\n");
    }
    else
    {
        do
        {
            vetorUtentes[*qtdUtentes].codigo = lerInteiro("\nCodigo: ", 0, MAX_CODIGO_UTENTE);
            posicao = procuraUtente(vetorUtentes, *qtdUtentes, vetorUtentes[*qtdUtentes].codigo);

            if(posicao == -1)
            {
                lerString("\nNome: ", vetorUtentes[*qtdUtentes].nome,MAX_STRING);
                vetorUtentes[*qtdUtentes].telefone = lerInteiro("\nTelefone: ", 0,MAX_TELEFONE);
                vetorUtentes[*qtdUtentes].tipo = lerInteiro("\nInsirta o Tipo:\n\t1 - Estudante\n\t2 - Docente\n\t3 - Tecnico Administrativo\n\t4 - Convidado\n\tInsira a opcao: ", 1,4);
                (*qtdUtentes)++;
            }
            else

            {
                printf("\nAtencao: O Codigo Ja Existe\n");
            }
        }
        while(posicao != -1);
    }
}

// Procurar Utente
int procuraUtente(tipoUtente vetorUtentes[MAX_UTENTES], int qtdUtentes, int codigo)
{
    int i, existeUtente = -1; // -1 caso nao exista utente

    for (i=0; i < qtdUtentes; i++)
    {
        if(vetorUtentes[i].codigo == codigo)
        {
            existeUtente = i;
            i = qtdUtentes;
        }
    }
    return existeUtente;
}

// Ordenar Utentes Metodo do Borbulhamento INTEIRO
void ordenarUtentes(tipoUtente vetorUtentes[MAX_UTENTES], int qtdUtentes)
{
    int i, j, haTrocas;
    tipoUtente aux;
    haTrocas=1;
    for(i=0; i <qtdUtentes-1 && haTrocas!=0; i++)
    {
        haTrocas=0;
        for (j= 0; j < qtdUtentes-i-1; j++)
        {
            if(vetorUtentes[j+1].codigo < vetorUtentes[j].codigo)  // Por Ordem CRESCENTE
            {
                haTrocas=1;
                aux=vetorUtentes[j];
                vetorUtentes[j]=vetorUtentes[j+1];
                vetorUtentes[j+1]=aux;
            }
        }
    }
}

// Listar Utentes
void listarUtentes(tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes)
{
    int a;

    if(*qtdUtentes == 0)
    {
        printf("\n\nNao Existem Utentes Inseridos\n");
    }
    else
    {
        for( a = 0; a < *qtdUtentes; a++ )
        {
            printf("\n\nUtente[%d]", a);
            printf("\n\tCodigo: %d", vetorUtentes[a].codigo);
            printf("\n\tNome: %s", vetorUtentes[a].nome);
            printf("\n\tTelefone: %d", vetorUtentes[a].telefone);
            //printf("\n\tTipo: %d", vetorUtentes[a].tipo);

            // TIPO
            printf("\n\tTipo: ");
            if(vetorUtentes[a].tipo == 1)
            {
                printf("1 - Estudante");
            }
            else
            {
                if(vetorUtentes[a].tipo == 2)
                {
                    printf("2 - Docente");
                }
                else
                {
                    if(vetorUtentes[a].tipo == 3)
                    {
                        printf("3 - Tecnico Administrativo");
                    }
                    else
                    {
                        printf("4 - Convidado");
                    }
                }
            }
        }
    }
    pausa();
}

//  Consultar Utente
void consultarUtente(tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes)
{
    int posicao, comparaCodigo=0;

    if(*qtdUtentes == 0)
    {
        printf("\nNao Existem Utentes inseridos!\n\n");
    }
    else
    {
        printf("\n\t\tAlterar Utente\n");
        comparaCodigo = lerInteiro("\nCodigo: ",0, MAX_CODIGO_UTENTE);
        posicao = procuraUtente(vetorUtentes, *qtdUtentes, comparaCodigo);

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
            printf("\n\nUtente[%d]", posicao);
            printf("\n\tCodigo: %d", vetorUtentes[posicao].codigo);
            printf("\n\tModelo: %s", vetorUtentes[posicao].nome);
            printf("\n\tEstado: %d", vetorUtentes[posicao].telefone);
            //printf("\n\tCampus: %d", vetorUtentes[posicao].tipo);

            // TIPO
            printf("\n\tTipo: ");
            if(vetorUtentes[posicao].tipo == 1)
            {
                printf("1 - Estudante");
            }
            else
            {
                if(vetorUtentes[posicao].tipo == 2)
                {
                    printf("2 - Docente");
                }
                else
                {
                    if(vetorUtentes[posicao].tipo == 3)
                    {
                        printf("3 - Tecnico Administrativo");
                    }
                    else
                    {
                        printf("4 - Convidado");
                    }
                }
            }
        }
    }
    pausa();
}

// Alterar Utente
void alterarUtente(tipoUtente vetorUtentes[MAX_UTENTES], int* qtdUtentes)
{
    int posicaoAlterar, posicaoPesquisa, comparaCodigo=0;

    if(*qtdUtentes == 0)
    {
        printf("\nNao Existem Utentes inseridos!\n\n");
    }
    else
    {
        printf("\n\t\tConsultar Utente\n");
        comparaCodigo = lerInteiro("\nCodigo: ",0, MAX_CODIGO_UTENTE);
        posicaoAlterar = procuraUtente(vetorUtentes, *qtdUtentes, comparaCodigo);

        if(posicaoAlterar == -1)
        {
            printf("\nCodigo nao encontrado!\n");
        }
        else
        {
            do
            {
                vetorUtentes[posicaoAlterar].codigo = lerInteiro("\nCodigo: ", 0, MAX_CODIGO_UTENTE);
                posicaoPesquisa = procuraUtente(vetorUtentes, *qtdUtentes, vetorUtentes[*qtdUtentes].codigo);

                if(posicaoPesquisa == -1)
                {
                    lerString("\nNome: ", vetorUtentes[posicaoAlterar].nome,MAX_STRING);
                    vetorUtentes[posicaoAlterar].telefone = lerInteiro("\nTelefone: ", 0,MAX_TELEFONE);
                    vetorUtentes[posicaoAlterar].tipo = lerInteiro("\nInsirta o Tipo:\n\t1 - Estudante\n\t2 - Docente\n\t3 - Tecnico Administrativo\n\t4 - Convidado\n\tInsira a opcao: ", 1,4);
                }
                else
                {
                    printf("\nAtencao: O Codigo Ja Existe\n");
                }
            }
            while(posicaoPesquisa != -1);
        }
    }
    pausa();
}

// Eliminar Utente
