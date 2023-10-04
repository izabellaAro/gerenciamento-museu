#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <TIME.H>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    menu();
    return 0;
}

int opcaoExposicao, decisao, tipoIngresso, pagamento;
char nomeVisitante;

void menu()
{  
    printf("\n\nMuseu Ada Lovelace\n\n");
    
    printf("Obras em cartaz:\n");
    printf("1. 100 anos da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olímpicos Paris 2024; \n4. História da tecnologia;\n0. Sair.\n\n");

    scanf("%d", &opcaoExposicao);

    system("cls ||clear");

    switch(opcaoExposicao)
    {
        case 1:
            printf("\nResumo da Obra 1\n\n");
            opcaoDecisao();
        break;
        
         case 2:
            printf("\nResumo da Obra 2\n\n");
            opcaoDecisao();
        break;

         case 3:
            printf("\nResumo da Obra 3\n\n");
            opcaoDecisao();
        break;

         case 4:
            printf("\nResumo da Obra 4\n\n");
           opcaoDecisao();
        break;

        case 0:
            sair();
        break;

        default:
            printf("Por gentileza, digite uma opção válida");
            retornarMenu();
            
    }

}

void retornarMenu() {
    getchar();
    getchar();
    system("cls ||clear");
    menu();
}

void sair(){
    printf("Obrigado por visitar nosso museu. Volte logo :)\n");
    system("pause");
}

void opcaoDecisao(){
    printf("Para adquirir o ingresso, digite 1. \nPara voltar ao menu aperte qualquer tecla.\n\n");
    scanf("%d", &decisao);

    if(decisao == 1) { 
        system("cls || clear");
        compraIngresso();
    }
    else {
        retornarMenu();
    }
}

void compraIngresso(){
    printf("Qual o tipo de ingresso deseja comprar?\n\n1.Inteira\n2.Meia(estudante/professor/idoso)\n3.Isenção\n\n");
    scanf("%d", &tipoIngresso);

    switch(tipoIngresso){

        case 1:
            printf("\nSiga com o pagamento da entrada Inteira no valor de R$15,00\n\n");
            formaPagamento();
        break;    

        case 2:
            printf("\nSiga com o pagamento da entrada Meia no valor de R$7,50\n\n");
            formaPagamento();
        break;

        case 3:
            printf("Siga com a emissão do seu ingresso e apresente o comprovante de isenção na entrada da exposição escolhida :)");
        break; 
    }

    gerarIngresso();    
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
    printf("\nPagamento realizado com sucesso :)");
    sleep(51);
}

void gerarIngresso(){
    system("cls || clear");
    printf("Por gentileza, informe seu nome e sobrenome: ");
    scanf("%s", &nomeVisitante);
    printf("\n\nQue a sua visita seja incrível!\n\n");
}