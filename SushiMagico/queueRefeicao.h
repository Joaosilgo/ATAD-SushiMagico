/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: João
 *
 * Created on 4 de Maio de 2017, 16:09
 */



#ifndef QUEUEREFEICAO_H
#define QUEUEREFEICAO_H

#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4
    
//#include "queueTypeElementCartao.h"
#include "queueTypeElementRefeicao.h"

    
    /* forward declaration da estrutura da fila.
     Será definida em concreto pela implementacao num *.c */
    struct queueImplRefeicao;
    
    /* Definicao de ponteiro para a estrutura da fila */
    typedef struct queueImplRefeicao  *PtQueueRefeicao;     
    
    /* Cria uma fila. Devolve a referência da pilha criada ou 
     * NULL no caso de inexistência de memória. */
    PtQueueRefeicao queueCreateRefeicao();
    /* Destroi uma fila, libertando a memória associada. Devolve: QUEUE_OK em
     * caso de sucesso, ou QUEUE_NULL no caso de ser ponteiro nulo. */
    int queueDestroyRefeicao(PtQueueRefeicao *ptQueue);
    /* Empilha 'elem' na fila. Devolve: QUEUE_OK no caso de sucesso; 
     * QUEUE_NULL em caso de ponteiro nulo; QUEUE_NO_MEMORY caso nao haja mais memória 
     * disponivel, ou; QUEUE_FULL caso a fila esteja cheia. */
    int queueEnqueueRefeicao(PtQueueRefeicao queue, QTypeElemRefeicao elem);
    /* Retira um elemento da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a pilha esteja vazia. */
    int queueDequeueRefeicao(PtQueueRefeicao queue, QTypeElemRefeicao *ptElem);
    /* Espreita o inicio da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a fila esteja vazia. */
    int queuePeekRefeicao(PtQueueRefeicao queue, QTypeElemRefeicao *ptElem);
    /* Calcula o tamanho da fila, copiando esse valor para 'ptSize'. 
     Devolve: QUEUE_OK no caso de sucesso, ou; QUEUE_NULL em caso de ponteiro nulo. */
    int queueSizeRefeicao(PtQueueRefeicao queue, int *ptSize);
    /* Verifica se a fila está vazia. 
     Devolve: 1 caso esteja vazia ou seja NULL; 0 não se encontre vazia. */
    int queueIsEmptyRefeicao(PtQueueRefeicao queue);
    
    //NIVEL V
    //so para manter as duas versoes mas ha que retirar uma das queueEnqueue
    //se for para manter esta entao ha que retirar o Priority do nome
    int queueEnqueuePriority(PtQueueRefeicao queue, QTypeElemRefeicao elem);










#endif	// QUEUEREFEICAO_H

