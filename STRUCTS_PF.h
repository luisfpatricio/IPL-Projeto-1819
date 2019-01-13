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
    int codigoUtente;
    char designacaoBicicleta[MAX_STRING];
    int campusOrigem;
    int campusDestino;
    tipoData instanteEmprestimo;
    tipoDevolucaoEmprestimo dadosDevolvidos;
}tipoEmprestimo;

//Estrutura Bicicleta
typedef struct{
    char designacao[MAX_STRING];
    char modelo[MAX_STRING];
    int estado;
    int campus;

}tipoBicicleta;

//Estrutura Utente
typedef struct{
    int codigo;
    char nome[MAX_STRING];
    int telefone;
    int tipo;
    tipoEmprestimo emprestimo;
}tipoUtente;




#endif // STRUCTS_PF_H_INCLUDED
