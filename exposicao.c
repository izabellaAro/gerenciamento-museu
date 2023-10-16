#include "exposicao.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exibirResumoObra(int obra){
    system("cls ||clear");
    char decisaoPesquisa[1];

    switch (obra)
    {
        case 1:
            lerArquivoResumoObra("resumos/semanaResumo.txt");
            break;
        case 2:
            lerArquivoResumoObra("resumos/dumontResumo.txt");
            break;
        case 3:
            lerArquivoResumoObra("resumos/olimpiadasResumo.txt");
            break;
        case 4:
            lerArquivoResumoObra("resumos/tecnologiaResumo.txt");
            break;
        default:
            printf("Obra invalida.");
            sleep(2);
            selecionaModo(obra);
            break;
    }
    
    printf("\n\nGostaria de participar de uma pesquisa de satisfação referente a sua visita? [S / N]: ");
    scanf("%s", &decisaoPesquisa);

    if(strcmp(decisaoPesquisa, "S") == 0){
        questionario(); 
        sleep(2);
        system("cls ||clear");
    }else
    {
        printf("\nObrigada por visitar! Volte sempre :)");
        sleep(2);
        system("cls ||clear");
        lerArquivoResumoObra(obra);
    }
}

void lerArquivoResumoObra(char* nomeArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");

    char linha[400]; 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf(linha);
    }
}

void questionario(){
    system("cls ||clear");
    
    int respostaPesquisa[5];

        printf("\nAvalie de 0 a 5:\n\n");
        printf("Qual foi o nível de satisfação geral com a sua visita?\n(0) Muito insatisfeito\n(1) Insatisfeito\n(2) Neutro\n(3) Satisfeito\n(4) Muito satisfeito\n(5) Extremamente satisfeito\n");
        scanf("%d", &respostaPesquisa[0]);
        printf("\nComo você avaliaria a qualidade do atendimento ao cliente?\n(0) Muito ruim\n(1) Ruim\n(2) Aceitável\n(3) Bom\n(4) Muito bom\n(5) Excelente\n");
        scanf("%d", &respostaPesquisa[1]);
        printf("\nA limpeza e organização do local atenderam às suas expectativas?\n(0) Muito abaixo do esperado\n(1) Abaixo do esperado\n(2) Satisfatório\n(3) Acima do esperado\n(4) Muito acima do esperado\n(5) Excepcional\n");
        scanf("%d", &respostaPesquisa[2]);
        printf("\nComo você classificaria a variedade de obras expostas?\n(0) Muito limitada\n(1) Limitada\n(2) Suficiente\n(3) Boa\n(4) Muito boa\n(5) Excelente\n");
        scanf("%d", &respostaPesquisa[3]);
        printf("\nVocê consideraria retornar a este local ou recomendaria a outras pessoas?\n(0) Definitivamente não\n(1) Provavelmente não\n(2) Talvez\n(3) Provavelmente sim\n(4) Definitivamente sim\n(5) Com certeza\n");
        scanf("%d", &respostaPesquisa[4]);
        printf("\nObrigada por participar! Volte sempre :)");

    FILE *pesquisaSat;
    pesquisaSat = fopen("respostasQuestionario.txt", "a");
    fprintf(pesquisaSat, "%d, %d, %d, %d, %d\n", respostaPesquisa[0], respostaPesquisa[1], respostaPesquisa[2], respostaPesquisa[3], respostaPesquisa[4]);
    fclose(pesquisaSat);
}
