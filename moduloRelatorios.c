#include <stdio.h>
#include <stdlib.h>
#include "moduloValidacoes.h"

char menuRelatorios(void){
    char opcao;
    int validaOp;
    int validaOpM;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            RELATÓRIOS:                                            ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Relatório: Produtos                                ///\n");
    printf("///            2 - Relatório: Compras                                 ///\n");
    printf("///            3 - Relatório: Consumo                                 ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 3); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

char menuRelatorioProdutos(void){

    char opcao;
    int validaOp;
    int validaOpM;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            RELATÓRIOS - PRODUTOS:                                 ///\n");    
    printf("///                                                                   ///\n");
    printf("///            1 - Itens vencidos                                     ///\n");
    printf("///            2 - Itens a vencer                                     ///\n");
    printf("///            3 - Itens abertos                                      ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 3); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

void itensVencidos(void){

    char codBarras[14] = "789859844612";
    char nomeItem[51] = "Arroz Branco";
    char dataValidade[11] = "19/03/2021";
    char local[10] = "Armário";
    char status[10] = "Fechado";
    int quant = 5;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = RELATÓRIO - PRODUTOS VENCIDOS = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///           Total de produtos vencidos: 2                           ///\n");
    printf("///           _____________________________________________           ///\n");
    
    for(int i=0; i < 2; i++){
        printf("///                                                                   ///\n");
        printf("///              Código de Barras : %s \n", codBarras);
        printf("///              Descrição        : %s \n", nomeItem);
        printf("///              Data de Validade : %s \n", dataValidade);
        printf("///              Local            : %s \n", local);
        printf("///              Status           : %s \n", status);
        printf("///              Quantidade       : %d \n", quant);
        printf("///           _____________________________________________           ///\n");
    }
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

void itensParaVencer(void){

    char codBarras[14] = "789859844612";
    char nomeItem[51] = "Arroz Branco";
    char dataValidade[11] = "28/03/2021";
    char local[10] = "Armário";
    char status[10] = "Fechado";
    int quant = 5;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = RELATÓRIO - PRODUTOS À VENCER = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///           Total de produtos à vencer: 2                           ///\n");
    printf("///           Data: 23/03/2021                                        ///\n");
    printf("///           _____________________________________________           ///\n");
    
    for(int i=0; i < 2; i++){
        printf("///                                                                   ///\n");
        printf("///              Código de Barras : %s \n", codBarras);
        printf("///              Descrição        : %s \n", nomeItem);
        printf("///              Data de Validade : %s \n", dataValidade);
        printf("///              Local            : %s \n", local);
        printf("///              Status           : %s \n", status);
        printf("///              Quantidade       : %d \n", quant);
        printf("///           _____________________________________________           ///\n");
    }
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void itensAbertos(void){
    limpaTela();
    printf("Em desenvolvimento\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

char menuRelatorioCompras(void){
    char opcao;
    int validaOp;
    int validaOpM;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            RELATÓRIOS - COMPRAS:                                  ///\n");    
    printf("///                                                                   ///\n");
    printf("///            1 - Compras Diárias                                    ///\n");
    printf("///            2 - Compras Mensais                                    ///\n");
    printf("///            3 - Compras Anuais                                     ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    
    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 3); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

void comprasDiarias(void){

    char dataCompra[11] = "23/03/2021";
    char horaCompra[6] = "08:30";
    char nomeItem[51] = "Arroz Branco";
    char valorCompra[20] = "100,00";
    int quant = 5;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = RELATÓRIO - COMPRAS DIÁRIAS = = = =             ///\n");
    printf("///                                                                   ///\n");
    printf("///           Total gasto com compras hoje: $200                      ///\n");
    printf("///           Total de compras realizadas hoje: 2                     ///\n");
    printf("///           Data: 23/03/2021                                        ///\n");
    printf("///           _____________________________________________           ///\n");
    
    for(int i=0; i < 2; i++){
        printf("///                                                                   ///\n");
        printf("///              Data Compra: %s\n", dataCompra);
        printf("///              Horário Compra: %s\n\n", horaCompra);
        printf("///              Lista de Itens:\n\n");

        for (int i = 0; i < 5; i++){
            printf("///              %s, %d unidade(s) \n", nomeItem, quant);
        }

        printf("///              Valor Compra: $ %s\n", valorCompra);
        printf("///           _____________________________________________           ///\n");
    }

    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void comprasMensais(void){
    limpaTela();
    printf("Em desenvolvimento\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void comprasAnuais(void){
    limpaTela();
    printf("Em desenvolvimento\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

char menuRelatorioConsumo(void){
    char opcao;
    int validaOp;
    int validaOpM;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            RELATÓRIOS - CONSUMO:                                  ///\n");    
    printf("///                                                                   ///\n");
    printf("///            1 - Consumo Diário                                     ///\n");
    printf("///            2 - Consumo Mensal                                     ///\n");
    printf("///            3 - Consumo Anual                                      ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 3); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

void consumoDiario(void){
    limpaTela();
    printf("Em desenvolvimento\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void consumoMensal(void){
    limpaTela();
    printf("Em desenvolvimento\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void consumoAnual(void){
    limpaTela();
    printf("Em desenvolvimento\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

