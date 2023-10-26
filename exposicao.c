#include "exposicao.h"
#include "questionario.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exibirResumoObra(int obra){
    system("cls ||clear");
    char decisaoPesquisa[1];
    char* caminhoResumos[4] = {"resumos/semanaResumo.txt", "resumos/dumontResumo.txt", "resumos/olimpiadasResumo.txt", "resumos/tecnologiaResumo.txt"};

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
    
    printf("\n\nGostaria de participar de uma pesquisa de satisfacao referente a sua visita? [S / N]: ");
    scanf("%s", &decisaoPesquisa);

    if(stricmp(decisaoPesquisa, "S") == 0){
        exibirQuestionario(); 
        sleep(2);
        system("cls ||clear");
    }else
    {
        printf("\nObrigada por visitar! Volte sempre :)");
        sleep(2);
        system("cls ||clear");
        exibirResumoObra(obra);
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
    
    fclose(arquivo);
}
