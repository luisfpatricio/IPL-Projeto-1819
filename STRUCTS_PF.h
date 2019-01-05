#ifndef STRUCTS_PF_H_INCLUDED
#define STRUCTS_PF_H_INCLUDED

// Estrutura Data
typedef struct{
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
}tipoData;

//Lista de Espera
typedef struct
{
    int qtdListaEspera;

}tipoListaEspera;


//Estrutura Devolucao Emprestimo
typedef struct{
    tipoData instanteDistancia;
    float distanciaPercorrida;
}tipoDevolucaoEmprestimo;

//Estrutura Emprestimo
typedef struct{
    int numeroRegisto;
    //char codigoUtente[10];
    //tipoUtente
    //char designacaoBicicleta[10];
    char campusOrigem[12];
    char campusDestino[12];
    tipoData instanteR;
    tipoDevolucaoEmprestimo dadosdevolvidos;
}tipoEmprestimo;

//Estrutura Bicicleta
typedef struct{
    char designacao[MAX_STRING];
    char modelo[MAX_STRING];
    //char estado[MAX_STRING];
    //char campus[MAX_STRING];
    int estado;
    int campus;

}tipoBicicleta;

//Estrutura Utente
typedef struct{
    int codigo;
    char nome[MAX_STRING];
    int telefone;
    //char tipo[MAX_STRING];
    int tipo;
    tipoEmprestimo emprestimo;
}tipoUtente;




#endif // STRUCTS_PF_H_INCLUDED
