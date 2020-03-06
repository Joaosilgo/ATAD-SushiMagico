/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "queueRefeicao.h"
#include <stdlib.h>

struct qnodeRefeicao;
typedef struct qnodeRefeicao *PtQNodeRefeicao;

typedef struct qnodeRefeicao {
    QTypeElemRefeicao elem;
    PtQNodeRefeicao next;
} QNodeRefeicao;

typedef struct queueImplRefeicao {
    PtQNodeRefeicao head;
    PtQNodeRefeicao tail;
    int size;
} MyQueue1;

PtQueueRefeicao queueCreateRefeicao () {
    PtQueueRefeicao newQueue = (MyQueue1*) malloc(sizeof (MyQueue1));

    if (newQueue == NULL) {
        return NULL;
    }

    newQueue->head = NULL; /* inicializar cabeca da lista */
    newQueue->tail = NULL; /* inicializar cauda da lista */
    newQueue->size = 0;
    return newQueue;
}

int queueDestroyRefeicao (PtQueueRefeicao *ptQueue) {
    PtQueueRefeicao curQueue = (*ptQueue);
    if (curQueue == NULL) {
        return QUEUE_NULL;
    }

    QTypeElemRefeicao aux;
    while (curQueue->size > 0) { /* explorar impl. de dequeue */
        queueDequeueRefeicao(curQueue, &aux);
    }

    free(curQueue);
    *ptQueue = NULL; /* colocar valor de ponteiro a NULL */
    return QUEUE_OK;
}

// esta operacao deveria ser alterada para o NIVEL V alinea c)
// mas mantem-se por causa dos primeiros niveis
// e para efeitos de estudo comparando com a operacao com prioridade
int queueEnqueueRefeicao (PtQueueRefeicao queue, QTypeElemRefeicao elem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }

    PtQNodeRefeicao newNode = (PtQNodeRefeicao) malloc(sizeof (PtQNodeRefeicao));
    if (newNode == NULL) {
        return QUEUE_NO_MEMORY;
    }

    newNode->elem = elem;
    newNode->next = NULL;

    /* insercao na tail (cauda da fila) */
    if (queue->size == 0) { /* se for o primeiro elemento a inserir numa fila vazia */
        queue->head = newNode;
    } else { /* caso contrario */
        queue->tail->next = newNode;
    }
    queue->tail = newNode; /* op. em comum para as duas situacoes */

    queue->size++;
    return QUEUE_OK;
}

/******************** Nível V ****************/
/**
 * 
 * @param queue
 * @param elem
 * @return 
 
int queueEnqueuePriority(PtQueue queue, QTypeElem elem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }

    PtQNode newNode = (PtQNode) malloc(sizeof (QNode));
    if (newNode == NULL) {
        return QUEUE_NO_MEMORY;
    }

    newNode->elem = elem;
    newNode->next = NULL;

    /* insercao na tail (cauda da fila) 
    /* se for o primeiro elemento a inserir numa fila vazia 
    if (queue->size == 0) {
        queue->head = newNode;
        queue->tail = newNode;
    } 
    else // se for para inserir na cabeca 
    if (compareElemsPriority(queue->head->elem, newNode->elem) > 0) {
        newNode->next = queue->head;
        queue->head = newNode;
    } else { // caso contrario percorre-se a fila ate encontrar a posicao
        PtQNode currNode = queue->head;
        while (currNode->next != NULL &&
                compareElemsPriority(currNode->next->elem, newNode->elem) <= 0) {
            currNode = currNode->next;
        }

        if (currNode->next != NULL) { //algures a meio
            newNode->next = currNode->next;
        } else { //ultimo elemento... na cauda
            queue->tail = newNode;
        }
        //igual seja a meio ou cauda
        currNode->next = newNode;

    }

    queue->size++;
    return QUEUE_OK;
}

*/


int queueDequeueRefeicao (PtQueueRefeicao queue, QTypeElemRefeicao *ptElem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }
    if (queue->size <= 0) {
        return QUEUE_EMPTY;
    }

    /* removao da head (inicio da fila) */
    PtQNodeRefeicao curHead = queue->head;
    (*ptElem) = curHead->elem;

    queue->head = curHead->next; /* avancar ponteiro; pode ser NULL no caso abaixo */

    if (queue->size == 1) { /* ..se vamos retirar o unico elemento existente */
        queue->tail = NULL; /* cauda deixa de existir */
    }

    free(curHead); /* libertar memórica alocada para o nó */

    queue->size--;
    return QUEUE_OK;
}

int queuePeekRefeicao (PtQueueRefeicao queue, QTypeElemRefeicao *ptElem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }
    if (queue->size <= 0) {
        return QUEUE_EMPTY;
    }

    /* espreitar na head (inicio da fila) */
    PtQNodeRefeicao curHead = queue->head;
    (*ptElem) = curHead->elem;
    return QUEUE_OK;
}

int queueSizeRefeicao (PtQueueRefeicao queue, int *ptSize) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }

    (*ptSize) = queue->size;
    return QUEUE_OK;
}

int queueIsEmptyRefeicao (PtQueueRefeicao queue) {
    if (queue == NULL) {
        return 1;
    } /* consideramos inexistente como vazia */

    return (queue->size == 0) ? 1 : 0;
}