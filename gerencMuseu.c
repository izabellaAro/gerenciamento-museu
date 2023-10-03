#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    menu();
    return 0;
}

int opcaoExposicao, decisao;

void menu()
{  
    printf("\n\nMuseu Ada Lovelace\n\n");
    
    printf("Obras em cartaz:\n");
    printf("1. 100 da semana da arte moderna; \n2. 150 anos de Santos Dumont; \n3. Jogos olímpicos Paris 2024; \n4. História da tecnologia;\n0. Sair.\n\n");

    scanf("%d", &opcaoExposicao);

    switch(opcaoExposicao)
    {
        case 1:
            printf("Resumo da Obra 1\n\n");
            opcaoDecisao();
        break;
        
         case 2:
            printf("Resumo da Obra 2\n\n");
            opcaoDecisao();
        break;

         case 3:
            printf("Resumo da Obra 3\n\n");
            opcaoDecisao();
        break;

         case 4:
            printf("Resumo da Obra 4\n\n");
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
    printf("Para adquirir o ingresso, digite 1. \nPara voltar ao menu aperte qualquer tecla.");
    scanf("%d", &decisao);

    if(decisao == 1) { 
        printf("Página de pagamento");}
    else {
        retornarMenu();}
}