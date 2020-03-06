/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cartaoCliente.h
 * Author: João
 *
 * Created on 19 de Abril de 2017, 16:27
 */


#ifndef CARTAOCLIENTE_H
#define CARTAOCLIENTE_H


#include "data.h"
#include "refeicao.h"
#include "queueRefeicao.h"

typedef struct {
    char nomeCliente[50];
    char apelido[50];
    int idade;
   // data dataNascimento;
    int numeroCartao;
  
    int pontos;
    
    PtQueueRefeicao filaRefeicoes;

} cartaoCliente;

cartaoCliente criarCartaoCliente(int numeroCartao , char nomeCliente[], char apelido[], int idade);
void imprimeCartao (cartaoCliente cartao);
int prioridadeDoCliente(cartaoCliente p);



// void lerFicheiroCartaoCliente();


#endif	// CARTAOCLIENTE_H

