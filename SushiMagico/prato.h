/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prato.h
 * Author: João
 *
 * Created on 19 de Abril de 2017, 18:11
 */


#ifndef PRATO_H
#define PRATO_H

typedef struct{
    int numeroPrato;
    char    nomePrato[50];
    char    corPrato[20];
    double  preco;
    int     calorias;
}prato;

prato criaPrato(int numeroPrato, char nomePrato[], char corPrato[], double preco, int calorias);

void imprimePrato (prato prato);


#endif	// PRATO_H

