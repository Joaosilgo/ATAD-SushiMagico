/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   operacoes.h
 * Author: João
 *
 * Created on 4 de Maio de 2017, 15:21
 */




#ifndef OPERACOES_H
#define OPERACOES_H
#include "restaurante.h"

void AD(int day, int month, int year);
void AC(int numeroCartao);
void IR(int numeroCartao,int day, int month, int year );
void FR( int numeroCartao ,int  pontos);
void RP (int numeroCartao , int numeroPrato);
void DP (int numeroCartao);
void UP (int numeroCartao);
void CP (int numeroCartao);
void VC (int numeroCartao);
void CE();
void processarOperacoes( restaurante *suchiMagico);






#endif	// OPERACOES_H

