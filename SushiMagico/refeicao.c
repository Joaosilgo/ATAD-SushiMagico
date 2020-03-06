/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "refeicao.h"
#include "data.h"

#include "cartaoCliente.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
// #include <stdio.h>



refeicao criarRefeicao(int dia, int mes, int ano)

{
    SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	
    refeicao ref;
    ref.pilhaPratosConsumidos=stackCreate();
    ref.dataRefeicao=criarData(dia, mes, ano);
    ref.valorFinal=0;
    /*
    for(int i=0; i<sizeof(ref.cartao.listaRefeicoes) ; i++)
    {
        if(ref.cartao.listaRefeicoes[i] == NULL)
        {
            ref.cartao.listaRefeicoes[i]=ref;
        }
    }
     * */
    return ref;
    }
            



void imprimeRefeicao(refeicao refei)
{
   // printf("fereicao iniciada Por: \n");
   // imprimeCartao ( refei.cartao);
    
     printf("Data: \n");
     imprimeData(refei.dataRefeicao);
     


}
