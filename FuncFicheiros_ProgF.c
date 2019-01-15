#include <stdio.h>
#include <string.h>
#include "FuncMenus_ProgF.h"
#include "FuncAux_ProgF.h"
#include "FuncBicicletas_ProgF.h"
#include "FuncUtentes_ProgF.h"
#include "FuncEmprestimos_ProgF.h"
#include "STRUCTS_PF.h"
#include "FuncFicheiros_ProgF.h"

//Funcoes Ficheiros

void escreveFichBinario(tipoBicicleta vetorBicicletas[], int qtdBicicletas, tipoUtente vetorUtentes[], int qtdUtentes, tipoEmprestimo *vetorEmprestimo,int *qtdEmprestimo)
{
    FILE *fich;
    fich = fopen("dados.dat","wb");
    if (fich == NULL)
    {
        printf ("Erro abrir fich");
    }
    else
    {
        fwrite(&qtdBicicletas,sizeof(int),1,fich);
        fwrite(vetorBicicletas,sizeof(tipoBicicleta),qtdBicicletas,fich);
        fwrite(&qtdUtentes,sizeof(int),1,fich);
        fwrite(vetorUtentes,sizeof(tipoUtente),qtdUtentes,fich);
        fwrite(&qtdEmprestimo,sizeof(int),1,fich);
        fwrite(&vetorEmprestimo,sizeof(tipoEmprestimo),&qtdEmprestimo,fich);
        fclose(fich);
        printf("\n Ficheiro Guardado com Sucesso!");
        pausa();
    }
}


void leFicheiroBinario(tipoBicicleta vetorBicicletas[], int* qtdBicicletas, tipoUtente vetorUtentes[], int* qtdUtentes, tipoEmprestimo *vetorEmprestimo,int *qtdEmprestimo)
{
    FILE* fich;
    int quantBicicletas=0;

    fich=fopen("dados.dat","rb");

    if (fich == NULL)
    {
        perror("\n Impossivel abrir ficheiro dados.dat!");
    }
    else
    {
        fread(&qtdBicicletas,sizeof(int),1,fich);
        fread(vetorBicicletas,sizeof(tipoBicicleta),qtdBicicletas,fich);
        fread(&qtdUtentes,sizeof(int),1,fich);
        fread(vetorUtentes,sizeof(tipoUtente),qtdUtentes,fich);
        fread(&qtdEmprestimo,sizeof(int),1,fich);
        fread(&vetorEmprestimo,sizeof(tipoEmprestimo),&qtdEmprestimo,fich);
        fclose(fich);
        printf("\n Ficheiro Lido com Sucesso!");
        pausa();
    }
}


