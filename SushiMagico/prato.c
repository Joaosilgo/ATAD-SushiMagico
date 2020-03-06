/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "prato.h"

prato criaPrato(int numeroPrato,char nomePrato[], char corPrato[], double preco, int calorias){
    prato pratos;
    
    strcpy(pratos.nomePrato, nomePrato); // copia o conteúdo do 2º p/ o 1º
    strcpy(pratos.corPrato, corPrato); // copia o conteúdo do 2º p/ o 1º
    
    pratos.preco = preco;
    pratos.calorias = calorias;
    pratos.numeroPrato=numeroPrato;
    
    return pratos;
}

void imprimePrato (prato p){
        printf("%s [%d calorias] - prato %s (%.2f€) \n",
           p.nomePrato, 
           p.calorias, 
           p.corPrato, 
           p.preco);
        
}
