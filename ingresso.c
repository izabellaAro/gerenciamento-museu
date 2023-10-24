#include "ingresso.h"
#include "menu.h"
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

    system("cls ||clear");
    exibeOpcoes();
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

void gerarIngresso()
{
    system("cls || clear");

    struct Ingresso ingresso;
    int retorno;
    FILE *arq = fopen("ingressos.txt", "ab");

    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }

    printf("Por gentileza, informe seu nome para gerar seu ingresso: ");
    scanf("%s", nomeVisitante);

    srand(time(NULL)); 
    codIngresso = rand() % 10000;

    strcpy(ingresso.nome, nomeVisitante);
    ingresso.codigo = codIngresso;
    ingresso.valido = 1;
    ingresso.opcaoExposicao = opcaoExposicao;
    
    retorno = fwrite(&ingresso, sizeof(ingresso), 1, arq);

    if (retorno == 1)
    {
        fclose(arq);
        
        printf("\nO código do seu ingresso é: %d", codIngresso);
        printf("\n\nQue a sua visita seja incrível!\n\n");
        sleep(2);
    }
    else
    {
        fclose (arq);
        printf("\n Falha ao gravar dados.");
    }
}

void validaIngresso(int exposicao){
    system("cls || clear");
    printf("-- Validador de Ingressos --");
    printf("\n\nPor gentileza, informe seu nome: ");
    scanf("%s", &nomeVisitante);
    printf("\nInforme o código do ingresso: ");
    scanf("%d", &codIngresso);
    
    opcaoExposicao = exposicao;

    encontrarIngresso(codIngresso);
    sleep(2);
    validaIngresso(exposicao);
}

void encontrarIngresso(int codIngresso)
{
    FILE *arq = fopen("ingressos.txt", "r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }

    struct Ingresso ingresso;
    int encontrado = 0;

    while (fread(&ingresso, sizeof(ingresso), 1, arq))
    {
        if (ingresso.codigo == codIngresso && strcmp(ingresso.nome, nomeVisitante) == 0)
        {
            encontrado = 1;

            if (!ingresso.valido)
            {
                printf("\nIngresso com o código '%d' invalido.\n", codIngresso);
            } else if(ingresso.opcaoExposicao != opcaoExposicao) {
		        printf("\nIngresso com o código '%d' invalido para esta exposicao.\n", codIngresso);
	        } else {
                printf("\nIngresso encontrado:\n");
                printf("Nome: %s\n", ingresso.nome);
                printf("Ingresso valido?: %d\n", ingresso.valido);
                printf("Codigo: %d\n", ingresso.codigo);
                printf("Numero da exposição escolhida: %d\n", opcaoExposicao);

                fseek(arq, sizeof(struct Ingresso)*-1, SEEK_CUR);

                ingresso.valido = 0;

                fwrite(&ingresso, sizeof(ingresso), 1, arq);
                fseek(arq, sizeof(ingresso)* 0, SEEK_END);
            }
        }
    }

    if (!encontrado)
    {
        printf("\nIngresso com o código '%d' não encontrado.\n", codIngresso);
    }
    fclose(arq);
}
