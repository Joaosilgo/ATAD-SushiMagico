/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "operacoes.h"
#include "data.h"
#include "restaurante.h"




// restaurante s =  createRestaurante();

void AD(int day, int month, int year)
{
 data ad =  criarData(day , month, year);
 imprimeData(ad);
}

void AC(int numeroCartao)
 {
    
 }
void IR(int numeroCartao, int dia, int mes, int ano)
{
    
} 

/**
void processarOperacoes( restaurante *suchiMagico){
    //abrir o fich fOps.... etc...
    
    char linha[1024];
    char op[3];
    int numCartao;
    
    while (fgets(linha, sizeof(linha), fOps)) {
        fscanf(linha, "%s", op);
        if (strcmp(op, "AC") == 0){
            fscanf(linha, "%d", &numCartao);
            
            //chamar a funcao da AC e fazer o que ha a fazer
        }
        if (strcmp(op, "AD") == 0){
            int d, m, a;
            fscanf(linha, "%d/%d/%d", &d, &m, &a);
            
            
        }
        if (strcmp(op, "RP") == 0){
            int numPrato;
            fscanf(linha, "%d %d", &numCartao, &numPrato);
            
            //chamar a funcao da AC e fazer o que ha a fazer
        }
    }
    
}
 * */