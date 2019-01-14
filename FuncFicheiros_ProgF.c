#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "FuncBicicletas_ProgF.h"
#include "FuncUtentes_ProgF.h"
#include "FuncEmprestimos_ProgF.h"
#include "STRUCTS_PF.h"

//Funcoes Ficheiros


void escreveFichBinario(tipoBicicleta vetorBicicletas[], int qtdBicicletas, tipoUtente vetorUtentes[], int qtdUtentes, tipoEmprestimo vetorEmprestimo[MAX_EMPRESTIMOS], int* qtdEmprestimos)
{
    FILE *fich;
    fich = fopen("dados.dat","wb");
    if (fich == NULL)
    {
        printf ("Erro abrir fich");
    }
    else
    {
        /*fwrite(&qtdBicicletas,sizeof(int),1,fich);
        fwrite(vetorBicicletas,sizeof(tipoBicicleta),qtdBicicletas,fich);
        fwrite(&qtdUtentes,sizeof(int),1,fich);
        fwrite(vetorBicicletas,sizeof(tipoUtente),qtdUtentes,fich);
        fwrite(&qtdEmprestimos,sizeof(int),1,fich);
        fwrite(&vetorBicicletas,sizeof(tipoEmprestimo),qtdEmprestimos,fich);*/
        fclose(fich);
        printf("\n Ficheiro Guardado com Sucesso!");
        pausa();
    }
}

/*
void leFicheiroBinario(tipoBicicleta vetorBicicletas[], int* qtdBicicletas, tipoUtente vetorUtentes[], int* qtdUtentes, tipoEmprestimo *vetorEmprestimo, *qtdEmprestimo)
{
    FILE* ficheiro;
    int quantBicicletas=0;

    ficheiro=fopen("dados.dat","rb");

    if (ficheiro == NULL)
    {
        perror("\n Impossivel abrir ficheiro dados.dat!");
    }
    else
    {
        fread(&qtdBicicletas,sizeof(int),1,fich);
        fread(vetorBicicletas,sizeof(tipoBicicleta),qtdBicicletas,fich);
        fread(&qtdUtentes,sizeof(int),1,fich);
        fread(vetorBicicletas,sizeof(tipoUtente),qtdUtentes,fich);
        fread(&qtdEmprestimos,sizeof(int),1,fich);
        fread(&vetorBicicletas,sizeof(tipoEmprestimo),qtdEmprestimos,fich);
        fclose(fich);
        printf("\n Ficheiro Lido com Sucesso!")
        pausa();
    }
}
*/

