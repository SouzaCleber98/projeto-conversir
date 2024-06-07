#include "function.h"

// Definindo cores para estilização
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BRED "\x1b[91m"
#define BGREEN "\x1b[92m"
#define BYELLOW "\x1b[93m"
#define BBLUE "\x1b[94m"
#define BMAGENTA "\x1b[95m"
#define BCYAN "\x1b[96m"
#define BWHITE "\x1b[97m"
#define BG_RED "\x1b[41m"
#define BG_GREEN "\x1b[42m"
#define BG_YELLOW "\x1b[43m"
#define BG_BLUE "\x1b[44m"
#define BG_MAGENTA "\x1b[45m"
#define BG_CYAN "\x1b[46m"
#define BG_WHITE "\x1b[47m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define ITALIC "\x1b[3m"
#define UNDERLINE "\x1b[4m"

// Protótipos
int menu();

int main(void) {
    // Variáveis
    int aux = 0;
    double aux2 = 0;
    int opcao = OP_NAO_SELECIONADA;
    struct unidade novo;
    const char *nomeArquivo = "historico.txt";

    // Início do menu
    while(opcao != OP_SAIR) { // Até o usuário querer sair
        opcao = menu(); // Exibe o menu e captura a opção do usuário

        switch (opcao) {
            case OP_TEMPERATURA:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\tTemperatura" RESET "                 ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
              //Deixar o aviso ou não?
                printf(RED "\t\t\t\t!Atenção!\n");
                printf("\tNa escala Kelvin, teoricamente não existem  \n");
                printf("\tvalores negativos, entretanto a fins de \n");
                printf("\tcuriosidade, as conversões para esses valores\n");
                printf("\tainda serão feitas." RESET "\n\n");
              //^^^^^^
                printf("\t\t1 - Celsius para Fahrenheits\n");
                printf("\t\t2 - Celsius para Kelvin\n");
                printf("\t\t3 - Fahrenheits para Celsius\n");
                printf("\t\t4 - Fahrenheits para Kelvin\n");
                printf("\t\t5 - Kelvin para Celsius\n");
                printf("\t\t6 - Kelvin para Fahrenheits\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de temperatura se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf(BG_RED "\t\tErro na conversão!" RESET "\n");
                    break;
                }
                break;

            case OP_MASSA:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\t\tMassa" RESET "                   ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf("\t\t1 - Libras para quilogramas\n");
                printf("\t\t2 - Quilogramas para libras\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de massa se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                menuConversao(novo); // Realiza a conversão
                break;

            case OP_COMPRIMENTO:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\t\tDistâncias" RESET "              ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf("\t\t1 - Centímetros para Metros\n");
                printf("\t\t2 - Centímetros para Quilômetros\n");
                printf("\t\t3 - Metros para Centímetros\n");
                printf("\t\t4 - Metros para Quilômetros\n");
                printf("\t\t5 - Quilômetros para Centímetros\n");
                printf("\t\t6 - Quilômetros para Metros\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de comprimento se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf(BG_RED "\t\tErro na conversão!" RESET "\n");
                }
                break;

            case OP_TEMPO:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\t\tTempo" RESET "                   ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf("\t\t1 - Dias para Horas\n");
                printf("\t\t2 - Dias para Minutos\n");
                printf("\t\t3 - Horas para Dias\n");
                printf("\t\t4 - Horas para Minutos\n");
                printf("\t\t5 - Minutos para Dias\n");
                printf("\t\t6 - Minutos para Horas\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de tempo se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf(BG_RED "\t\tErro na conversão!" RESET "\n");
                }
                break;

            case OP_RELATORIO:
                mostrarHistorico(nomeArquivo);
                break;

            case OP_SAIR:
                break; // Sai do programa

            default:
                printf("\n" BG_RED "\t\t\tOpção inválida!" RESET "\n\n");
        }
    }

    return EXIT_SUCCESS;
}

// Menu de opções
int menu() {
    int op = OP_NAO_SELECIONADA;

  printf("\n");
  printf(BCYAN BOLD"\t\t===========================\n");
  printf("\t\t||" BWHITE BOLD "Bem vindo ao ConverSir!" RESET BCYAN BOLD "||\n");
  printf("\t\t===========================\n\n" RESET);
  printf(BCYAN BOLD "==============================================\n");
  printf("||" BWHITE BOLD "Converta grandezas de maneira simples." RESET BCYAN BOLD "\t||\n");
  printf("||" BWHITE "Selecione a grandeza que deseja converter:" RESET BCYAN BOLD "||\n");
  printf("==============================================" RESET "\n\n");
  printf(BG_BLUE "\t\t\t\t*** Menu ***" RESET "\n\n");
  printf("\t\t\t %d - Temperatura\n", OP_TEMPERATURA);
  printf("\t\t\t %d - Massa\n", OP_MASSA);
  printf("\t\t\t %d - Distância\n ", OP_COMPRIMENTO);
  printf("\t\t\t %d - Tempo\n", OP_TEMPO);
  printf("\t\t\t %d - Gerar Relatório\n", OP_RELATORIO);
  printf("\t\t\t %d - Sair\n\n", OP_SAIR);
  printf(BG_BLUE "\t\t\tDigite sua opção:" RESET " ");
    scanf("%d", &op); // Captura a opção do menu principal
    scanf("%*c"); // Limpa o buffer

    return op; // Retorna a opção selecionada
}