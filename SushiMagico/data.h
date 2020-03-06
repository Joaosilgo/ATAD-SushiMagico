/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: João
 *
 * Created on 19 de Abril de 2017, 15:43
 */



//dia (inteiro)
//ano (inteiro)
//mes(inteiro)

#ifndef DATA_H
#define DATA_H


typedef struct {
    int ano;
    int mes;
    int dia;

}data;

 data criarData(int dia, int mes, int ano);
 void imprimeData(data date);



#endif	// DATA_H

