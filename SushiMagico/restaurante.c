/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdlib.h>
#include<string.h>
#include "restaurante.h"
#include "prato.h"
#define MAX_CLIENTES 100

#define FICHEIRO_CLIENTES "clientes.txt"
#define FICHEIRO_PRATOS "pratos.txt"
// #define FICHEIRO_CLIENTES "cliente.txt"

restaurante createRestaurante() {
    restaurante res;
    res.numeroClientes = 0;
    res.listaDeEspera = queueCreateCartao();
    
    


    return res;
}

void adicionarClienteRestaurante(restaurante *restaurante, cartaoCliente cliente) {
    if (restaurante->numeroClientes < MAX_CLIENTES) {
        restaurante->listaClientes[restaurante->numeroClientes] = cliente;
        restaurante->numeroClientes++;
    }
}

void mostrarListaClientes(restaurante res) {


    int i;

    for (i = 0; i < res.numeroClientes; i++) {


        printf("Numero: %d | Nome: %s %s | idade: %d | \n", res.listaClientes[i].numeroCartao, res.listaClientes[i].nomeCliente, res.listaClientes[i].apelido, res.listaClientes[i].idade);

    }
}

void lerFicheiroCartaoCliente(restaurante *suchiMagico) {
    FILE *fileLeitura;
    fileLeitura = fopen(FICHEIRO_CLIENTES, "r");

    char nomeCliente[50];
    char apelido[50];
    int idade;
    // data dataNascimento;
    int numeroCartao;

    //int pontos;
    //  refeicao listaRefeicoes[];


    cartaoCliente cliente;
    int i = 0;
    while (!feof(fileLeitura)) {
        fscanf(fileLeitura, "%d %s %s %d", &numeroCartao, nomeCliente, apelido, &idade);

        cliente = criarCartaoCliente(numeroCartao, nomeCliente, apelido, idade);
        suchiMagico->listaClientes[i] = cliente;
        adicionarClienteRestaurante(&suchiMagico, cliente);
        // adicionarUtenteClinica (cl,ut); 
        i++;
    }
}

void lerFicheiroPratos(restaurante *suchiMagico) {
    FILE *fileLeitura;
    fileLeitura = fopen(FICHEIRO_PRATOS, "r");

    int numeroPrato;
    char nomePrato[50];
    double preco;
    char corPrato[20];
    prato p;
    int i = 0;
    while (!feof(fileLeitura)) {
        fscanf(fileLeitura, "%d %s %d %s", &numeroPrato, nomePrato, &preco, corPrato);

        p = criaPrato(numeroPrato, nomePrato, corPrato, preco, 250);
        suchiMagico->numeroPratoRestaurante[i] = p.numeroPrato;
        suchiMagico->PratosRestaurante[i]=p;
        // adicionarUtenteClinica (cl,ut); 
        i++;
    }

}

cartaoCliente getCartaoCliente(int numeroCartao, restaurante res) {
    for (int i = 0; i < res.numeroClientes; i++) {
        if (numeroCartao == res.listaClientes[i].numeroCartao) {
            return res.listaClientes[i];


        }
        
    }
}

/*

cartaoCliente getCartaoClienteNoBalcao(int numeroCartao, restaurante res)
{
    for(int i=0; i<4;i++)
    {
        if(numeroCartao==res.lugaresBalcao[i])
        {
            
        }
    }
}
 *  
 */
