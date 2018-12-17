#ifndef STRUCTS_PF_H_INCLUDED
#define STRUCTS_PF_H_INCLUDED

// Estrutura Data
typedef struct{
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
}tipoMomento;

//Estrutura Devolucao Emprestimo
typedef struct{
    tipoMomento instanteD;
    float dPERCORRIDA;
}tipoDevolucao;

//Estrutura Bicicleta
typedef struct{
    char designacao[10];
    char modelo[25];
    char estado[12];
    char campus[12];
}Bicicleta;

//Estrutura Utente
typedef struct{
    char codigo[10];
    char nome[25];
    int telefone;
    char tipoU[25];
}Utente;

//Estrutura Emprestimo
typedef struct{
    int numeroR;
    char codigoU[10];
    char designacaoB[10];
    char campusO[12];
    char campusD[12];
    tipoMomento instanteR;
    tipoDevolucao dadosdevolvidos;
}Emprestimo;
#endif // STRUCTS_PF_H_INCLUDED
