/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "pilhaPratos.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node;
typedef struct node *PtNode;

typedef struct node {
    typeElement elem;
    PtNode next;
} Node;

typedef struct stackImpl {
    PtNode top;
    int size;
} MyStack;

PtStack stackCreate() {
    PtStack newStack = (MyStack*) malloc(sizeof (MyStack));

    if (newStack == NULL) {
        return NULL;
    }

    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

int stackPush(PtStack stack, typeElement elem) {
    if (stack == NULL) {
        return STACK_NULL;
    }

    //criar novo no para guardar elemento
    PtNode newNode = (PtNode) malloc(sizeof (Node));
    if (newNode == NULL) {
        return STACK_NO_MEMORY;
    }


    PtNode curNode = stack->top;


    while (curNode != NULL) {        
            
      // if (strcmp(curNode->elem.prato, elem.prato) == 0) {
       //     return MESMO_PRATO;
        //}
        curNode = curNode->next;
    }


    newNode->elem = elem;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return STACK_OK;

}

int stackSize(PtStack stack, int *ptSize) {
    if (stack == NULL) {
        return STACK_NULL;
    }

    (*ptSize) = stack->size;
    return STACK_OK;
}

int stackPop(PtStack stack, typeElement *ptElem) {
    if (stack == NULL) {
        return STACK_NULL;
    }
    if (stack->size <= 0) {
        return STACK_EMPTY;
    }

    PtNode curTop = stack->top;
    (*ptElem) = curTop->elem;
    stack->top = curTop->next;

    free(curTop);
    stack->size--;
    return STACK_OK;
}

int stackPeek(PtStack stack, typeElement *ptElem) {
    if (stack == NULL) {
        return STACK_NULL;
    }
    if (stack->size <= 0) {
        return STACK_EMPTY;
    }

    PtNode curTop = stack->top;
    (*ptElem) = curTop->elem;
    return STACK_OK;
}

int stackDestroy(PtStack *ptStack) {
    PtStack curStack = (*ptStack);
    if (curStack == NULL) { return STACK_NULL; }

    typeElement e;
    while(curStack->size > 0) {
        stackPop(curStack, &e);
    }
    
    free(curStack);
    *ptStack = NULL; 
    return STACK_OK;
}

