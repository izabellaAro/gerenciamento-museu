#include "exposicao.h"
#include <stdio.h>
#include <stdlib.h>

void exibirResumoObra(int obra){
    system("cls ||clear");

    switch (obra)
    {
        case 1:
            exibeResumoObra("resumos/semanaResumo.txt");
            break;
        case 2:
            exibeResumoObra("resumos/dumontResumo.txt");
            break;
        case 3:
            exibeResumoObra("resumos/olimpiadasResumo.txt");
            break;
        case 4:
            exibeResumoObra("resumos/tecnologiaResumo.txt");
            break;
        default:
            break;
    }
}

void exibeResumoObra(char* nomeArquivo){
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