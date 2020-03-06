/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   refeicao.h
 * Author: João
 *
 * Created on 27 de Abril de 2017, 16:12
 */


#ifndef REFEICAO_H
#define REFEICAO_H

#include "data.h"
//#include "cartaoCliente.h"
#include "pilhaPratos.h"
#include "prato.h"
typedef struct{
    data dataRefeicao;
     //   cartaoCliente cartao;
       PtStack pilhaPratosConsumidos ;
       double valorFinal;
    
}refeicao;

refeicao criarRefeicao();


void imprimeRefeicao(refeicao refei);




#endif	// REFEICAO_H

