#include <stdio.h>
#include <stdlib.h>
#include "moduloValidacoes.h"


/* A função menuPrincipal realiza a navegação para os demais módulos do projeto. */

char menuPrincipal(void){
    
    char opcao;
    int validaOp;
    int validaOpM;

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            MENU:                                                  ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Módulo Produtos                                    ///\n");
    printf("///            2 - Módulo Compras                                     ///\n");
    printf("///            3 - Módulo Consumo                                     ///\n");
    printf("///            4 - Módulo Relatorios                                  ///\n");
    printf("///            5 - Sobre o sistema                                    ///\n");
    printf("///            0 - Encerrar Programa                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();

        printf("%c \n", opcao);

        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 5); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}