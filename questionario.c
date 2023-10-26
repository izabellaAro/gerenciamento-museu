#include "questionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <TIME.H>


struct Questao {
    char* pergunta;
    char* opcoes;
    int resposta;
};

struct Questao questoes[5];

void preencherQuestoes()
{
    questoes[0].pergunta = "Qual foi o nível de satisfação geral com a sua visita?";
    questoes[0].opcoes = "\n(0) Muito insatisfeito\n(1) Insatisfeito\n(2) Neutro\n(3) Satisfeito\n(4) Muito satisfeito\n(5) Extremamente satisfeito\n";

    questoes[1].pergunta = "\nComo você avaliaria a qualidade do atendimento ao cliente?";
    questoes[1].opcoes = "\n(0) Muito ruim\n(1) Ruim\n(2) Aceitável\n(3) Bom\n(4) Muito bom\n(5) Excelente\n";

    questoes[2].pergunta = "\nA limpeza e organização do local atenderam às suas expectativas?";
    questoes[2].opcoes = "\n(0) Muito abaixo do esperado\n(1) Abaixo do esperado\n(2) Satisfatório\n(3) Acima do esperado\n(4) Muito acima do esperado\n(5) Excepcional\n";

    questoes[3].pergunta = "\nComo você classificaria a variedade de obras expostas?";
    questoes[3].opcoes = "\n(0) Muito limitada\n(1) Limitada\n(2) Suficiente\n(3) Boa\n(4) Muito boa\n(5) Excelente\n";

    questoes[4].pergunta = "\nVocê consideraria retornar a este local ou recomendaria a outras pessoas?";
    questoes[4].opcoes = "\n(0) Definitivamente não\n(1) Provavelmente não\n(2) Talvez\n(3) Provavelmente sim\n(4) Definitivamente sim\n(5) Com certeza\n";

}

void exibirQuestionario()
{
    system("cls ||clear");
    
    preencherQuestoes();
    
    int respostaPesquisa[5];

    printf("\nAvalie de 0 a 5:\n\n");

	int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s %s", questoes[i].pergunta, questoes[i].opcoes);
        scanf("%d", &respostaPesquisa[i]);
    }

    printf("\nObrigada por participar! Volte sempre.");
    sleep(2);
    
    int retorno;
    FILE *pesquisaSat;
    pesquisaSat = fopen("respostasQuestionario.txt", "a");

    retorno = fwrite(&respostaPesquisa, sizeof(respostaPesquisa), 1, pesquisaSat);

    fclose(pesquisaSat);
}

void gerarRelatorio()
{
    int respostas[5][5] = {0};

    obterRespostas(respostas);
    preencherQuestoes();
    
    FILE *arquivo;

    arquivo = fopen("relatorio.csv", "w+");
    fprintf(arquivo,"Pergunta, Opção 1, Opção 2, Opção 3, Opção 4, Opção 5\n");

    int i;
    for (i = 0; i < 5; i++)
    {
        fprintf(arquivo,"%s, %d, %d, %d, %d, %d", questoes[i].pergunta, respostas[i][0], respostas[i][1], respostas[i][2], respostas[i][3], respostas[i][4]);
    }

    printf("Relatorio gerado com sucesso!");

    fclose(arquivo);
}


void obterRespostas(int respostas[5][5])
{
    FILE *arq = fopen("respostasQuestionario.txt", "r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }

    int respostaPesquisa[5];
    int valorResposta = 0;

    while (fread(&respostaPesquisa, sizeof(respostaPesquisa), 1, arq))
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            valorResposta = respostaPesquisa[i];
            respostas[i][valorResposta - 1]++;
        }
    }

    fclose(arq);
}
