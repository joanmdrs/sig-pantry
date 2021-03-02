#include <stdio.h>
#include <stdlib.h>
#include "moduloTestes.h"


/* A função menuPrincipal realiza a navegação para os demais módulos do projeto. */

char menuPrincipal(void){
    char opcao;
    int teste;

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
    printf("///            MENU:                                                  ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Módulo Produtos                                    ///\n");
    printf("///            2 - Módulo Compras                                     ///\n");
    printf("///            3 - Módulo Consumo                                     ///\n");
    printf("///            4 - Sobre o Sistema                                    ///\n");
    printf("///            0 - Encerrar Programa                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("Informe a sua opção : ");
    scanf("%c", &opcao);
    getchar();
    teste = testeDigito(opcao);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira novamente um valor correto: ");
        scanf("%c", &opcao);
        getchar();
        teste = testeDigito(opcao);
    }
	return opcao;

}