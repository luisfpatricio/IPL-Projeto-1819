/*
    João Carreira - nº 2182317
    Luís Patrício - nº 2162357
    Projecto Programação I - Gestão de Bicicletas no IPL
    ©2018-19 - Engenharia Informática - ESTG, IPLeiria
*/
#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "STRUCTS_PF.h"
#include "FuncAux_ProgF.h"
#include "FuncMenus_ProgF.h"
#include "FuncBicicletas_ProgF.h"



int main()
{
    int opcaoMenuPrincipal, opcaoMenuBicicletas, opcaoMenuUtentes, opcaoMenuEmprestimos, opcaoMenuListaEspera, opcaoMenuFicheiros;
    //contadores
    int qtdBicicletas=0, qtdUtentes=0, qtdEmprestimos=0, qtdListaEspera=0, qtdAvarias=0;
    float qtdDistanciaPercorrida = 0.0;
    char compString[MAX_STRING];
    char comparaDesignacao[MAX_STRING];
    int posicaoEmprestimo, posicaoUtente, posicaoBicicleta, posicaoCampus, numID=0;
    int codigo;
    char temporarioBike[MAX_STRING];

    tipoEmprestimo temporario;

    //Declarar variavel "Tipo estrutura"
    tipoBicicleta vetorBicicletas[MAX_BICICLETAS];
    tipoUtente vetorUtentes[MAX_UTENTES];
    //tipoEmprestimo vetorEmprestimos[MAX_EMPRESTIMOS];
    //tipoEmprestimo

    tipoEmprestimo *vetorEmprestimos;
    vetorEmprestimos = NULL; // Inicializar vetores Dinamicos

    iniciaZeros(vetorBicicletas, vetorUtentes);

    // Chama Menu Principal
    do
    {
        opcaoMenuPrincipal=menuPrincipal(&qtdUtentes, &qtdEmprestimos, &qtdDistanciaPercorrida, &qtdListaEspera);

        switch(opcaoMenuPrincipal)
        {
        case 1:
            //menu Bicicletas
            do
            {
                opcaoMenuBicicletas = menuBicicletas(&qtdBicicletas, &qtdEmprestimos, &qtdDistanciaPercorrida);

                switch (opcaoMenuBicicletas)
                {
                case 1:
                    // Inserir Bicicletas
                    inserirBicicletas(vetorBicicletas, &qtdBicicletas);
                    break;
                case 2:
                    // Consultar Bicicletas
                    consultarBicicleta(vetorBicicletas, &qtdBicicletas);

                    break;

                case 3:
                    //Listar Bicicletas
                    listarBicicletas(vetorBicicletas, &qtdBicicletas);

                    break;

                //Eliminar Bicicleta
                case 4:

                    break;

                //Alterar Destino da Bicicleta
                case 5:

                    break;

                    //default:

                }
            }
            while(opcaoMenuBicicletas != 0);

            break;
        case 2:
            //Menu Utentes
            do
            {
                opcaoMenuUtentes = menuUtentes(&qtdEmprestimos, &qtdAvarias, &qtdDistanciaPercorrida);

                switch(opcaoMenuUtentes)
                {
                case 1:
                    // Inserir Utente
                    inserirUtente(vetorUtentes, &qtdUtentes);
                    break;

                case 2:
                    // Alterar Utente
                    alterarUtente(vetorUtentes, &qtdUtentes);

                    break;

                case 3:
                    //Consultar Utente
                    consultarUtente(vetorUtentes, &qtdUtentes);
                    break;

                case 4:
                    // Listar Utentes
                    listarUtentes(vetorUtentes, &qtdUtentes);
                    break;

                case 5:
                    // Eliminar Utente

                    break;
                }
            }
            while(opcaoMenuUtentes != 0);
            break;
        case 3:
            //Menu Emprestimos
            do
            {
                opcaoMenuEmprestimos = menuEmprestimos(&qtdEmprestimos, &qtdListaEspera);

                switch(opcaoMenuEmprestimos)
                {
                case 1:
                    // Inserir Emprestimos
                    //inserirEmprestimo(vetorEmprestimos, &qtdEmprestimos, vetorBicicletas, &qtdBicicletas, vetorUtentes, &qtdUtentes, &qtdListaEspera);

                    if(qtdEmprestimos == MAX_EMPRESTIMOS)
                    {
                        printf("\nAtencao: Antigimos a quantidade maxima de Emprestimos\n");
                    }
                    else
                    {
                        if(qtdBicicletas == 0 || qtdUtentes == 0)
                        {
                            //printf("\nNao existe Bicicletas [%d] ou Utentes [%d] inseridos\n\n", *qtdBicicletas, *qtdUtentes);
                            printf("\nQuantidade Bicicletas: %d\nQuantidade Utentes: %d", qtdBicicletas, qtdUtentes);
                            if(qtdBicicletas == 0)
                            {
                                printf("\n\nNao Existem Bicicletas Inseridas");
                            }
                            if(qtdUtentes == 0)
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
                                posicaoUtente = procuraUtente(vetorUtentes, qtdUtentes, codigo);

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
                                        posicaoBicicleta = procuraBicicleta(vetorBicicletas, qtdBicicletas, temporarioBike);

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
                                            posicaoCampus = procuraBicicletaCampus(vetorBicicletas, qtdBicicletas, temporario.campusOrigem);

                                            if(posicaoCampus==-1)
                                            {

                                                (qtdListaEspera)++;
                                                printf("\nAtencao: Nao existe Bicicletas neste Campus Disponiveis");
                                                printf("\nIra ter que aguardar na nossa Lista de Espera [%d]\n", qtdListaEspera);



                                                //tipoEmprestimo vetorEmprestimo[]
                                            }
                                            else
                                            {
                                                temporario.numeroRegisto = numID+1;

                                                vetorEmprestimos=inserirEmprestimo(vetorEmprestimos, &qtdEmprestimos, temporario);

                                                vetorBicicletas[posicaoBicicleta].estado = 2;
                                                vetorBicicletas[posicaoBicicleta].contaEmprestimos++ ;

                                                vetorUtentes[posicaoUtente].contaEmprestimos++;
                                                // ver nº maximo de bikes por utente

                                                // verificar o estado
                                                (qtdEmprestimos)++;
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



























                    break;

                case 2:
                    // Consultar Emprestimos
                    consultarEmprestimo(vetorEmprestimos, &qtdEmprestimos);

                    break;

                case 3:
                    //Listar Emprestimos
                    listarEmprestimos(vetorEmprestimos, &qtdEmprestimos);
                    break;

                case 4:
                    // Listar Lista de Espera0
                    //listarListaEspera(vetorListaEspera, &qtdListaEspera);
                    break;

                case 5:
                    // Eliminar Emprestimos

                    break;
                }
            }
            while(opcaoMenuEmprestimos != 0);
            break;
        case 4:
            //Menu Lista de Espera
            do
            {
                opcaoMenuListaEspera = menuListaEspera(&qtdListaEspera);
            }
            while(opcaoMenuListaEspera != 0);
            break;
        case 5:
            //MenuFicheiros
            do
            {
                opcaoMenuFicheiros = menuFicheiros();
            }
            while(opcaoMenuFicheiros != 0);
            break;
        case 0:
            //Sair;
            printf("\n\n\tAdeus!!!\n\n\n");
            break;
            /*
            default:
                printf("/nOpcao Errada!");
            */
        }
    }
    while(opcaoMenuPrincipal != 0);


    return 0;
}

