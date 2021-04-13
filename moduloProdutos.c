#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"

typedef struct produto Produto;

struct produto {
    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char quant[10];
};


/* A função menuProdutos irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listar, referentes ao módulo produtos. */

char menuProdutos(void){

    char opcao;
    int validaI; 
    int validaII;  

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
        scanf("%[^\n]", &opcao);
        getchar();
        validaI = testeDigito(opcao);
        validaII = validaOpcaoMenu(opcao, 5); 

        if(!validaI || !validaII){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaI || !validaII);

	return opcao;

}

/* A função gravarProduto salva o produto no arquivo produtos.dat. */

void gravarProduto(Produto* pro){
    FILE* file;

    file = fopen("produtos.dat", "ab");

    fwrite(pro, sizeof(Produto), 1, file);

    fclose(file);
}

/* A função telaCadastrarProduto realiza o cadastro de um produto. */

Produto* telaCadastrarProduto(void){
    
    int validaCod;
	int validaDig;
	int validaData;
    int validaNull;

    int quantC;

    limpaTela();
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

// ----------------------- Alocando espaço de memória ----------------------------------

    Produto* pro;
    pro = (Produto*) malloc(sizeof(Produto));

// ----------------------- Validando o código de barras ----------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%[^\n]", pro->codBarras);
        getchar();

		validaCod = validaCodBarras(pro->codBarras);
        validaDig = testeDigitosNumericos(pro->codBarras);
        validaNull = verificaNulo(pro->codBarras);

		if(!validaCod || validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod || validaDig || validaNull);

// ----------------------- Validando a descrição do produto ------------------------------

    do{
        printf("///            - Descrição: ");
        scanf("%[^\n]", pro->nomeItem);
        getchar();

        validaDig = testeDigitos(pro->nomeItem);
        validaNull = verificaNulo(pro->nomeItem);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

// ----------------------- Validando a data de validade ----------------------------------

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", pro->dataValidade);
        getchar();

        validaData = testaData(pro->dataValidade);
        validaDig = testeDigitosNumericosData(pro->dataValidade);
        validaNull = verificaNulo(pro->dataValidade);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

// -------------------------------- Validando o local ------------------------------------

    do{
        printf("///            - Local: ");
        scanf("%[^\n]", pro->local);
        getchar();

        validaDig = testeDigitos(pro->local);
        validaNull = verificaNulo(pro->local);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

// -------------------------------- Validando o status -----------------------------------

    do{
        printf("///            - Status: ");
        scanf("%[^\n]", pro->status);
        getchar();

        validaDig = testeDigitos(pro->status);
        validaNull = verificaNulo(pro->status);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

// ----------------------------- Validando a quantidade ----------------------------------
      
    do{
        printf("///            - Quantidade: ");
        scanf("%[^\n]", pro->quant);
        getchar();

        validaDig = testeDigitosNumericos(pro->quant);
        validaNull = verificaNulo(pro->quant);

        if(validaDig || validaNull){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    quantC = converteCharParaInt(pro->quant);

// ---------------------------------------------------------------------------------------

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                  Produto cadastrado com sucesso !                 ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///              Código de Barras: %s \n", pro->codBarras);
    printf("///                     Descrição: %s \n", pro->nomeItem);
    printf("///              Data de Validade: %s \n", pro->dataValidade);
    printf("///                         Local: %s \n", pro->local);
    printf("///                        Status: %s \n", pro->status);
    printf("///                    Quantidade: %d \n", quantC);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                >>> Tecle <ENTER> para continuar...                ///\n");
    getchar();

    return pro;

}

/* A função cadastrarProduto faz o procedimento para o cadastro de um produto. */

void cadastrarProduto(void){
    Produto* prod;

    prod = telaCadastrarProduto();

    gravarProduto(prod);

    free(prod);
}

/* A função buscaProduto verifica se o produto está no arquivo produtos.dat. */

Produto* buscaProduto(char op){

    int validaCod;
	int validaDig;
    int validaNull;

    FILE* file;
    Produto* prod;

    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "rb");

    while(!feof(file)){
        fread(prod, sizeof(Produto), 1, file);

        if(op == 'a'){
            char codBarras[14];

// ----------------------- Validando o código de barras ----------------------------------

            do{
                printf("///            - Código de Barras: ");
                scanf("%[^\n]", codBarras);
                getchar();

                validaCod = validaCodBarras(codBarras);
                validaDig = testeDigitosNumericos(codBarras);
                validaNull = verificaNulo(codBarras);

                if(!validaCod || validaDig || validaNull){
                    printf("///            Código inválido, tente novamente !\n");
                }

            }while(!validaCod || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

            if(!strcmp(prod->codBarras, codBarras)){
                fclose(file);
                return prod;
            }

        } else if(op == 'b'){
            char nomeItem[51];

// ----------------------- Validando a descrição do produto ------------------------------

            do{
                printf("///            - Descrição: ");
                scanf("%[^\n]", nomeItem);
                getchar();

                validaDig = testeDigitos(nomeItem);
                validaNull = verificaNulo(nomeItem);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);

// ---------------------------------------------------------------------------------------
            
            if(!strcmp(prod->nomeItem, nomeItem)){
                fclose(file);
                return prod;
            }
        } else{
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("///          Opção Inválida!                                          ///\n");  
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }
    }

    fclose(file);
    return NULL;

}

/* A função telaPesquisarProduto realiza a busca de um produto. */

char telaPesquisarProduto(void){
    char tipoPesq;

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
    printf("///          = = = = =  MÓDULO PESQUISAR PRODUTO: = = = = =           ///\n");
    printf("///                                                                   ///\n");
    printf("///           a) Pesquisar pelo Cod. Barras                           ///\n");
    printf("///           b) Pesquisar pela Descrição                             ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            Informe o tipo de pesquisa : ");
        scanf("%[^\n]", &tipoPesq);
        getchar();

        validaDig = testeDigito(tipoPesq);

        if(validaDig){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(validaDig);

    return tipoPesq;

// ---------------------------------------------------------------------------------------
}

void exibeProduto(Produto* prod){

    if(prod == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não existem produtos cadastrados com a descricao         ///\n");  
        printf("///          informada.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        if (strcmp("x",prod->status)){
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("///                        PRODUTO LOCALIZADO!                        ///\n");
            printf("///                                                                   ///\n");
            printf("///              Código de Barras: %s \n", prod->codBarras);
            printf("///                     Descrição: %s \n", prod->nomeItem);
            printf("///              Data de Validade: %s \n", prod->dataValidade);
            printf("///                         Local: %s \n", prod->local);
            printf("///                        Status: %s \n", prod->status);
            int quantC = converteCharParaInt(prod->quant);
            printf("///                    Quantidade: %d \n", quantC);
            printf("///        ___________________________________________________        ///\n");

        }
    }

    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void pesquisarProduto(void){
    Produto* pro;
    char opcao;

    opcao = telaPesquisarProduto();

    pro = buscaProduto(opcao);

    exibeProduto(pro);

    free(pro);
}


/* A função telaExcluirProduto realiza a exclusão de um produto. */

char telaExcluirProduto(Produto* pro){
    char codigoBarras[14];

    int validaCod;
    int validaDig;
    int validaNull;

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
    printf("///            = = = = = MÓDULO EXCLUIR PRODUTO: = = = = =            ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%[^\n]", codigoBarras);
        getchar();
        
		validaCod = validaCodBarras(codigoBarras);
        validaDig = testeDigitosNumericos(codigoBarras);
        validaNull = verificaNulo(codigoBarras);

		if(!validaCod || validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod || validaDig || validaNull);
    
    return codigoBarras;
}

Produto* buscaProdutoPorCodBarra(char codBarras[]){

    int validaCod;
	int validaDig;
    int validaNull;

    FILE* file;
    Produto* prod;

    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "rb");

    while(!feof(file)){
        fread(prod, sizeof(Produto), 1, file);

        if(!strcmp(prod->codBarras, codBarras)){
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("///                        PRODUTO LOCALIZADO!                        ///\n");
            printf("///                                                                   ///\n");
            printf("///              Código de Barras: %s \n", prod->codBarras);
            printf("///                     Descrição: %s \n", prod->nomeItem);
            printf("///              Data de Validade: %s \n", prod->dataValidade);
            printf("///                         Local: %s \n", prod->local);
            printf("///                        Status: %s \n", prod->status);
            printf("///                    Quantidade: %s \n", prod->quant);
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");

            fclose(file);
            return prod;
        }
    }

    fclose(file);
    return NULL;

}

void excProduto(Produto* pro){
    FILE* file;
    Produto* prod;
    char resposta;

    int validaDig;
    int validaOp;

    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "r+b");

    if(pro == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não foi encontrado nenhum produto com esse               ///\n");  
        printf("///          código de barras!                                        ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    } else{
        while(!feof(file)) {
            if (strcmp("x",pro->status)){
                do{
                    printf("///            - Confirmar operação (S/N) ? ");
                    scanf("%[^\n]", &resposta);
                    getchar();

                    validaDig = testeDigito(resposta);
                    validaOp = validaOpcao(resposta);
                    

                    if(!validaOp || validaDig){
                        printf("///            Opcão inválida, tente novamente!\n");
                    }

                }while(!validaOp || validaDig);

                if (resposta == 'S' || resposta == 's'){

                    fread(prod, sizeof(Produto), 1, file);
                    if(!strcmp(pro->codBarras, prod->codBarras) && strcmp(prod->status, "x")){
                        strcpy(prod->status, "x");
                        fseek(file, -1*sizeof(Produto), SEEK_CUR);
                        fwrite(prod, sizeof(Produto), 1, file);
                    }

                    printf("///                                                                   ///\n");
                    printf("///            Produto excluído com sucesso!                          ///\n"); 
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

                } else if (resposta == 'N' || resposta == 'n'){
                    printf("///                                                                   ///\n");
                    printf("///            Operação cancelada!                                    ///\n"); 
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

                }
            }
        }
    }
    fclose(file);

}

void excluirProduto(void){
    Produto* prod;
    char codBarras[14];

    codBarras = telaExcluirProduto;

    prod = buscaProdutoPorCodBarra(codBarras);

    excProduto(prod);

}


/* A função telaAlterarProduto realiza a alteração de um produto. */

void telaAlterarProduto(Produto* pro){

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char quant[10];

    char resposta;
    char respostaLetras;
    char decisao;

    int validaCod;
    int validaDig;
    int validaOp;
    int validaData;
    int validaNull;

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
    printf("///            = = = = = MÓDULO ALTERAR PRODUTO: = = = = =            ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            - Código de Barras: ");
        scanf("%[^\n]", codBarras);
        getchar();
        
		validaCod = validaCodBarras(codBarras);
        validaDig = testeDigitosNumericos(codBarras);
        validaNull = verificaNulo(codBarras);

		if(!validaCod || validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod || validaDig || validaNull);

    if(!strcmp(codBarras, pro->codBarras) && strcmp("x", pro->status)){

        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///                        PRODUTO LOCALIZADO!                        ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", pro->codBarras);
        printf("///                     Descrição: %s \n", pro->nomeItem);
        printf("///              Data de Validade: %s \n", pro->dataValidade);
        printf("///                         Local: %s \n", pro->local);
        printf("///                        Status: %s \n", pro->status);
        printf("///                    Quantidade: %s \n", pro->quant);
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");

// ----------------------------------------------------------------------------------------------------

        do{
            printf("///            - Deseja alterar todos os itens do produto (S/N) ? ");
            scanf("%[^\n]", &resposta);
            getchar();

            validaDig = testeDigito(resposta);
            validaOp = validaOpcao(resposta);
            

            if(!validaOp || validaDig){
                printf("///            Opcão inválida, tente novamente!\n");
            }

        }while(!validaOp || validaDig);

// ---------------------------------------------------------------------------------------

        if (resposta == 'S' || resposta == 's'){
            printf("///                                                                   ///\n");
            printf("///           INFORME OS NOVOS VALORES DO PRODUTO:                    ///\n");
            printf("///                                                                   ///\n");
        
            do{
                printf("///            - Nova Descrição: ");
                scanf("%[^\n]", nomeItem);
                getchar();

                validaDig = testeDigitos(nomeItem);
                validaNull = verificaNulo(nomeItem);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);
            
            do{
                printf("///            - Nova Data Val. (dd/mm/aaaa): ");
                scanf("%[^\n]", dataValidade);
                getchar();
            
                validaData = testaData(dataValidade);
                validaDig = testeDigitosNumericosData(dataValidade);
                validaNull = verificaNulo(dataValidade); 

                if (!validaData || validaDig || validaNull) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData || validaDig || validaNull);

            do{
                printf("///            - Novo Local: ");
                scanf("%[^\n]", local);
                getchar();

                validaDig = testeDigitos(local);
                validaNull = verificaNulo(local);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);

            do{
                printf("///            - Novo Status: ");
                scanf("%[^\n]", status);
                getchar();

                validaDig = testeDigitos(status);
                validaNull = verificaNulo(status);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);
            
            do{
                printf("///            - Nova Quantidade: ");
                scanf("%[^\n]", quant);
                getchar();
                
                validaDig = testeDigitosNumericos(quant);
                validaNull = verificaNulo(quant);

                if(validaDig || validaNull){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);            

            do{
                printf("///            - Confirmar operação (S/N) ? ");
                scanf("%[^\n]", &decisao);
                getchar();

                validaDig = testeDigito(decisao);
                validaOp = validaOpcao(decisao);

                if(!validaOp || validaDig){
                    printf("///            Opcão inválida, tente novamente!\n");
                }

            }while(!validaOp || validaDig);

            if (decisao == 'S' || decisao == 's'){

                strcpy(pro->nomeItem, nomeItem);
                strcpy(pro->dataValidade, dataValidade);
                strcpy(pro->local, local);
                strcpy(pro->status, status);
                strcpy(pro->quant, quant);

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
                scanf("%[^\n]", &respostaLetras);
                getchar();

                validaDig = testeDigito(respostaLetras);
                validaOp = validaOpcaoLetrasAE(respostaLetras);
                

                if(!validaOp || validaDig){
                    printf("///            Opcão inválida, tente novamente!\n");
                }

            }while(!validaOp || validaDig);

            if (respostaLetras == 'A' || respostaLetras == 'a'){
                printf("///                                                                   ///\n");
            
                do{
                    printf("///            - a) Nova Descrição: ");
                    scanf("%[^\n]", nomeItem);
                    getchar();

                    validaDig = testeDigitos(nomeItem);
                    validaNull = verificaNulo(nomeItem);

                    if(validaDig || validaNull){
                        printf("///            Caracteres inválidos, tente novamente !\n");
                    }

                }while (validaDig || validaNull);

                strcpy(pro->nomeItem, nomeItem);

            }else if(resposta == 'B' || respostaLetras == 'b'){
                printf("///                                                                   ///\n");
                
                do{
                    printf("///            - b) Nova Data Val. (dd/mm/aaaa): ");
                    scanf("%[^\n]", dataValidade);
                    getchar();
                
                    validaData = testaData(dataValidade);
                    validaDig = testeDigitosNumericosData(dataValidade);
                    validaNull = verificaNulo(dataValidade);

                    if (!validaData || validaDig || validaNull) {
                        printf("///            Data inválida, tente novamente !\n");
                    }

                }while(!validaData || validaDig || validaNull);

                strcpy(pro->dataValidade, dataValidade);

            }else if(respostaLetras == 'C' || respostaLetras == 'c'){
                printf("///                                                                   ///\n");
                
                do{
                    printf("///            - c) Novo Local: ");
                    scanf("%[^\n]", local);
                    getchar();

                    validaDig = testeDigitos(local);
                    validaNull = verificaNulo(local);

                    if(validaDig || validaNull){
                        printf("///            Caracteres inválidos, tente novamente !\n");
                    }

                }while (validaDig || validaNull);

                strcpy(pro->local, local);

    // -------------------------------- Validando o status -----------------------------------

            }else if(respostaLetras == 'D' || respostaLetras == 'd'){
                printf("///                                                                   ///\n");
                
                do{
                    printf("///            - d) Novo Status: ");
                    scanf("%[^\n]", status);
                    getchar();

                    validaDig = testeDigitos(status);
                    validaNull = verificaNulo(status);

                    if(validaDig || validaNull){
                        printf("///            Caracteres inválidos, tente novamente !\n");
                    }

                }while (validaDig || validaNull);

                strcpy(pro->status, status);

            }else if(respostaLetras == 'E' || respostaLetras == 'e'){
                printf("///                                                                   ///\n");
                    
                do{
                    printf("///            - e) Nova Quantidade: ");
                    scanf("%[^\n]", quant);
                    getchar();
                    
                    validaDig = testeDigitosNumericos(quant);
                    validaNull = verificaNulo(quant);

                    if(validaDig || validaNull){
                        printf("///            Dígitos inválidos, tente novamente !\n");
                    }

                }while (validaDig || validaNull);

                strcpy(pro->quant, quant);

            }

        }
    
    }else{
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            Não existem produtos cadastrados com o código          ///\n");  
        printf("///            de barras informado.                                   ///\n");    
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}


/* A função telaListarProdutos realiza a listagem de todos os produtos. */

void telaListarProdutos(void){

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
