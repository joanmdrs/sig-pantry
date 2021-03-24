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
    printf("              Total de produtos vencidos: 2                              \n");
    printf("              _____________________________________________              \n");
    
    for(int i=0; i < 2; i++){
        printf("                                                                         \n");
        printf("                 Código de Barras : %s \n", codBarras);
        printf("                 Descrição        : %s \n", nomeItem);
        printf("                 Data de Validade : %s \n", dataValidade);
        printf("                 Local            : %s \n", local);
        printf("                 Status           : %s \n", status);
        printf("                 Quantidade       : %d \n", quant);
        printf("              _____________________________________________              \n");
    }
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
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
    printf("              Total de produtos à vencer: 2                              \n");
    printf("              Data: 23/03/2021                                           \n");
    printf("              _____________________________________________              \n");
    
    for(int i=0; i < 2; i++){
        printf("                                                                         \n");
        printf("                 Código de Barras : %s \n", codBarras);
        printf("                 Descrição        : %s \n", nomeItem);
        printf("                 Data de Validade : %s \n", dataValidade);
        printf("                 Local            : %s \n", local);
        printf("                 Status           : %s \n", status);
        printf("                 Quantidade       : %d \n", quant);
        printf("              _____________________________________________              \n");
    }
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void itensAbertos(void){
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
    printf("///           = = = = RELATÓRIO - PRODUTOS ABERTOS = = = =            ///\n");
    printf("///                                                                   ///\n");
    printf("              Total de produtos abertos: 2                               \n");
    printf("              _____________________________________________              \n");
    
    for(int i=0; i < 2; i++){
        printf("                                                                         \n");
        printf("                 Código de Barras : %s \n", codBarras);
        printf("                 Descrição        : %s \n", nomeItem);
        printf("                 Data de Validade : %s \n", dataValidade);
        printf("                 Local            : %s \n", local);
        printf("                 Status           : %s \n", status);
        printf("                 Quantidade       : %d \n", quant);
        printf("              _____________________________________________              \n");
    }
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
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
    printf("              Total gasto com compras hoje: $200                         \n");
    printf("              Total de compras realizadas hoje: 2                        \n");
    printf("              Data: 23/03/2021                                           \n");
    printf("              _____________________________________________              \n");
    
    for(int i=0; i < 2; i++){
        printf("                                                                         \n");
        printf("                 Data Compra: %s\n", dataCompra);
        printf("                 Horário Compra: %s\n\n", horaCompra);
        printf("                 Lista de Itens:\n\n");

        for (int i = 0; i < 5; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem, quant);
        }

        printf("                 Valor Compra: $ %s\n", valorCompra);
        printf("              _____________________________________________              \n");
    }
    
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void comprasMensais(void){
    char dataCompra1[11] = "03/03/2021";
    char horaCompra1[6] = "08:30";
    char nomeItem1[51] = "Arroz Branco";
    char valorCompra1[20] = "200,00";
    int quant1 = 5;

    char dataCompra2[11] = "12/03/2021";
    char horaCompra2[6] = "10:33";
    char nomeItem2[51] = "Macarrão";
    char valorCompra2[20] = "250,00";
    int quant2 = 8;

    char dataCompra3[11] = "25/03/2021";
    char horaCompra3[6] = "14:54";
    char nomeItem3[51] = "Feijão";
    char valorCompra3[20] = "300,00";
    int quant3 = 2;

    char dataCompra4[11] = "29/03/2021";
    char horaCompra4[6] = "11:02";
    char nomeItem4[51] = "Macarrão";
    char valorCompra4[20] = "250,00";
    int quant4 = 8;

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
    printf("///           = = = = RELATÓRIO - COMPRAS MENSAIS = = = =             ///\n");
    printf("///                                                                   ///\n");
    printf("              Total gasto com compras esse mês: $1000                    \n");
    printf("              Total de compras realizadas esse mês: 4                    \n");
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Compra: %s\n", dataCompra1);
    printf("                 Horário Compra: %s\n\n", horaCompra1);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 5; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem1, quant1);
    }
    printf("                 Valor Compra: $ %s\n", valorCompra1);
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Compra: %s\n", dataCompra2);
    printf("                 Horário Compra: %s\n\n", horaCompra2);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 8; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem2, quant2);
    }
    printf("                 Valor Compra: $ %s\n", valorCompra2);
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Compra: %s\n", dataCompra3);
    printf("                 Horário Compra: %s\n\n", horaCompra3);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 2; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem3, quant3);
    }
    printf("                 Valor Compra: $ %s\n", valorCompra3);
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Compra: %s\n", dataCompra4);
    printf("                 Horário Compra: %s\n\n", horaCompra4);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 8; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem4, quant4);
    }
    printf("                 Valor Compra: $ %s\n", valorCompra4);
    printf("              _____________________________________________              \n");
    
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void comprasAnuais(void){
    char mes[2];
    int m;

    char dataCompra1[11] = "03/02/2021";
    char horaCompra1[6] = "08:30";
    char nomeItem1[51] = "Arroz Branco";
    char valorCompra1[20] = "200,00";
    int quant1 = 5;

    char dataCompra2[11] = "12/05/2021";
    char horaCompra2[6] = "10:33";
    char nomeItem2[51] = "Macarrão";
    char valorCompra2[20] = "250,00";
    int quant2 = 8;

    char dataCompra3[11] = "25/08/2021";
    char horaCompra3[6] = "14:54";
    char nomeItem3[51] = "Feijão";
    char valorCompra3[20] = "300,00";
    int quant3 = 2;

    char dataCompra4[11] = "29/12/2021";
    char horaCompra4[6] = "11:02";
    char nomeItem4[51] = "Macarrão";
    char valorCompra4[20] = "250,00";
    int quant4 = 8;

    int validaDig;

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
    printf("///           = = = = RELATÓRIO - COMPRAS ANUAIS = = = =              ///\n");
    printf("///                                                                   ///\n");
    printf("              Total gasto com compras esse ano: $1000                    \n");
    printf("              Total de compras realizadas esse ano: 4                    \n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("Informe o mês que deseja ver o relatório (1/12): ");
        scanf("%[^\n]", mes);
        getchar();
        validaDig = testeDigitosNumericos(mes);
        m = converteCharParaInt(mes);

        if(validaDig || (m < 1 || m > 12)){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(validaDig || (m < 1 || m > 12));

    if (m == 1){
        printf("              _____________________________________________              \n");
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - JANEIRO = = = =                     ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");

    } else if (m == 2){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - FEVEREIRO = = = =                   ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Compra: %s\n", dataCompra1);
        printf("                 Horário Compra: %s\n\n", horaCompra1);
        printf("                 Lista de Itens:\n\n");

        for (int i = 0; i < 5; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem1, quant1);
        }

        printf("                 Valor Compra: $ %s\n", valorCompra1);
        printf("              _____________________________________________              \n");
        
    } else if (m == 3){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - MARÇO = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 4){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - ABRIL = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 5){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - MAIO = = = =                        ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Compra: %s\n", dataCompra2);
        printf("                 Horário Compra: %s\n\n", horaCompra2);
        printf("                 Lista de Itens:\n\n");
        for (int i = 0; i < 8; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem2, quant2);
        }
        printf("                 Valor Compra: $ %s\n", valorCompra2);
        printf("              _____________________________________________              \n");
        
    } else if (m == 6){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - JUNHO = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 7){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - JULHO = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 8){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - AGOSTO = = = =                      ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Compra: %s\n", dataCompra3);
        printf("                 Horário Compra: %s\n\n", horaCompra3);
        printf("                 Lista de Itens:\n\n");
        for (int i = 0; i < 2; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem3, quant3);
        }
        printf("                 Valor Compra: $ %s\n", valorCompra3);
        printf("              _____________________________________________              \n");
        
    } else if (m == 9){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - SETEMBRO = = = =                    ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 10){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - OUTUBRO = = = =                     ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 11){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - NOVEMBRO = = = =                    ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrada nenhuma compra nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 12){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - DEZEMBRO = = = =                    ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Compra: %s\n", dataCompra4);
        printf("                 Horário Compra: %s\n\n", horaCompra4);
        printf("                 Lista de Itens:\n\n");
        for (int i = 0; i < 8; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem4, quant4);
        }
        printf("                 Valor Compra: $ %s\n", valorCompra4);
        printf("              _____________________________________________              \n");

    }

    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
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
    char dataConsumo[11] = "23/03/2021";
    char horaConsumo[6] = "08:30";
    char nomeItem[51] = "Arroz Branco";
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
    printf("///           = = = = RELATÓRIO - CONSUMOS DIÁRIOS = = = =            ///\n");
    printf("///                                                                   ///\n");
    printf("              Total de consumos realizados hoje: 2                       \n");
    printf("              Data: 23/03/2021                                           \n");
    printf("              _____________________________________________              \n");
    
    for(int i=0; i < 2; i++){
        printf("                                                                         \n");
        printf("                 Data Consumo: %s\n", dataConsumo);
        printf("                 Horário Consumo: %s\n\n", horaConsumo);
        printf("                 Lista de Itens:\n\n");

        for (int i = 0; i < 5; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem, quant);
        }

        printf("              _____________________________________________              \n");
    }
    
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void consumoMensal(void){
    char dataConsumo1[11] = "03/03/2021";
    char horaConsumo1[6] = "08:30";
    char nomeItem1[51] = "Arroz Branco";
    int quant1 = 5;

    char dataConsumo2[11] = "12/03/2021";
    char horaConsumo2[6] = "10:33";
    char nomeItem2[51] = "Macarrão";
    int quant2 = 8;

    char dataConsumo3[11] = "25/03/2021";
    char horaConsumo3[6] = "14:54";
    char nomeItem3[51] = "Feijão";
    int quant3 = 2;

    char dataConsumo4[11] = "29/03/2021";
    char horaConsumo4[6] = "11:02";
    char nomeItem4[51] = "Macarrão";
    int quant4 = 8;

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
    printf("///           = = = = RELATÓRIO - CONSUMOS MENSAIS = = = =            ///\n");
    printf("///                                                                   ///\n");
    printf("              Total de consumos realizados esse mês: 4                   \n");
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Consumo: %s\n", dataConsumo1);
    printf("                 Horário Consumo: %s\n\n", horaConsumo1);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 5; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem1, quant1);
    }
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Consumo: %s\n", dataConsumo2);
    printf("                 Horário Consumo: %s\n\n", horaConsumo2);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 8; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem2, quant2);
    }
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Consumo: %s\n", dataConsumo3);
    printf("                 Horário Consumo: %s\n\n", horaConsumo3);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 2; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem3, quant3);
    }
    printf("              _____________________________________________              \n");
    
    printf("                                                                         \n");
    printf("                 Data Consumo: %s\n", dataConsumo4);
    printf("                 Horário Consumo: %s\n\n", horaConsumo4);
    printf("                 Lista de Itens:\n\n");
    for (int i = 0; i < 8; i++){
        printf("                 %s, %d unidade(s) \n", nomeItem4, quant4);
    }
    printf("              _____________________________________________              \n");
    
    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

