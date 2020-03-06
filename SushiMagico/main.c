/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: João
 *
 * Created on 19 de Abril de 2017, 15:32
 */
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <winbase.h>
#include "refeicao.h" 

#include "data.h"
#include "cartaoCliente.h" 
#include "restaurante.h"
#include "operacoes.h"
#include "queueCartao.h"
#include  "queueRefeicao.h"
#define FICHEIRO_OPERACOES "OPERACOES.txt"

/*
 * 
 */
//void processarOperacoes( restaurante *suchiMagico);
int main(int argc, char** argv) {
    

    cartaoCliente cartao1 = criarCartaoCliente(1, "joao", "gomes", 21);
    cartaoCliente cartao2 = criarCartaoCliente(2, "joa", "gome", 20);
    cartaoCliente cartao3 = criarCartaoCliente(3, "jo", "gom", 19);
    cartaoCliente cartao4 = criarCartaoCliente(4, "j", "go", 18);

    restaurante suchiMagico = createRestaurante();

    lerFicheiroCartaoCliente(&suchiMagico);
    //ler dados pratos
    lerFicheiroPratos( &suchiMagico);

    int clienteEstaRegistado(int numeroCartao) {// se tiver registado return 1 else return 0;
        for (int i = 0; i < suchiMagico.numeroClientes; i++) {
            if (suchiMagico.listaClientes[i].numeroCartao == numeroCartao) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    int clienteEstaNoBalcao(int numeroCartao) {
        for (int i = 0; i < 4; i++) {
            if (suchiMagico.lugaresBalcao[i] == numeroCartao) {
                return 1;
            }

        }
    }

    int validatePrato(int numeroPrato) {
        for (int i = 0; i<sizeof (suchiMagico.numeroPratoRestaurante); i++) {
            if (numeroPrato == suchiMagico.numeroPratoRestaurante[i]) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    void AD(int day, int month, int year) {
        data ad = criarData(day, month, year);
        imprimeData(ad);
    }

    /*

    void AC(int numeroCartao) {
        cartaoCliente c = getCartaoCliente(numeroCartao, suchiMagico);
        for (int i = 0; i < 4; i++) {
            if (suchiMagico.lugaresBalcao[i] == NULL) {
                suchiMagico.lugaresBalcao[i] = numeroCartao;
            } else {
                if (c.numeroCartao != numeroCartao) {

                    printf("Numero de cartao de cliente desconhecido");


                } else {
                    queueEnqueueCartao(suchiMagico.listaDeEspera, c);
                }
            }
        }


    }
     * */
    void AC(int numeroCartao) {
        if (clienteEstaRegistado(numeroCartao) == 1) {
            for (int i = 0; i < 4; i++) {
                if (suchiMagico.lugaresBalcao[i] == 0) {
                    suchiMagico.lugaresBalcao[i] = numeroCartao;
                    printf("Cliente <%d> colocado ao balcão\n", suchiMagico.lugaresBalcao[i]);
                    break;
                }

            }//perguntar prof
            cartaoCliente m = getCartaoCliente(numeroCartao, suchiMagico);
            queueEnqueueCartao(suchiMagico.listaDeEspera, m);
            printf("Cliente <%d> colocado ao balcão\n", m.numeroCartao);
        } else {
            printf("Cliente <%d> desconhecido\n", numeroCartao);
        }
    }

    /**
    void IR(int numeroCartao, int dia, int mes, int ano) {
       refeicao ref= criarRefeicao(int dia, int mes, int ano)

    }
     * */

    /*
    int isRefeicaoIniciada(int numeroCartao) {
        if (clienteEstaRegistado(int numeroCartao) == 1) {

            if (clienteEstaNoBalcao(numeroCartao) == 1) {
                prato pl;
                cartaoCliente card;
                card = cartaoCliente getCartaoCliente(numeroCartao, suchiMagico);
                refeicao p;
              queuePeekRefeicao(card.filaRefeicoes, &p);
                 //stackPeek(p.pilhaPratosConsumidos, pl);
                  stackPop(p.pilhaPratosConsumidos ,pl );
                 printf( "Último consumo de cliente <%d> - prato <%d> (<%s>)\n",numeroCartao,pl.numeroPrato,pl.nomePrato);
 

            } else {
                printf("Cliente <%d> não está ao balcão", numeroCartao);
            }
        } else {
            printf("Cliente <%d> desconhecido", numeroCartao);
        }
    }
     * 
     * */

    void IR(int numeroCartao) {
        SYSTEMTIME str_t;
        GetSystemTime(&str_t);
        refeicao ref = criarRefeicao(str_t.wDay, str_t.wMonth, str_t.wYear);
        cartaoCliente c = getCartaoCliente(numeroCartao, suchiMagico);
        if (numeroCartao != c.numeroCartao) {
            printf("Numero de cartao de cliente desconhecido \n");
        } else {
            queueEnqueueRefeicao(c.filaRefeicoes, ref);
            printf("Refeição de cliente : %d (%s %s) \n iniciada a :\n", c.numeroCartao, c.nomeCliente, c.apelido);

            imprimeRefeicao(ref);
        }
    }

    void FR(int numeroCartao, int pontos) {

        for (int a = 0; a < suchiMagico.numeroClientes; a++) {
            if (numeroCartao == suchiMagico.listaClientes[a].numeroCartao) {
                for (int i = 0; i < 4; i++) {
                    if (numeroCartao == suchiMagico.lugaresBalcao[i]) {

                        if (suchiMagico.listaClientes[a].pontos < pontos) {
                            suchiMagico.lugaresBalcao[i] = 0;
                            refeicao p;
                            queuePeekRefeicao(suchiMagico.listaClientes[a].filaRefeicoes, &p);
                            imprimeRefeicao(p);
                            double total = 0;

                            while (stackIsEmpty(p.pilhaPratosConsumidos) != 0) {
                                prato t;
                                stackPop(p.pilhaPratosConsumidos, &t);
                                printf("Prato <%d> (<%s>): <%s> <%f>€ \n", t.numeroPrato, t.corPrato, t.nomePrato, t.preco);
                                total += t.preco;
                            }
                            printf("Valor a pagar: %f \n", total);
                        } else {
                            printf("Cliente <%d> - Número de pontos inválido\n", suchiMagico.listaClientes[a].pontos);
                        }
                    } else {
                        printf("Cliente não está no balcao logo não iniciou refeicao \n");
                    }
                }
            } else {
                printf(" Cliente <%d> desconhecido\n", numeroCartao);
            }
        }
    }

    prato getPrato(int numeroPrato, restaurante res) {
        for (int i = 0; i<sizeof (res.PratosRestaurante); i++) {
            if (res.PratosRestaurante[i].numeroPrato == numeroPrato) {
                return res.PratosRestaurante[i];
            }
        }
    }

    void RP(int numeroCartao, int numeroPrato) {
        if (clienteEstaRegistado(numeroCartao) == 1) {
            if (clienteEstaNoBalcao(numeroCartao) == 1) {
                if (validatePrato(numeroPrato)) {
                    cartaoCliente cartao;
                    prato plate;
                    refeicao refei;
                    plate = getPrato(numeroPrato, suchiMagico);
                    cartao = getCartaoCliente(numeroCartao, suchiMagico);
                    queuePeekRefeicao(cartao.filaRefeicoes, &refei);
                    stackPush(refei.pilhaPratosConsumidos, plate);



                    printf("Cliente <%d> empilha prato <%d> (<%s>)\n", numeroCartao, numeroPrato, plate.nomePrato);
                } else {
                    printf("Prato <%d> desconhecido\n", numeroPrato);
                }
            } else {
                printf("Cliente <%d> não está ao balcão\n", numeroCartao);
            }
        } else {
            printf("Cliente <%d> desconhecido\n", numeroCartao);
        }
    }

    /**
     * 
     * UP <numeroCartao>: Último Prato consumido, com indicação do número de cartão. 
     * Parte-se do princípio que é referente a refeição iniciada, caso cliente esteja ao balcão. 
     * Outputs possíveis: Caso a operação não tenha sucesso 
     * ▪ Cliente <numeroCartao> desconhecido 
     * ▪ Cliente <numeroCartao> não está ao balcão 
     * Caso a operação tenha sucesso
     *  ▪ Último consumo de cliente <numeroCartao> - prato <numeroPrato> (<nomePeça>)  
 
     */
    void UP(int numeroCartao) {
        if (clienteEstaRegistado(numeroCartao) == 1) {

            if (clienteEstaNoBalcao(numeroCartao) == 1) {
                prato pl;
                cartaoCliente cartao;
                cartao = getCartaoCliente(numeroCartao, suchiMagico);
                refeicao p;
                queuePeekRefeicao(cartao.filaRefeicoes, &p);
                //stackPeek(p.pilhaPratosConsumidos, pl);
                stackPop(p.pilhaPratosConsumidos, &pl);
                printf("Último consumo de cliente <%d> - prato <%d> (<%s>)\n", numeroCartao, pl.numeroPrato, pl.nomePrato);


            } else {
                printf("Cliente <%d> não está ao balcão\n", numeroCartao);
            }
        } else {
            printf("Cliente <%d> desconhecido\n", numeroCartao);
        }

    }

    /*
    CP <numeroCartao> : Conta Pratos consumidos até ao momento na refeição,
            com indicação do número de cartão.
            Parte - se do princípio que é referente a refeição iniciada, caso cliente esteja ao balcão.
                Outputs possíveis : Caso a operação não tenha sucesso
                ▪ Cliente <numeroCartao> desconhecido
                ▪ Cliente <numeroCartao> não está ao balcão
                Caso a operação tenha sucesso
                ▪ Cliente <numeroCartao> -Contagem de pratos : <contaPratos >



     */
    void CP(int numeroCartao) {
        if (clienteEstaRegistado(numeroCartao) == 1) {

            if (clienteEstaNoBalcao(numeroCartao) == 1) {
                int x = 0;
              int *tamanho;

               tamanho = &x;

                
                 cartaoCliente cartao;
                cartao = getCartaoCliente(numeroCartao, suchiMagico);
                refeicao p;
                queuePeekRefeicao(cartao.filaRefeicoes, &p);
                 stackSize(p.pilhaPratosConsumidos , &tamanho );
              printf(  "Cliente <%d> - Contagem de pratos: <%d>\n",numeroCartao,&tamanho );
            } else {
                printf("Cliente <%d> não está ao balcão\n", numeroCartao);
            }
        } else {
            printf("Cliente <%d> desconhecido\n", numeroCartao);
        }
    }
    /*
     * VC <numeroCartao>: Visualizar dados de Cartão, com indicação do número de cartão,
     *  tendo o objetivo de consultar o total de pontos acumulados até ao momento e o número de refeições efetuadas no último mês. 
     * Outputs possíveis: 
     * Caso a operação não tenha sucesso 
     * ▪ Cliente <numeroCartao> desconhecido 
     * Caso a operação tenha sucesso 
     * ▪ Cliente <numeroCartao> (<nomeProprio> <apelido>) com <totalPontos> pontos acumulados 
     * e <numeroRefeicoes> refeições no último mês 
 
     */
    /*
     * CE: listagem de Clientes em Espera por lugar ao balcão,
     * apresentando também a contagem. 
     * Outputs possíveis: 
     * Caso a operação não tenha sucesso 
     * ▪ Fila de espera inexistente 
     * Caso a operação tenha sucesso (exemplo de 2 clientes) 
     * ▪ <contagemClientesEmFila> clientes em fila de espera: 

 [<numeroCartao>] <apelido> <nomeProprio> (<idade> anos) [<numeroCartao>] <apelido> <nomeProprio> (<idade> anos) 
     */
    /*
    void CE(int numeroCartao)
    {
       if(queueIsEmptyCartao(suchiMagico.listaDeEspera)==0)
        {
           // cartaoCliente cartao;
             //   cartao = getCartaoCliente(numeroCartao, suchiMagico);
            int x = 0;
              int *tamanho;
               tamanho = &x;
               queueSizeCartao(suchiMagico.listaDeEspera, &tamanho);
           while(tamanho!=0)
           {
               
               queuePeekRefeicao(suchiMagico.listaDeEspera, QTypeElemRefeicao *ptElem);
           printf("<contagemClientesEmFila> clientes em fila de espera:\n" )

    printf("[<numeroCartao>] <apelido> <nomeProprio> (<idade> anos) [<numeroCartao>] <apelido> <nomeProprio> (<idade> anos)" );
        }
       }
       else
       {
        printf("Fila de espera inexistente\n" );  
       }
    }
    
*/

    // processarOperacoes(&suchiMagico);
    // processarOperacoes( &suchiMagico);

    adicionarClienteRestaurante(&suchiMagico, cartao1);
    adicionarClienteRestaurante(&suchiMagico, cartao2);
    adicionarClienteRestaurante(&suchiMagico, cartao3);
    adicionarClienteRestaurante(&suchiMagico, cartao4);
    mostrarListaClientes(suchiMagico);

    // bALCAO 4 POS

    //  cartaoCliente    lugares[4];


    // fila de espera 
    // cartaoCliente    lugaresFila[100];

    data date1 = criarData(02, 04, 2017);

    imprimeData(date1);

    cartaoCliente cartao0 = criarCartaoCliente(1, "joao", "gomes", 21);
    // lugares[0]=cartao0;

    imprimeCartao(cartao0);


    // refeicao refeicao1= criarRefeicao(lugares[0]);
    //imprimeRefeicao(refeicao1);


void processarOperacoes( restaurante *suchiMagico){
    //abrir o fich fOps.... etc...
   FILE *fileLeitura;
    fileLeitura = fopen(FICHEIRO_OPERACOES, "r");
    
    char linha[1024];
    char op[3];
    int numCartao;
    
    while (fgets(linha, sizeof(linha), fileLeitura)) {
        fscanf(linha, "%s", op);
        if (strcmp(op, "AC") == 0){
            fscanf(linha, "%d", &numCartao);
            
            AC(numCartao);
        }
        if (strcmp(op, "AD") == 0){
            int d, m, a;
            fscanf(linha, "%d/%d/%d", &d, &m, &a);
            
            AD( d,  m,  a);
        }
        if (strcmp(op, "RP") == 0){
            int numPrato;
            fscanf(linha, "%d %d", &numCartao, &numPrato);
            RP( numCartao,  numPrato);
            
            //chamar a funcao da AC e fazer o que ha a fazer
        }
        if (strcmp(op, "IR") == 0){
           // int numPrato;
            fscanf(linha, "%d", &numCartao);
            IR( numCartao);
    }
        if (strcmp(op, "FR") == 0){
           // int numPrato;
            int pontos;
            fscanf(linha, "%d %d", &numCartao, &pontos);
            FR( numCartao,pontos);
    }
        if (strcmp(op, "RP") == 0){
           // int numPrato;
            //int pontos;
            //UP(int numeroCartao)
            int numPrato;
            fscanf(linha, "%d %d", &numCartao, &numPrato);
            RP( numCartao,  numPrato);
    }
        if (strcmp(op, "UP") == 0){
           // int numPrato;
            //int pontos;
            //UP(int numeroCartao)
            //int numPrato;
            fscanf(linha, "%d", &numCartao);
            UP( numCartao);
             //void CP(int numeroCartao)
    }
        if (strcmp(op, "CP") == 0){
           // int numPrato;
            //int pontos;
            //UP(int numeroCartao)
           // int numPrato;
            fscanf(linha, "%d", &numCartao);
            
              CP( numCartao);
    }
    
}
}
// processarOperacoes( &suchiMagico);

    return (EXIT_SUCCESS);
}
/*
void processarOperacoes( restaurante *suchiMagico){
    //abrir o fich fOps.... etc...
   FILE *fileLeitura;
    fileLeitura = fopen(FICHEIRO_OPERACOES, "r");
    
    char linha[1024];
    char op[3];
    int numCartao;
    
    while (fgets(linha, sizeof(linha), fileLeitura)) {
        fscanf(linha, "%s", op);
        if (strcmp(op, "AC") == 0){
            fscanf(linha, "%d", &numCartao);
            
            AC(numCartao);
        }
        if (strcmp(op, "AD") == 0){
            int d, m, a;
            fscanf(linha, "%d/%d/%d", &d, &m, &a);
            
            AD( d,  m,  a);
        }
        if (strcmp(op, "RP") == 0){
            int numPrato;
            fscanf(linha, "%d %d", &numCartao, &numPrato);
            RP( numCartao,  numPrato);
            
            //chamar a funcao da AC e fazer o que ha a fazer
        }
        if (strcmp(op, "IR") == 0){
           // int numPrato;
            fscanf(linha, "%d", &numCartao);
            IR( numCartao);
    }
        if (strcmp(op, "FR") == 0){
           // int numPrato;
            int pontos;
            fscanf(linha, "%d %d", &numCartao, &pontos);
            FR( numCartao,pontos);
    }
        if (strcmp(op, "RP") == 0){
           // int numPrato;
            //int pontos;
            //UP(int numeroCartao)
            int numPrato;
            fscanf(linha, "%d %d", &numCartao, &numPrato);
            RP( numCartao,  numPrato);
    }
        if (strcmp(op, "UP") == 0){
           // int numPrato;
            //int pontos;
            //UP(int numeroCartao)
            //int numPrato;
            fscanf(linha, "%d", &numCartao);
            UP( numCartao);
             //void CP(int numeroCartao)
    }
        if (strcmp(op, "CP") == 0){
           // int numPrato;
            //int pontos;
            //UP(int numeroCartao)
           // int numPrato;
            fscanf(linha, "%d", &numCartao);
            
              CP( numCartao);
    }
    
}
}
}*/
