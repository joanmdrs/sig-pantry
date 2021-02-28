///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///           Projeto Sistema de Controle de Despensa Doméstica             ///
///              Developed by  @allangbr @joanmdrs - Jan, 2021              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "moduloPrincipal.h"
#include "moduloProdutos.h"
#include "moduloSobre.h"

char menuCompras(void);
void telaCadastrarCompra(void);
void telaPesquisarCompra(void);
void telaExcluirCompra(void);
void telaAlterarCompra(void);
void telaListarCompras(void);

char menuConsumo(void);
void telaCadastrarConsumo(void);
void telaPesquisarConsumo(void);
void telaExcluirConsumo(void);
void telaAlterarConsumo(void);
void telaListarConsumos(void);


int main(void) {

    char opcao1, opcao2, opcao3, opcao4;

    do{
        opcao1 = menuPrincipal();

        switch (opcao1){
            case '1':
                do{                   
                    opcao2 = menuProdutos();

                    switch (opcao2){
                        case '1':
                            telaCadastrarProduto();
                            break;
                        case '2':
                            telaPesquisarProduto();
                            break;
                        case '3':
                            telaExcluirProduto();
                            break;
                        case '4':
                            telaAlterarProduto();
                            break;
                        case '5':
                            telaListarProdutos();
                            break;
                    }

                }while(opcao2 != '0');
                break;

            case '2':
                do{
                    opcao3 = menuCompras();

                    switch (opcao3){
                        case '1':
                            telaCadastrarCompra();
                            break;
                        case '2':
                            telaPesquisarCompra();
                            break;
                        case '3':
                            telaExcluirCompra();
                            break;
                        case '4':
                            telaAlterarCompra();
                            break;
                        case '5':
                            telaListarCompras();
                            break;
                    }

                } while (opcao3 != '0');
                break;

            case '3':
                do{
                    opcao4 = menuConsumo();

                    switch (opcao4){
                        case '1':
                            telaCadastrarConsumo();
                            break;
                        case '2':
                            telaPesquisarConsumo();
                            break;
                        case '3':
                            telaExcluirConsumo();
                            break;
                        case '4':
                            telaAlterarConsumo();
                            break;
                        case '5':
                            telaListarConsumos();
                            break;
                    }

                } while(opcao4 != '0');
                break;
                
            case '4':
                menuSobre();
                break;

        } 

    }while(opcao1 != '0');

    return 0;

}