void consumoAnual(void){
    char mes[2];
    int m;

    char dataConsumo1[11] = "03/03/2021";
    char horaConsumo1[6] = "08:30";
    char nomeItem1[51] = "Arroz Branco";
    int quant1 = 5;

    char dataConsumo2[11] = "12/03/2021";
    char horaConsumo2[6] = "10:33";
    char nomeItem2[51] = "Macarrão";
    int quant2 = 8;

    char dataConsumo3[11] = "25/03/2021";
    char horaConsumo3[6] = "14:54";
    char nomeItem3[51] = "Feijão";
    int quant3 = 2;

    char dataConsumo4[11] = "29/03/2021";
    char horaConsumo4[6] = "11:02";
    char nomeItem4[51] = "Macarrão";
    int quant4 = 8;


    int validaDig;

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
    printf("///           = = = = RELATÓRIO - CONSUMOS ANUAIS = = = =             ///\n");
    printf("///                                                                   ///\n");
    printf("              Total de consumos realizados esse ano: 4                   \n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("Informe o mês que deseja ver o relatório (1/12): ");
        scanf("%[^\n]", mes);
        getchar();
        validaDig = testeDigitosNumericos(mes);
        m = converteCharParaInt(mes);

        if(validaDig || (m < 1 || m > 12)){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(validaDig || (m < 1 || m > 12));

    if (m == 1){
        printf("              _____________________________________________              \n");
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - JANEIRO = = = =                     ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");

    } else if (m == 2){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - FEVEREIRO = = = =                   ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Consumo: %s\n", dataConsumo1);
        printf("                 Horário Consumo: %s\n\n", horaConsumo1);
        printf("                 Lista de Itens:\n\n");

        for (int i = 0; i < 5; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem1, quant1);
        }

        printf("              _____________________________________________              \n");
        
    } else if (m == 3){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - MARÇO = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 4){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - ABRIL = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 5){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - MAIO = = = =                        ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Consumo: %s\n", dataConsumo2);
        printf("                 Horário Consumo: %s\n\n", horaConsumo2);
        printf("                 Lista de Itens:\n\n");
        for (int i = 0; i < 8; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem2, quant2);
        }

        printf("              _____________________________________________              \n");
        
    } else if (m == 6){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - JUNHO = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 7){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - JULHO = = = =                       ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 8){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - AGOSTO = = = =                      ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Consumo: %s\n", dataConsumo3);
        printf("                 Horário Consumo: %s\n\n", horaConsumo3);
        printf("                 Lista de Itens:\n\n");
        for (int i = 0; i < 2; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem3, quant3);
        }

        printf("              _____________________________________________              \n");
        
    } else if (m == 9){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - SETEMBRO = = = =                    ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 10){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - OUTUBRO = = = =                     ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 11){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - NOVEMBRO = = = =                    ///\n");
        printf("///                                                                   ///\n");
        printf("              Não foi registrado nenhum consumo nesse mês!            ///\n");
        printf("///        ___________________________________________________        ///\n");
        
    } else if (m == 12){
        printf("///                                                                   ///\n");
        printf("///           = = = = RELATÓRIO - DEZEMBRO = = = =                    ///\n");
        printf("///                                                                   ///\n");
        printf("                 Data Consumo: %s\n", dataConsumo4);
        printf("                 Horário Consumo: %s\n\n", horaConsumo4);
        printf("                 Lista de Itens:\n\n");
        for (int i = 0; i < 8; i++){
            printf("                 %s, %d unidade(s) \n", nomeItem4, quant4);
        }
        
        printf("              _____________________________________________              \n");

    }

    printf("\n/////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

