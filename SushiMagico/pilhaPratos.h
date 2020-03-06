/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilhaPratos.h
 * Author: João
 *
 * Created on 27 de Abril de 2017, 16:07
 */




#ifndef PILHAPRATOS_H
#define PILHAPRATOS_H

#include "typeElement.h"

#define STACK_OK 0
#define STACK_NULL 1
#define STACK_NO_MEMORY 2
#define STACK_EMPTY 3
#define STACK_FULL 4
#define MESMO_PRATO 5 

struct stackImpl;

typedef struct stackImpl *PtStack;

PtStack stackCreate();
int stackPush(PtStack stack, typeElement elem);
int stackSize(PtStack stack, int *PtSize);
int stackPeek(PtStack stack, typeElement *PtElem );
int stackPop(PtStack stack, typeElement *PtElem );
int stackIsEmpty(PtStack stack);



#endif	// PILHAPRATOS_H

