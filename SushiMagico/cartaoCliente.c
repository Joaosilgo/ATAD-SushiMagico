/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "queueTypeElementRefeicao.h"
#include "queueRefeicao.h"
#include "cartaoCliente.h"
// #define FICHEIRO_CLIENTES "cliente.txt"
#define PRIORIDADE_ALTA 1
#define PRIORIDADE_BAIXA 0

cartaoCliente criarCartaoCliente(int numeroCartao, char nomeCliente[], char apelido[], int idade) {
    cartaoCliente cartao;
    strcpy(cartao.nomeCliente, nomeCliente); // copia o conteúdo do 2º p/ o 1º
    strcpy(cartao.apelido, apelido); // copia o conteúdo do 2º p/ o 1º
    if (idade > 0 && idade < 150) {
        cartao.idade = idade;
    } else {
        cartao.idade = 1;
    }
    if (numeroCartao > 0) {
        cartao.numeroCartao = numeroCartao;
    } else {
        cartao.numeroCartao = 0;
    }
    cartao.pontos = 0;
    cartao.filaRefeicoes = queueCreateRefeicao();
    return cartao;

}

void imprimeCartao(cartaoCliente cartao) {
    
            printf("%s \n[Numero:%d ] \n Apelido %s \n pontos: %d \n idade: %d \n",
            cartao.nomeCliente,
            cartao.numeroCartao,
            cartao.apelido,
            cartao.pontos,
            cartao.idade);
}
int prioridadeDoCliente(cartaoCliente p) {
    
    if (p.idade > 60)
        return PRIORIDADE_ALTA;
    
    if (p.idade<60 )
        return PRIORIDADE_BAIXA;
   
}
/*
void lerFicheiroCartaoCliente()
{
    FILE *fileLeitura;
    fileLeitura=fopen(FICHEIRO_CLIENTES,"r");
    
    char nomeCliente[50];
    char apelido[50];
    int idade;
   // data dataNascimento;
    int numeroCartao;
  
    int pontos;
   //  refeicao listaRefeicoes[];
    
    
    cartaoCliente cliente;
       
   while(!feof(fileLeitura)){
        fscanf(fileLeitura,"%d %s %s %d",numeroCartao, nomeCliente, apelido , idade);
    
        cliente=criarCartaoCliente( numeroCartao,  nomeCliente,  apelido,  idade);
       // adicionarUtenteClinica (cl,ut); 
   }
}
 * 
 * 
 * 
 * */