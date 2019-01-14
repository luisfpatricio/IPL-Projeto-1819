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
    int numeroRegisto;                          // ID Numero de Registo do Emprestimo
    int codigoUtente;                           // Codigo do Utente
    char designacaoBicicleta[MAX_STRING];       // Designacao da Bicicleta
    int campusOrigem;                           // Campus de Origem
    int campusDestino;                          // Campus de Destino
    tipoData instanteEmprestimo;                // Data e Hora
    tipoDevolucaoEmprestimo dadosDevolvidos;
}tipoEmprestimo;

//Estrutura Bicicleta
typedef struct{
    char designacao[MAX_STRING];            // Designacao
    char modelo[MAX_STRING];                // Modelo
    int estado;                             // Estado: 1 - Disponivel | 2 - Emprestada | 3 - Avariada
    int campus;                             // Campus: 1 - Residencias | 2 - Campus1 | 3 - Campus2 | 4 - Campus5
    int contaEmprestimos, contaAvarias;     // Contador de Emprestimos / Avarias por bicicleta
    float contaDistancia;                    // Contador Distancia Total Percorrida por bicicleta

}tipoBicicleta;

//Estrutura Utente
typedef struct{
    int codigo;                             // ID codigo do Utente
    char nome[MAX_STRING];                  // Nome do Utente
    int telefone;                           // Telefone
    int tipo;                               // Tipo de Utente: 1 - Estudante 2 - Docente 3 - Tecnico Administrativo 4 - Convidado
    int contaEmprestimos;                   // Contador de Emprestimos por Utente
    float contaDistancia;                   // Contador Distancia Total Percorrida por Utente
}tipoUtente;




#endif // STRUCTS_PF_H_INCLUDED
