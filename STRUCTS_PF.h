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

//Estrutura Devolucao Emprestimo
typedef struct{
    tipoData instanteDistancia;
    float distanciaPercorrida;
}tipoDevolucaoEmprestimo;

//Estrutura Bicicleta
typedef struct{
    char designacao[MAX_STRING];
    char modelo[MAX_STRING];
    //char estado[12];
    //char campus[12];
    int estado;
    int campus;
}tipoBicicleta;

//Estrutura Utente
typedef struct{
    int codigo;
    char nome[MAX_STRING];
    int telefone;
    char tipo[MAX_STRING];
}tipoUtente;

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


#endif // STRUCTS_PF_H_INCLUDED
