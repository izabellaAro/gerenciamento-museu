#include "menu.h"
#include "ingresso.h"
#include <stdio.h>
#include <stdlib.h>

int opcaoExposicao, decisao;

void selecionaModo()
{
    int opcaoModo, opcaoObraSelecionada;

    printf("Selecione o modo de operção do sistema:\n");
    printf("1. Venda de Ingressos; \n2. Validador de Ingressos; \n3. Exibição de Obras.\n\n");

    scanf("%d", &opcaoModo);

    system("cls ||clear");

    switch (opcaoModo)
    {
        case 1:
            exibeOpcoes();
            break;
        case 2:
            printf("Selecione uma exposicao:\n");
            printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olímpicos Paris 2024; \n4. História da tecnologia;\n0. Sair.\n\n");
            scanf("%d", &opcaoObraSelecionada);

            validaIngresso(opcaoObraSelecionada);
            break;
        case 3:
            printf("Selecione uma exposicao:\n");
            printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olímpicos Paris 2024; \n4. História da tecnologia;\n0. Sair.\n\n");
            
            scanf("%d", &opcaoObraSelecionada);
            exibirResumoObra(opcaoObraSelecionada);
            break;
        default:
            printf("Por gentileza, digite uma opção válida");
            selecionaModo();
            break;
    }
}

void exibeOpcoes()
{  
    printf("\n\nMuseu Ada Lovelace\n\n");
    
    printf("Obras em cartaz:\n");
    printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olímpicos Paris 2024; \n4. História da tecnologia;\n0. Sair.\n\n");

    scanf("%d", &opcaoExposicao);

    system("cls ||clear");

    switch(opcaoExposicao)
    {
        case 1:
            printf("\nExplore a revolução artística da Semana de Arte Moderna de 1922. Descubra obras inovadoras que marcaram o início do movimento modernista no Brasil. Venha vivenciar a transformação cultural que moldou a arte brasileira. \n\n");
            validaDecisaoCompra();
            break;
        
         case 2:
            printf("\nComemore os 150 anos de Santos Dumont conosco! Conheça a vida e as inovações do pioneiro da aviação brasileira. Visite nossa exposição e celebre o legado de um dos maiores inventores da história. \n\n");
            validaDecisaoCompra();
        break;

         case 3:
            printf("\nTestemunhe os melhores atletas do mundo competindo em um dos eventos esportivos mais prestigiados do planeta. Junte-se a nós e faça parte dessa celebração esportiva única. Reserve seu lugar para experienciar a magia olímpica em Paris!\n\n");
            validaDecisaoCompra();
        break;

         case 4:
            printf("\nViaje pela história da tecnologia conosco! Descubra os avanços revolucionários que moldaram o mundo moderno. Da invenção da roda aos avanços da era digital, explore a evolução que impulsionou a sociedade. \n\n");
           validaDecisaoCompra();
        break;

        case 0:
            sair();
        break;

        default:
            printf("Por gentileza, digite uma opção válida");
            retornaParaOpcoes();
    }
}

void retornaParaOpcoes() {
    getchar();
    getchar();
    system("cls ||clear");
    exibeOpcoes();
}

void validaDecisaoCompra(){
    printf("Para adquirir o ingresso, digite 1. \nPara voltar ao menu aperte qualquer tecla.\n\n");
    scanf("%d", &decisao);

    if(decisao == 1) { 
        system("cls || clear");
        compraIngresso();
    }
    else {
        retornaParaOpcoes();
    }
}

void sair(){
    printf("Obrigado por visitar nosso museu. Volte logo :)\n");
    system("pause");
}
