/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queueCartao.h
 * Author: João
 *
 * Created on 4 de Maio de 2017, 17:00
 */



#ifndef QUEUECARTAO_H
#define QUEUECARTAO_H

#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4
    
#include "queueTypeElementCartao.h"
    
    /* forward declaration da estrutura da fila.
     Será definida em concreto pela implementacao num *.c */
    struct queueImplCartao;
    
    /* Definicao de ponteiro para a estrutura da fila */
    typedef struct queueImplCartao *PtQueueCartao;     
    
    /* Cria uma fila. Devolve a referência da pilha criada ou 
     * NULL no caso de inexistência de memória. */
    PtQueueCartao queueCreateCartao();
    /* Destroi uma fila, libertando a memória associada. Devolve: QUEUE_OK em
     * caso de sucesso, ou QUEUE_NULL no caso de ser ponteiro nulo. */
    int queueDestroyCartao(PtQueueCartao *ptQueue);
    /* Empilha 'elem' na fila. Devolve: QUEUE_OK no caso de sucesso; 
     * QUEUE_NULL em caso de ponteiro nulo; QUEUE_NO_MEMORY caso nao haja mais memória 
     * disponivel, ou; QUEUE_FULL caso a fila esteja cheia. */
    int queueEnqueueCartao(PtQueueCartao queue, QTypeElemCartao elem);
    /* Retira um elemento da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a pilha esteja vazia. */
    int queueDequeueCartao(PtQueueCartao queue, QTypeElemCartao *ptElem);
    /* Espreita o inicio da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a fila esteja vazia. */
    int queuePeekCartao(PtQueueCartao queue, QTypeElemCartao *ptElem);
    /* Calcula o tamanho da fila, copiando esse valor para 'ptSize'. 
     Devolve: QUEUE_OK no caso de sucesso, ou; QUEUE_NULL em caso de ponteiro nulo. */
    int queueSizeCartao(PtQueueCartao queue, int *ptSize);
    /* Verifica se a fila está vazia. 
     Devolve: 1 caso esteja vazia ou seja NULL; 0 não se encontre vazia. */
    int queueIsEmptyCartao(PtQueueCartao queue);
    
    //NIVEL V
    //so para manter as duas versoes mas ha que retirar uma das queueEnqueue
    //se for para manter esta entao ha que retirar o Priority do nome
    int queueEnqueuePriorityCartao(PtQueueCartao queue, QTypeElemCartao elem);


#endif	// QUEUECARTAO_H

