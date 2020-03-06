/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "cartaoCliente.h"
#include "queueTypeElementCartao.h"

/******************** Nível V ****************/
int compareElemsPriority(QTypeElemCartao elem1, QTypeElemCartao elem2) {
    return (prioridadeDoCliente(elem1) - prioridadeDoCliente(elem2));
}