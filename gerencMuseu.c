#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <TIME.H>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    menu();
    return 0;
}


int opcaoExposicao, decisao, tipoIngresso, pagamento, codIngresso;
char nomeVisitante[50];


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
            printf("\nExplore a revolução artística da Semana de Arte Moderna de 1922. Descubra obras inovadoras que marcaram o início do movimento modernista no Brasil. Venha vivenciar a transformação cultural que moldou a arte brasileira. \n\n");
            opcaoDecisao();
            break;
        
         case 2:
            printf("\nComemore os 150 anos de Santos Dumont conosco! Conheça a vida e as inovações do pioneiro da aviação brasileira. Visite nossa exposição e celebre o legado de um dos maiores inventores da história. \n\n");
            opcaoDecisao();
        break;

         case 3:
            printf("\nTestemunhe os melhores atletas do mundo competindo em um dos eventos esportivos mais prestigiados do planeta. Junte-se a nós e faça parte dessa celebração esportiva única. Reserve seu lugar para experienciar a magia olímpica em Paris!\n\n");
            opcaoDecisao();
        break;

         case 4:
            printf("\nViaje pela história da tecnologia conosco! Descubra os avanços revolucionários que moldaram o mundo moderno. Da invenção da roda aos avanços da era digital, explore a evolução que impulsionou a sociedade. \n\n");
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
    fprintf(arquivoInfoIngresso, "%s, %d, %d\n", nomeVisitante, 1, codIngresso);
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
    encontrarIngresso(codIngresso);
}

struct Ingresso {
    char nome[50];
    int valido;
    int codigo;
};

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

        if(ingressoEncontrado.codigo == codIngresso){
            ingressoEncontradoFlag = 1;
        }       

    }

    fclose(arquivo);

    if (ingressoEncontradoFlag) {
        printf("\nIngresso encontrado:\n");
        printf("Nome: %s\n", ingressoEncontrado.nome);
        printf("Ingresso valido?: %d\n", ingressoEncontrado.valido);
        printf("Codigo: %d\n", ingressoEncontrado.codigo);
    } 
        else {
        printf("\nIngresso com o código '%d' não encontrado.\n", codIngresso);
    }
}
