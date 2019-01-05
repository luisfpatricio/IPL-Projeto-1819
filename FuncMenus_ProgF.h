#ifndef FUNCMENUS_PROGF_H_INCLUDED
#define FUNCMENUS_PROGF_H_INCLUDED

#include "constantes.h"

//Menus e SubMenus
int menuPrincipal(int* qtdUtentes, int* qtdEmprestimos, float* qtdDistanciaPercorrida, int* qtdListaEspera);
int menuBicicletas(int* qtdBicicletas, int* qtdEmprestimos, float* qtdDistanciaPercorrida);
int menuUtentes(int* qtdEmprestimos, int* qtdAvarias, int* qtdDistanciaPercorrida);
int menuEmprestimos(void);
int menuEstatisticas(void);
int menuFicheiros(void);


#endif // FUNCAUX_PROGF_H_INCLUDED
