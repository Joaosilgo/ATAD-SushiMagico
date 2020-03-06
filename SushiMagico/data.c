/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data.h"

data criarData(int dia, int mes, int ano) {
    data date;
    if (ano > 2000 && ano <= 2017) {
        date.ano = ano;
    } else {
        date.ano = 2017;
    }
    if (dia > 0 && dia <= 31) {
        date.dia = dia;
    } else {
        date.dia = 1;
    }
    if (mes > 0 && mes <= 12) {
        date.mes = mes;
    } else {
        date.mes = 01;
    }

    return date;
}

void imprimeData(data date) {
    printf(" Data:   \nDia:%d  Mes:%d  Ano:%d \n", date.dia, date.mes, date.ano);
}