#include <stdio.h>
#include <stdlib.h>

char menuRelatorios(void){
    char opcao;
    int validaOp;
    int validaOpM;

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
        scanf("%c", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoSubMenu(opcao); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

void telaRelatorioProdutos(void){
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
    printf("///            MÓDULO LISTAR PRODUTOS:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void telaRelatorioCompras(void){
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
    printf("///            MÓDULO LISTAR PRODUTOS:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void telaRelatorioConsumo(void){
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
    printf("///            MÓDULO LISTAR PRODUTOS:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

