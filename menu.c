#include "menu.h"
#include "ingresso.h"
#include "questionario.h"
#include <stdio.h>
#include <stdlib.h>

int opcaoExposicao, decisao;

void selecionaModo()
{
    int opcaoModo, opcaoObraSelecionada;

    printf("\nSelecione o modo de operacao do sistema:\n");
    printf("1. Venda de Ingressos; \n2. Validador de Ingressos; \n3. Exibicao de Obras; \n4. Gerar Relatorio de Questionarios\n\n");

    scanf("%d", &opcaoModo);

    system("cls ||clear");

    switch (opcaoModo)
    {
        case 1:
            exibeOpcoes();
            break;
        case 2:
            printf("Selecione uma exposicao:\n");
            printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olimpicos Paris 2024; \n4. Historia da tecnologia;\n0. Sair.\n\n");
            scanf("%d", &opcaoObraSelecionada);

            if (opcaoObraSelecionada < 0 || opcaoObraSelecionada > 4){
                printf("Exposicao invalida:\n");
                sleep(2);
                system("cls ||clear");
                selecionaModo();    
            }

            validaIngresso(opcaoObraSelecionada);
            break;
        case 3:
            printf("Selecione uma exposicao:\n");
            printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olimpicos Paris 2024; \n4. Historia da tecnologia;\n0. Sair.\n\n");
            
            scanf("%d", &opcaoObraSelecionada);
            exibirResumoObra(opcaoObraSelecionada);
            break;

        case 4:
            gerarRelatorio();
            break;
        default:
            printf("Por gentileza, digite uma opcao valida");
            selecionaModo();
            break;
    }
}

void exibeOpcoes()
{  
    printf("\nMuseu Ada Lovelace\n\n");
    
    printf("Obras em cartaz:\n");
    printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olimpicos Paris 2024; \n4. Historia da tecnologia;\n0. Sair.\n\n");

    scanf("%d", &opcaoExposicao);

    system("cls ||clear");

    switch(opcaoExposicao)
    {
        case 1:
            printf("\nExplore a revolucao artistica da Semana de Arte Moderna de 1922. Descubra obras inovadoras que marcaram o inicio do movimento modernista no Brasil. Venha vivenciar a transformacao cultural que moldou a arte brasileira. \n\n");
            validaDecisaoCompra();
            break;
        
         case 2:
            printf("\nComemore os 150 anos de Santos Dumont conosco! Conheca a vida e as inovacoes do pioneiro da aviacao brasileira. Visite nossa exposicao e celebre o legado de um dos maiores inventores da historia. \n\n");
            validaDecisaoCompra();
        break;

         case 3:
            printf("\nTestemunhe os melhores atletas do mundo competindo em um dos eventos esportivos mais prestigiados do planeta. Junte-se a nos e faca parte dessa celebracao esportiva unica. Reserve seu lugar para experienciar a magia olimpica em Paris!\n\n");
            validaDecisaoCompra();
        break;

         case 4:
            printf("\nViaje pela historia da tecnologia conosco! Descubra os avancos revolucionarios que moldaram o mundo moderno. Da invencao da roda aos avan�os da era digital, explore a evolucao que impulsionou a sociedade. \n\n");
           validaDecisaoCompra();
        break;

        case 0:
            sair();
        break;

        default:
            printf("Por gentileza, digite uma opcao valida");
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
