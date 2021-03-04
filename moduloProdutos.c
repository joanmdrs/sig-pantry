#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"


/* A função menuProdutos irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listar, referentes ao módulo produtos. */

char menuProdutos(void){
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
    printf("///            PRODUTOS:                                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Cadastrar produto                                  ///\n");
    printf("///            2 - Pesquisar produto                                  ///\n");
    printf("///            3 - Excluir produto                                    ///\n");
    printf("///            4 - Alterar produto                                    ///\n");
    printf("///            5 - Listar produtos                                    ///\n");
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

/* A função telaCadastrarProduto realiza o cadastro de um produto. */

void telaCadastrarProduto(void){

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char quant[10];
    
    int validaCod;
	int validaDig;
	int validaData;

	char dia[3];
	int diaC;
	char mes[3];
	int mesC;
	char ano[5];
	int anoC;
	int quantC = 0;

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
    printf("///          = = = = =  MÓDULO CADASTRAR PRODUTO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

// ----------------------- Validando o código de barras ----------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%s", codBarras);
        getchar();
    
		validaCod = validaCodBarras(codBarras);

		if(!validaCod){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod);

// ----------------------- Validando a descrição do produto ------------------------------

    do{
        printf("///            - Descrição: ");
        scanf("%s", nomeItem);
        getchar();

        validaDig = testeDigitos(nomeItem);

        if(validaDig){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig);

// ----------------------- Validando a data de validade ----------------------------------

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%s", dataValidade);
        getchar();

        dia[0] = dataValidade[0];
		dia[1] = dataValidade[1];
		diaC = converteCharParaInt(dia);

		mes[0] = dataValidade[3];
		mes[1] = dataValidade[4];
		mesC = converteCharParaInt(mes);

		ano[0] = dataValidade[6];
		ano[1] = dataValidade[7];
		ano[2] = dataValidade[8];
		ano[3] = dataValidade[9];
		anoC = converteCharParaInt(ano);
    
        validaData = testaData(diaC, mesC, anoC);
        validaDig = testeDigitosNumericosData(dataValidade);

        if (!validaData || validaDig) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig);

// -------------------------------- Validando o local ------------------------------------

    do{
        printf("///            - Local: ");
        scanf("%s", local);
        getchar();

        validaDig = testeDigitos(local);

        if(validaDig){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig);

// -------------------------------- Validando o status -----------------------------------

    do{
        printf("///            - Status: ");
        scanf("%s", status);
        getchar();

        validaDig = testeDigitos(status);

        if(validaDig){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig);

// ----------------------------- Validando a quantidade ----------------------------------
      
    do{
        printf("///            - Quantidade: ");
        scanf("%s", quant);
        getchar();
        
        validaDig = testeDigitosNumericos(quant);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig);

    quantC = converteCharParaInt(quant);

// ---------------------------------------------------------------------------------------

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                  Produto cadastrado com sucesso !                 ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///              Código de Barras: %s \n", codBarras);
    printf("///                     Descrição: %s \n", nomeItem);
    printf("///              Data de Validade: %s \n", dataValidade);
    printf("///                         Local: %s \n", local);
    printf("///                        Status: %s \n", status);
    printf("///                    Quantidade: %d \n", quantC);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                >>> Tecle <ENTER> para continuar...                ///\n");
    getchar();

}

/* A função telaPesquisarProduto realiza a busca de um produto. */

void telaPesquisarProduto(void){
    char codBarras[14];
    int validaCod;
    
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
    printf("///          = = = = =  MÓDULO PESQUISAR PRODUTO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%s", codBarras);
        getchar();
    
		validaCod = validaCodBarras(codBarras);

		if(!validaCod){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                         VALOR DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: %s \n",codBarras);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            PRODUTO LOCALIZADO!                                    ///\n"); ///se encontrar
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Descrição:                                           ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///            Não existem produtos cadastrados com o código          ///\n"); ///se não encontrar   
    printf("///            de barras informado.                                   ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

/* A função telaExcluirProduto realiza a exclusão de um produto. */

void telaExcluirProduto(void){
    char codBarras[14];
    char resposta;

    int validaCod;
    int validaOp;
    int validaDig;

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
    printf("///            = = = = = MÓDULO EXCLUIR PRODUTO: = = = = =            ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%s", codBarras);
        getchar();
        
		validaCod = validaCodBarras(codBarras);

		if(!validaCod){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                         VALOR DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: %s \n",codBarras);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            PRODUTO LOCALIZADO!                                    ///\n"); 
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///            Não existem produtos cadastrados com o código          ///\n");    
    printf("///            de barras informado.                                   ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%c", &resposta);
        getchar();

        validaDig = testeDigito(resposta);
        validaOp = validaOpcao(resposta);
        

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);

// ---------------------------------------------------------------------------------------


    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                         VALOR DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Opção escolhida: %c \n",resposta);
    printf("/// _________________________________________________________________ ///\n");

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///            Produto excluído com sucesso!                          ///\n"); 
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

    }
    
}

/* A função telaAlterarProduto realiza a alteração de um produto. */


void telaAlterarProduto(void){
    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char resposta;
    char respostaLetras;
    char decisao;
    char quant[10];
    int validaCod;
    int validaDig;
    int validaOp;
    int validaData;

	char dia[3];
	int diaC;
	char mes[3];
	int mesC;
	char ano[5];
	int anoC;
	int quantC = 0;

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
    printf("///            = = = = = MÓDULO ALTERAR PRODUTO: = = = = =            ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%s", codBarras);
        getchar();
        
		validaCod = validaCodBarras(codBarras);

		if(!validaCod){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALOR DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: %s \n",codBarras);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            PRODUTO LOCALIZADO!                                    ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras:                                    ///\n");
    printf("///            - Descrição:                                           ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///            Não existem produtos cadastrados com o código          ///\n"); 
    printf("///            de barras informado.                                   ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%c", &resposta);
        getchar();

        validaDig = testeDigito(resposta);
        validaOp = validaOpcao(resposta);
        

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALOR DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Opção escolhida: %c \n",resposta);
    printf("///___________________________________________________________________///\n");

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///           INFORME OS NOVOS VALORES DO PRODUTO:                    ///\n");
        printf("///                                                                   ///\n");
        
// ----------------------- Validando a descrição do produto ------------------------------

        do{
            printf("///            - Nova Descrição: ");
            scanf("%s", nomeItem);
            getchar();

            validaDig = testeDigitos(nomeItem);

            if(validaDig){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }

        }while (validaDig);

// ----------------------- Validando a data de validade ----------------------------------
        
        do{
            printf("///            - Nova Data Val. (dd/mm/aaaa): ");
            scanf("%s", dataValidade);
            getchar();

            dia[0] = dataValidade[0];
            dia[1] = dataValidade[1];
            diaC = converteCharParaInt(dia);

            mes[0] = dataValidade[3];
            mes[1] = dataValidade[4];
            mesC = converteCharParaInt(mes);

            ano[0] = dataValidade[6];
            ano[1] = dataValidade[7];
            ano[2] = dataValidade[8];
            ano[3] = dataValidade[9];
            anoC = converteCharParaInt(ano);
        
            validaData = testaData(diaC, mesC, anoC);
            validaDig = testeDigitosNumericosData(dataValidade);

            if (!validaData ) {
                printf("///            Data inválida, tente novamente !\n");
            }

        }while(!validaData);

// -------------------------------- Validando o local ------------------------------------

        do{
            printf("///            - Novo Local: ");
            scanf("%s", local);
            getchar();

            validaDig = testeDigitos(local);

            if(validaDig){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }

        }while (validaDig);

// -------------------------------- Validando o status -----------------------------------

    do{
        printf("///            - Novo Status: ");
        scanf("%s", status);
        getchar();

        validaDig = testeDigitos(status);

        if(validaDig){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig);        
        
// ----------------------------- Validando a quantidade ----------------------------------

    do{
        printf("///            - Nova Quantidade: ");
        scanf("%s", quant);
        getchar();
        
        validaDig = testeDigitosNumericos(quant);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig);

    quantC = converteCharParaInt(quant);
        

        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
        printf("///                                                                   ///\n");
        printf("///                          Nome: %s \n", nomeItem);
        printf("///              Data de Validade: %s \n", dataValidade);
        printf("///                         Local: %s \n", local);
        printf("///                        Status: %s \n", status);
        printf("///                    Quantidade: %d \n", quantC);
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%c", &decisao);
        getchar();

        validaDig = testeDigito(decisao);
        validaOp = validaOpcao(decisao);

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);

// ---------------------------------------------------------------------------------------

        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALOR DE ENTRADA:                           ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Opção escolhida: %c \n",decisao);
        printf("/// _________________________________________________________________ ///\n");

        if (decisao == 'S' || decisao == 's'){
            printf("///                                                                   ///\n");
            printf("///            Produto alterado com sucesso!                          ///\n"); 
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
        printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Digite 'a' para alterar o nome                       ///\n");
        printf("///            - Digite 'b' para alterar a validade                   ///\n");
        printf("///            - Digite 'c' para alterar o local                      ///\n");
        printf("///            - Digite 'd' para alterar o status                     ///\n");
        printf("///            - Digite 'e' para alterar a quantidade:                ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Informe a sua opção: ");
        scanf("%c", &respostaLetras);
        getchar();

        validaDig = testeDigito(respostaLetras);
        validaOp = validaOpcaoLetrasAE(respostaLetras);
        

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);

// ---------------------------------------------------------------------------------------

        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALOR DE ENTRADA:                           ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Opção escolhida: %c \n",respostaLetras);
        printf("/// _________________________________________________________________ ///\n");

        if (respostaLetras == 'A' || respostaLetras == 'a'){
            printf("///                                                                   ///\n");
        
// ----------------------- Validando a descrição do produto ------------------------------

            do{
                printf("///            - a) Nova Descrição: ");
                scanf("%s", nomeItem);
                getchar();

                validaDig = testeDigitos(nomeItem);

                if(validaDig){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig);

// ---------------------------------------------------------------------------------------

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                          Nome: %s \n", nomeItem);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O nome do produto foi alterado!                        ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(resposta == 'B' || respostaLetras == 'b'){
            printf("///                                                                   ///\n");
            
// ----------------------- Validando a data de validade ----------------------------------

            do{
                printf("///            - b) Nova Data Val. (dd/mm/aaaa): ");
                scanf("%s", dataValidade);
                getchar();

                dia[0] = dataValidade[0];
                dia[1] = dataValidade[1];
                diaC = converteCharParaInt(dia);

                mes[0] = dataValidade[3];
                mes[1] = dataValidade[4];
                mesC = converteCharParaInt(mes);

                ano[0] = dataValidade[6];
                ano[1] = dataValidade[7];
                ano[2] = dataValidade[8];
                ano[3] = dataValidade[9];
                anoC = converteCharParaInt(ano);
            
                validaData = testaData(diaC, mesC, anoC);
                validaDig = testeDigitosNumericosData(dataValidade);

                if (!validaData ) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData);

// ---------------------------------------------------------------------------------------

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///              Data de Validade: %s \n", dataValidade);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A data de validade do produto foi alterada!            ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'C' || respostaLetras == 'c'){
            printf("///                                                                   ///\n");
            
// -------------------------------- Validando o local ------------------------------------

            do{
                printf("///            - c) Novo Local: ");
                scanf("%s", local);
                getchar();

                validaDig = testeDigitos(local);

                if(validaDig){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig);

// ---------------------------------------------------------------------------------------

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                         Local: %s \n", local);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O local do produto foi alterado!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'D' || respostaLetras == 'd'){
            printf("///                                                                   ///\n");
            
// -------------------------------- Validando o status -----------------------------------

            do{
                printf("///            - d) Novo Status: ");
                scanf("%s", status);
                getchar();

                validaDig = testeDigitos(status);

                if(validaDig){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig);

// ---------------------------------------------------------------------------------------

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                        Status: %s \n", status);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O status do produto foi alterado!                      ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'E' || respostaLetras == 'e'){
            printf("///                                                                   ///\n");
            
// ----------------------------- Validando a quantidade ----------------------------------
      
            do{
                printf("///            - e) Nova Quantidade: ");
                scanf("%s", quant);
                getchar();
                
                validaDig = testeDigitosNumericos(quant);

                if(validaDig){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig);

            quantC = converteCharParaInt(quant);

// ---------------------------------------------------------------------------------------

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                    Quantidade: %d \n", quantC);       
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A quantidade foi alterada!                             ///\n");
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

/* A função telaListarProdutos realiza a listagem de todos os produtos. */

void telaListarProdutos(void){
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
