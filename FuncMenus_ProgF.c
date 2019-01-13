#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"





// Menu Principal
int menuPrincipal(int* qtdUtentes, int* qtdEmprestimos, float* qtdDistanciaPercorrida, int* qtdListaEspera)
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Principal **************************\n\n");
    printf("Quantidade de Utentes: %d\n", *qtdUtentes);
    printf("Quantidade de Emprestimos Registados: %d\n", *qtdEmprestimos);
    printf("Distancia Total Percorrida: %.3f\n", *qtdDistanciaPercorrida);
    printf("Quantidade de Pedidos em Lista de Espera: %d\n\n", *qtdListaEspera);
    printf("\t1 - Bicicletas\n");
    printf("\t2 - Utentes\n");
    printf("\t3 - Emprestimos\n");
    printf("\t4 - Lista de Espera\n");
    printf("\t5 - Ficheiros\n");
    printf("\n0 - Sair\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 5);

    //limpaBufferStdin();
    //opcao =toupper(opcao);

    return opcao;
}

// Menu Bicilcetas
int menuBicicletas(int *qtdBicicletas, int *qtdEmprestimos, float *qtdDistanciaPercorrida)
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Bicicletas **************************\n\n");
    printf("\nQuantidade de Bicicletas: %d\n", *qtdBicicletas);
    printf("Quantidade de Emprestimos: %d\n", *qtdEmprestimos);
    printf("Distancia Total Percorrida: %.3f\n\n", *qtdDistanciaPercorrida);
    printf("\t 1 - Adicionar Bicicleta\n");
    printf("\t 2 - Consultar Bicicletas\n");
    printf("\t 3 - Listar Bicicletas\n");
    printf("\t 4 - Eliminar Bicicleta\n");
    printf("\t 5 - Alterar Destino da Bicicleta\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 5);

    return opcao;
}

// Menu Utentes
int menuUtentes(int* qtdEmprestimos, int* qtdAvarias, int* qtdDistanciaPercorrida)
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Utentes **************************\n\n");
    printf("Quantidade de Emprestimos: %d\n", *qtdEmprestimos);
    printf("Quantidade de Avarias: %d\n", *qtdAvarias);
    printf("Distancia Total Percorrida: %.3f\n\n", *qtdDistanciaPercorrida);
    printf("\t 1 - Adicionar Utente\n");
    printf("\t 2 - Alterar Utente\n");
    printf("\t 3 - Consultar Utentes\n");
    printf("\t 4 - Listar Utentes\n");
    printf("\t 5 - Eliminar Utentes\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 5);

    return opcao;
}

// Menu Emprestimos
int menuEmprestimos(int* qtdEmprestimos, int* qtdListaEspera)
{
    int opcao;

    //system("cls");
    printf("\n************************** Menu Emprestimos **************************\n\n");
    printf("Quantidade de Emprestimos: %d\n", *qtdEmprestimos);
    printf("Quantidade de Lista de Espera: %d\n", *qtdListaEspera);
    printf("\t 1 - Registar Emprestimo\n");
    printf("\t 2 - Consultar Emprestimo\n");
    printf("\t 3 - Listar Emprestimos\n");
    printf("\t 4 - Listar Lista de Espera\n");
    printf("\t 5 - Eliminar Utentes\n");
    printf("\n 0 - Sair \n\n");

    opcao = lerInteiro("\n\t\tIndique a opcao:", 0, 5);

    return opcao;
}

// Menu Lista de Espera
int menuListaEspera(int* qtdListaEspera)
{
    printf("\n************************** Menu Lista de Espera **************************\n\n");
    printf("\nQuantidade de Lista de Espera: %d", *qtdListaEspera);



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
