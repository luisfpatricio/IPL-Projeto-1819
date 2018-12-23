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
    int qtdBicicletas=0, qtdUtentes=0, qtdEmprestimos=0, qtdListaEspera=0;
    float qtdDistanciaPercorrida = 0.0;

    //Declarar variavel "Tipo estrutura"
    tipoBicicleta vetorBicicletas[MAX_BICICLETAS];

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

                    break;

                case 3:
                    //Listar Bicicletas
                    listarBicicletas(vetorBicicletas, qtdBicicletas);

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
                opcaoMenuUtentes = menuUtentes();
            }
            while(opcaoMenuUtentes != 0);
            break;
        case 3:
            //Menu Emprestimos
            do
            {
                opcaoMenuEmprestimos = menuEmprestimos();
            }
            while(opcaoMenuEmprestimos != 0);
            break;
        case 4:
            //Menu Lista de Espera
            do
            {
                printf("teste");
                //opcaoMenuListaEspera = menuListaEspera();
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

