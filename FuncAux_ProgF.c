#include <stdio.h>
#include <string.h>
#include "FuncAux_ProgF.h"
#include "constantes.h"


// Menu Principal
int menuPrincipal()
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Principal **************************\n\n");
    printf("Quantidade de Utentes: %d\n");
    printf("Quantidade de Emprestimos Registados: %d\n");
    printf("Distancia Total Percorrida: %.3f\n");
    printf("Quantidade de Pedidos em Lista de Espera: %d\n\n");
    printf("\t1 - Bicicletas\n");
    printf("\t2 - Utentes\n");
    printf("\t3 - Emprestimos\n");
    printf("\t4 - Lista de Espera\n");
    printf("\t5 - Ficheiros\n");
    printf("\t0 - Sair\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 5);

    //limpaBufferStdin();
    //opcao =toupper(opcao);

    return opcao;
}

// Menu Bicilcetas
int menuBicicletas()
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Bicicletas **************************\n\n");
    printf("Quantidade de Emprestimos: %d\n");
    printf("Distancia Total Percorrida: %.3f\n\n");
    printf("\t 1 - Adicionar Bicicleta\n");
    printf("\t 2 - Consultar Bicicletas\n");
    printf("\t 3 - Listar Bicicletas");
    //printf("\t 4 - Eliminar Bicicleta\n");
    //printf("\t 5 - Alterar Destino da Bicicleta\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 3);

    return opcao;
}

// Menu Utentes
int menuUtentes()
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Utentes **************************\n\n");
    printf("Quantidade de Emprestimos: %d\n");
    printf("Quantidade de Avarias: %d\n");
    printf("Distancia Total Percorrida: %.3f\n\n");
    printf("\t 1 - Adicionar Utente\n");
    printf("\t 2 - Alterar Utente\n");
    printf("\t 3 - Consultar Utentes");
    printf("\t 4 - Listar Utentes\n");
    //printf("\t 5 - Eliminar Utentes\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 4);

    return opcao;
}

// Menu Emprestimos
int menuEmprestimos()
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Emprestimos **************************\n\n");
    printf("\t 1 - Registar Emprestimo\n");
    printf("\t 2 - Consultar Emprestimo");
    printf("\t 3 - Listar Emprestimos\n");
    printf("\t 4 - Listar Lista de Espera\n");
    //printf("\t 5 - Eliminar Utentes\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 4);

    return opcao;
}

// Menu Estatisticas
int menuEstatisticas()
{

}
// Menu Ficheiros
int menuFicheiros()
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Emprestimos **************************\n\n");
    printf("\t 1 - Ler do Ficheiro\n");
    printf("\t 2 - Guardar no Ficheiro\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 2);

    return opcao;
}



// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vĂ lidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vĂ lidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        //   puts(mensagem);
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
        {
            limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
        }
        else
        {
            vetorCaracteres[tamanhoString-1] ='\0';          //substitui \n da string armazenada em vetor por \0
        }
        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    }
    while (tamanhoString == 1);
}


/*
tipoData lerData(void)
{
    tipoData data;
    int maxDiasMes;

    data.ano = lerInteiro(" ano", 2014, 2018);
    data.mes = lerInteiro(" mes", 1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" dia:", 1, maxDiasMes);


    return data;
}
*/


void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
