#include "ingresso.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <TIME.H>

int tipoIngresso, pagamento, codIngresso, opcaoExposicao;
char nomeVisitante[50];

struct Ingresso {
    char nome[50];
    int valido;
    int codigo;
    int opcaoExposicao;
};

void compraIngresso(){
    printf("Qual o tipo de ingresso deseja comprar?\n\n1.Inteira\n2.Meia(estudante/professor/idoso)\n3.Isenção\n\n");
    scanf("%d", &tipoIngresso);

    switch(tipoIngresso){

        case 1:
            printf("\nSiga com o pagamento da entrada Inteira no valor de R$15,00\n\n");
            sleep(5);
            formaPagamento();
        break;    

        case 2:
            printf("\nSiga com o pagamento da entrada Meia no valor de R$7,50\n\n");
            sleep(5);
            formaPagamento();
        break;

        case 3:
            printf("Siga com a emissão do seu ingresso e apresente o comprovante de isenção na entrada da exposição escolhida :)");
            sleep(5);
        break; 
    }

    gerarIngresso();   
    validaIngresso();
}

void formaPagamento(){
    system("cls || clear");
    printf("Selecione a forma de pagamento:\n\n1.Cartão de crédito\n2.Cartão de débito\n\n");
    scanf("%d", &pagamento);
    if(pagamento == 1){
        printf("\nSiga com o pagamento via cartão de crédito pela máquina de cartões!\n");
    }
    else{
        printf("\nSiga com o pagamento via cartão de débito pela máquina de cartões!\n");
    }
    sleep(3);
    printf("\nPagamento realizado com sucesso :)");
    sleep(4);
}

void gerarIngresso(){
    system("cls || clear");
    printf("Por gentileza, informe seu nome para gerar seu ingresso: ");
    scanf("%s", nomeVisitante);
    FILE *arquivoInfoIngresso;
    arquivoInfoIngresso = fopen("Arquivo.txt", "a");
   
    srand(time(NULL)); 
    codIngresso = rand() % 10000;
    printf("\nO código do seu ingresso é: %d", codIngresso); 
    fprintf(arquivoInfoIngresso, "%s, %d, %d, %d\n", nomeVisitante, 1, codIngresso, opcaoExposicao);
    fclose(arquivoInfoIngresso);

    printf("\n\nQue a sua visita seja incrível!\n\n");
    sleep(2);
}

void validaIngresso(){
    system("cls || clear");
    printf("-- Validador de Ingressos --");
    printf("\n\nPor gentileza, informe seu nome: ");
    scanf("%s", &nomeVisitante);
    printf("\nInforme o código do ingresso: ");
    scanf("%d", &codIngresso);
    printf("\nInforme o número da exposição escolhida: ");
    scanf("%d", &opcaoExposicao);
    encontrarIngresso(codIngresso);
}

void encontrarIngresso(int codIngresso){
    FILE *arquivo;
    arquivo = fopen("Arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    
    struct Ingresso ingressoEncontrado;
    int ingressoEncontradoFlag = 0; 

    char linha[100]; 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        char *token = strtok(linha, ",");
        if(token == NULL){
            continue;
        }
        strncpy(ingressoEncontrado.nome, token, sizeof(ingressoEncontrado.nome));
        token = strtok(NULL, ",");

        if(token == NULL){
            continue;
        }

        ingressoEncontrado.valido = atoi(token);
        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        ingressoEncontrado.codigo = atoi(token);
        token = strtok(NULL, ",");

        ingressoEncontrado.opcaoExposicao = atoi(token);
     
        if(ingressoEncontrado.codigo == codIngresso){
            ingressoEncontradoFlag = 1;
            break;
        }

    }

    fclose(arquivo);
    
    if (!ingressoEncontradoFlag){
    	printf("\nIngresso com o código '%d' não encontrado.\n", codIngresso);
	} else if(ingressoEncontradoFlag && !ingressoEncontrado.valido) {
		printf("\nIngresso com o código '%d' invalido.\n", codIngresso);
	} else if(ingressoEncontradoFlag && ingressoEncontrado.opcaoExposicao != opcaoExposicao) {
		printf("\nIngresso com o código '%d' invalido para esta exposicao.\n", codIngresso);
	} else {
        printf("\nIngresso encontrado:\n");
        printf("Nome: %s\n", ingressoEncontrado.nome);
        printf("Ingresso valido?: %d\n", ingressoEncontrado.valido);
        printf("Codigo: %d\n", ingressoEncontrado.codigo);
        printf("Numero da exposição escolhida: %d\n", opcaoExposicao);
    }

}