char menuCompras(void){
    char opcao;

    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRAS:                                               ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Cadastrar compra                                   ///\n");
    printf("///            2 - Pesquisar compra                                   ///\n");
    printf("///            3 - Excluir compra                                     ///\n");
    printf("///            4 - Alterar compra                                     ///\n");
    printf("///            5 - Listar compras                                     ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("Informe a sua opção : ");
    scanf("%c", &opcao);
    getchar();
	return opcao;


}

void telaCadastrarCompra(void){

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    int quant;
    float valorItem;
    float valorCompra;
    
/// Pegando a data do sistema -----------------------------------------------------

    time_t timer;
    struct tm *horarioLocal;

    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    int dia = horarioLocal->tm_mday;
    int mes = horarioLocal->tm_mon + 1;
    int ano = horarioLocal->tm_year + 1900;

    int hora = horarioLocal->tm_hour;
    int min  = horarioLocal->tm_min;
    int sec  = horarioLocal->tm_sec;

    int vetor[6]= {dia,mes,ano,hora,min,sec};

/// --------------------------------------------------------------------------------

    system("clear");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO CADASTRAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("///            - Descrição do Item: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
    getchar();
    printf("///            - Data Val. (dd/mm/aaaa): ");
    scanf("%[0-9/]", dataValidade);
    getchar();
    printf("///            - Quantidade: ");
    scanf("%d", &quant);
    getchar();
    printf("///            - Valor do Item: R$ "); 
    scanf("%f", &valorItem);
    getchar();
    
    valorCompra += quant * valorItem;
    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Compra cadastrada com sucesso !                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///              Código de Barras: %s \n", codBarras);
    printf("///             Descrição do Item: %s \n", nomeItem);
    printf("///              Data de Validade: %s \n", dataValidade);
    printf("///                    Quantidade: %d \n", quant);
    printf("///                 Valor do Item: R$ %.2f \n", valorItem);
    printf("///               Valor da compra: R$ %.2f \n", valorCompra);
    printf("///                          Data: %d/%d/%d \n",vetor[0],vetor[1],vetor[2]);
    printf("///                       Horário: %d:%d:%d \n",vetor[3],vetor[4],vetor[5]);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 >>> Tecle <ENTER> para continuar...               ///\n");
    getchar();

}

void telaPesquisarCompra(void){

    char data[11];
    char horario[9];

    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO PESQUISAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%s", data);
    getchar();
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALORES DE ENTRADA:                        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário.                                 ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaExcluirCompra(void){

    char data[11];
    char horario[9];
    char resposta;

    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            = = = = =  MÓDULO EXCLUIR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%s", data);
    getchar();
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALORES DE ENTRADA:                        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Itens: Aqui vai mostrar todos os itens comprados     ///\n");
    printf("///              naquele dia e horário e suas quantidades.            ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/N): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &resposta);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALOR DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %c \n", resposta);
    printf("/// _________________________________________________________________ ///\n");

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///            Compra excluída com sucesso!                           ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(resposta == 'N' || resposta == 'n'){
        printf("///                                                                   ///\n");
        printf("///            Operação cancelada!                                    ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else{
        printf("///                                                                   ///\n");
        printf("///            Você informou um valor inválido!                       ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}

void telaAlterarCompra(void){

    char data[11];
    char horario[9];
    char resposta;
    char decisao;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    int quant;
    float valorItem;
    float valorCompra;

    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            = = = = =  MÓDULO ALTERAR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%s", data);
    getchar();
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                      VALORES DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n"); ///Possível resultado
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário.                                 ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");   
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n"); ///Outro possível resultado   
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          - Deseja alterar todos os items da compra (S/N) ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &resposta);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALOR DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %c \n", resposta);
    printf("/// _________________________________________________________________ ///\n");

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///           NOVA LISTA DE ITENS:                                    ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Código de Barras: ");
        scanf("%[0-9]", codBarras);
        getchar();
        printf("///            - Descrição do Item: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
        getchar();
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[0-9/]", dataValidade);
        getchar();
        printf("///            - Quantidade: ");
        scanf("%d", &quant);
        getchar();
        printf("///            - Valor do Item: R$ "); 
        scanf("%f", &valorItem);
        getchar();
        
        valorCompra += quant * valorItem;
        
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///             Descrição do Item: %s \n", nomeItem);
        printf("///              Data de Validade: %s \n", dataValidade);
        printf("///                    Quantidade: %d \n", quant);
        printf("///                 Valor do Item: R$ %.2f \n", valorItem);
        printf("///               Valor da compra: R$ %.2f \n", valorCompra);
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &decisao);
        getchar();

        if (decisao == 'S' || decisao == 's'){
            printf("///                                                                   ///\n");
            printf("///            Compra alterada com sucesso!                           ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(decisao == 'N' || decisao == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operação cancelada!                                    ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else{
            printf("///                                                                   ///\n");
            printf("///            Você informou um valor inválido!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }

    }else if(resposta == 'N' || resposta == 'n'){
        printf("///                                                                   ///\n");
        printf("///           INFORME O ITEM A ALTERAR:                               ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Código de Barras: ");
        scanf("%[0-9]", codBarras);
        getchar();
        printf("///            - Data de Validade (dd/mm/aaaa): ");
        scanf("%[0-9/]", dataValidade);
        getchar();
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                     VALORES DE ENTRADA:                           ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///              Data de Validade: %s \n", dataValidade); 
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM ENCONTRADO !                                      ///\n");
        printf("///                                                                   ///\n");
        printf("///             - Código de Barras:                                   ///\n");
        printf("///             - Descrição do Item:                                  ///\n");
        printf("///             - Data de Validade:                                   ///\n"); 
        printf("///             - Quantidade:                                         ///\n"); 
        printf("///             - Valor do Item:                                      ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Digite 'a' para alterar a descrição                  ///\n");
        printf("///            - Digite 'b' para alterar a validade                   ///\n");
        printf("///            - Digite 'c' para alterar o quantidade                 ///\n");
        printf("///            - Digite 'd' para alterar o valor                      ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Informe a sua opção: "); 
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &respostaLetras);
        getchar();
        if (respostaLetras == 'A' || respostaLetras == 'a'){
            printf("///                                                                   ///\n");
            printf("///            - a) Nova Descrição: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
            getchar();
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                          Nome: %s \n", nomeItem);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O nome da compra foi alterado!                         ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }else if(resposta == 'B' || respostaLetras == 'b'){
            printf("///                                                                   ///\n");
            printf("///            - b) Nova Data Val. (dd/mm/aaaa): ");
            scanf("%[0-9/]", dataValidade);
            getchar();
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///              Data de Validade: %s \n", dataValidade);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A data de validade da compra foi alterada!             ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'C' || respostaLetras == 'c'){   
            printf("///                                                                   ///\n");
            printf("///            - c) Nova Quantidade: ");
            scanf("%d", &quant);
            getchar();  
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                    Quantidade: %d \n", quant);       
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A quantidade da compra foi alterada!                   ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'D' || respostaLetras == 'd'){
            printf("///                                                                   ///\n");
            printf("///            - d) Novo Valor: ");
            scanf("%f", &valorItem);
            getchar();  
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                      Valor: %.2f \n", valorItem);       
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O valor foi alterado!                                  ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }else{
            printf("///                                                                   ///\n");
            printf("///            Você informou um valor inválido!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }

    }else{
        printf("///                                                                   ///\n");
        printf("///            Você informou um valor inválido!                       ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

void telaListarCompras(void){
    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            MÓDULO LISTAR COMPRAS:                                 ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário, suas quantidades e valores      ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n"); 
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

char menuConsumo(void){
    char opcao;
    
    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMOS:                                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Cadastrar consumo                                  ///\n");
    printf("///            2 - Pesquisar consumo                                  ///\n");
    printf("///            3 - Excluir consumo                                    ///\n");
    printf("///            4 - Alterar consumo                                    ///\n");
    printf("///            5 - Listar consumos                                    ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("Informe a sua opção : ");
    scanf("%c", &opcao);
    getchar();
	return opcao;

}

void telaCadastrarConsumo(void){
    char codBarras[14];
    char dataValidade[11];
    char item[51];
    int quant;
    
/// Pegando a data do sistema -----------------------------------------------------

    time_t timer;
    struct tm *horarioLocal;

    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    int dia = horarioLocal->tm_mday;
    int mes = horarioLocal->tm_mon + 1;
    int ano = horarioLocal->tm_year + 1900;

    int hora = horarioLocal->tm_hour;
    int min  = horarioLocal->tm_min;
    int sec  = horarioLocal->tm_sec;

    int vetor[6]= {dia,mes,ano,hora,min,sec};

/// --------------------------------------------------------------------------------

    system("clear");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO CADASTRAR CONSUMO: = = = = =          ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("///            - Data Val. (dd/mm/aaa): ");
    scanf("%[0-9/]", dataValidade);
    getchar();
    printf("///            - Descrição do Item: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", item);
    getchar();
    printf("///            - Quantidade: ");
    scanf("%d", &quant);
    getchar();
    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Consumo cadastrado com sucesso !                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Código de Barras: %s \n", codBarras);
    printf("///             Data de Validade: %s \n", dataValidade);
    printf("///            Descrição do Item: %s \n", item);
    printf("///                   Quantidade: %d \n", quant);
    printf("///                         Data: %d/%d/%d \n",vetor[0],vetor[1],vetor[2]);
    printf("///                      Horário: %d/%d/%d \n",vetor[3],vetor[4],vetor[5]);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                >>> Tecle <ENTER> para continuar...                ///\n");
    getchar();


}

void telaPesquisarConsumo(void){

    char data[11];
    char horario[9];

    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO PESQUISAR CONSUMO: = = = = =          ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data do consumo (dd/mm/aaa): ");
    scanf("%[0-9/]", data);
    getchar();
    printf("///            - Horário do consumo (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALORES DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data do consumo: %s \n", data);
    printf("///             Horário do consumo: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele dia e horário e suas quantidades               ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário da consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaExcluirConsumo(void){

    char data[11];
    char horario[9];
    char resposta;
    
    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            = = = = =  MÓDULO EXCLUIR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data do consumo (dd/mm/aaa): ");
    scanf("%[0-9/]", data);
    getchar();
    printf("///            - Horário do consumo (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALORES DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data do consumo: %s \n", data);
    printf("///             Horário do consumo: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Itens: Aqui vai mostrar todos os itens consumidos    ///\n");
    printf("///              naquele dia e horário, e suas quantidades.           ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/N): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &resposta);
    getchar();

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///            Consumo excluído com sucesso!                          ///\n"); 
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t              >>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if (resposta == 'N' || resposta == 'n'){
        printf("///                                                                   ///\n");
        printf("///            Operação cancelada!                                    ///\n"); 
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else{
        printf("///                                                                   ///\n");
        printf("///            Você informou um valor inválido!                       ///\n"); 
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }

}

void telaAlterarConsumo(void){
    char data[11];
    char horario[9];
    char resposta;
    char decisao;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    int quant;

    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          = = = = = = MÓDULO ALTERAR CONSUMO = = = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data do consumo (dd/mm/aaa): ");
    scanf("%s", data);
    getchar();
    printf("///            - Horário do consumo (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                      VALORES DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data do consumo: %s \n", data);
    printf("///             Horário do consumo: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n"); ///Possível resultado
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele dia e horário.                                 ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo                                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n"); ///Outro possível resultado   
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          - Deseja alterar todos os items do consumo (S/N) ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &resposta);
    getchar();
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALOR DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %c \n", resposta);
    printf("/// _________________________________________________________________ ///\n");

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///           NOVA LISTA DE ITENS:                                    ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Código de Barras: ");
        scanf("%[0-9]", codBarras);
        getchar();
        printf("///            - Descrição do Item: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
        getchar();
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[0-9/]", dataValidade);
        getchar();
        printf("///            - Quantidade: ");
        scanf("%d", &quant);
        getchar();
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///             Descrição do Item: %s \n", nomeItem);
        printf("///              Data de Validade: %s \n", dataValidade);
        printf("///                    Quantidade: %d \n", quant);
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &decisao);
        getchar();
        if (decisao == 'S' || decisao == 's'){
            printf("///                                                                   ///\n");
            printf("///            Consumo alterado com sucesso!                           ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(decisao == 'N' || decisao == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operação cancelada!                                    ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else{
            printf("///                                                                   ///\n");
            printf("///            Você informou um valor inválido!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }

    }else if(resposta == 'N' || resposta == 'n'){
        printf("///                                                                   ///\n");
        printf("///           INFORME O ITEM A ALTERAR:                               ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Código de Barras: ");
        scanf("%[0-9]", codBarras);
        getchar();
        printf("///            - Data de Validade (dd/mm/aaaa): ");
        scanf("%[0-9/]", dataValidade);
        getchar();
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                     VALORES DE ENTRADA:                           ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///              Data de Validade: %s \n", dataValidade); 
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM ENCONTRADO !                                      ///\n");
        printf("///                                                                   ///\n");
        printf("///             - Código de Barras:                                   ///\n");
        printf("///             - Descrição do Item:                                  ///\n");
        printf("///             - Data de Validade:                                   ///\n"); 
        printf("///             - Quantidade:                                         ///\n"); 
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Digite 'a' para alterar a descrição                  ///\n");
        printf("///            - Digite 'b' para alterar a validade                   ///\n");
        printf("///            - Digite 'c' para alterar o quantidade                 ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Informe a sua opção: "); 
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &respostaLetras);
        getchar();
        if (respostaLetras == 'A' || respostaLetras == 'a'){
            printf("///                                                                   ///\n");
            printf("///            - a) Nova Descrição: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
            getchar();
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                          Nome: %s \n", nomeItem);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O nome do consumo foi alterado!                        ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }else if(resposta == 'B' || respostaLetras == 'b'){
            printf("///                                                                   ///\n");
            printf("///            - b) Nova Data Val. (dd/mm/aaaa): ");
            scanf("%[0-9/]", dataValidade);
            getchar();
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///              Data de Validade: %s \n", dataValidade);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A data de validade do consumo foi alterada!            ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'C' || respostaLetras == 'c'){   
            printf("///                                                                   ///\n");
            printf("///            - c) Nova Quantidade: ");
            scanf("%d", &quant);
            getchar();  
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                    Quantidade: %d \n", quant);       
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A quantidade do consumo foi alterada!                  ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else{
            printf("///                                                                   ///\n");
            printf("///            Você informou um valor inválido!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }
    }
}

void telaListarConsumos(){
    system("clear");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            MÓDULO LISTAR CONSUMOS:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele por dia e horário, e suas informações          ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    /* No módulo listar consumos, serão exibidos todos os items consumidos, separados por 
    data e horário de cadastro. 
    */
}

