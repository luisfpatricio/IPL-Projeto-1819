//Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
/*
    João Carreira - nº 2182317
    Luís Patrício - nº 2162357
    Projecto Programação I - Gestão de Bicicletas no IPL
    ©2018-19 - Engenharia Informática - ESTG, IPLeiria
*/
#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"


int main()
{
    int opcaoMenuPrincipal, opcaoMenuBicicletas, opcaoMenuUtentes, opcaoMenuEmprestimos, opcaoMenuListaEspera, opcaoMenuFicheiros;

    // Chama Menu Principal
    do
    {
        opcaoMenuPrincipal=menuPrincipal();

        switch(opcaoMenuPrincipal)
        {
        case '1':
            //menu Bicicletas
            do
            {
                opcaoMenuBicicletas = menuBicicletas();
            }
            while(opcaoMenuBicicletas != 0);

            break;
        case '2':
            //Menu Utentes
            do
            {
                opcaoMenuUtentes = menuUtentes();
            }while(opcaoMenuUtentes != 0);
            break;
        case '3':
            //Menu Emprestimos
            menuEmprestimos();
            break;
        case '4':
            //Menu Lista de Espera

            break;
        case '5':
            //MenuFicheiros
            menuFicheiros();
            break;
        case '0':
            //Sair;
            printf("/n/nAdeus!!!");
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

