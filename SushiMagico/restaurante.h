/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   restaurante.h
 * Author: João
 *
 * Created on 3 de Maio de 2017, 16:48
 */
#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <stdio.h>

//Nivel 2
#define MAX_CLIENTES 100

#include "cartaoCliente.h"
#include "queueCartao.h"

typedef struct{
    int numeroClientes;  
    cartaoCliente listaClientes[MAX_CLIENTES];
    //BALCAO 4 POS
    int    lugaresBalcao[4];// nº de cartao do cliente
    //PtQueueRefeicao refeicoesRestaurante;// uma fila de refeiçoes do restaurante
    int numeroPratoRestaurante[50]; //pratos do restaurante
    prato PratosRestaurante[50];
    PtQueueCartao listaDeEspera;// lista de espera do restaurante
}restaurante;

restaurante createRestaurante();

void adicionarClienteRestaurante (restaurante *restaurante, cartaoCliente cliente);


//Nível 3
void mostrarListaClientes(restaurante rest);

void lerFicheiroCartaoCliente(restaurante *suchiMagico);
void lerFicheiroPratos(restaurante *suchiMagico);

cartaoCliente getCartaoCliente(int numeroCartao, restaurante res);




#endif	// RESTAURANTE_H

