#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"

typedef struct produto Produto;

struct produto {
    char codBarras[14];
    char dataValidade[11];
    char nomeItem[51];
    char local[20];
    int quant;
    char status[11];
};

typedef struct chaveP ChaveP;

struct chaveP {
    char codBarras[14];
    char dataValidade[11];
};

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

void gravarProduto(Produto* pro){
    FILE* file;
    file = fopen("produtos.dat", "ab");
    fwrite(pro, sizeof(Produto), 1, file);
    fclose(file);
}

void exibeProduto(Produto* prod){

    if(prod == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não foi encontrado nenhum produto com os dados           ///\n");  
        printf("///          fornecidos                                               ///\n");
        printf("///        ___________________________________________________        ///\n");
    } else {
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", prod->codBarras);
        printf("///              Data de Validade: %s \n", prod->dataValidade);
        printf("///                     Descrição: %s \n", prod->nomeItem);
        printf("///                         Local: %s \n", prod->local);
        printf("///                    Quantidade: %d \n", prod->quant);
        printf("///                        Status: %s \n", prod->status);
        printf("///        ___________________________________________________        ///\n");
    }
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

// SEÇÃO RELACIONADA AO CADASTRO ________________________________________________________________________________

Produto* telaCadastrarProduto(void){
    int validaCod;
	int validaDig;
	int validaData;
    int validaNull;

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

    FILE* fp;
    Produto* proe; // Produto existente no arquivo produtos.dat
    proe = (Produto*) malloc(sizeof(Produto));

    Produto* pro; // Produto a ser cadastrado no arquivo produtos.dat
    pro = (Produto*) malloc(sizeof(Produto));

    fp = fopen("produtos.dat", "rb");

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

    while(fread(proe, sizeof(Produto), 1, fp)) {
        if (!strcmp(proe->codBarras, pro->codBarras) && !strcmp(proe->dataValidade, pro->dataValidade)) {
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("///         Já existe um produto cadastrado com este CÓDIGO           ///\n");  
            printf("///         DE BARRAS e com essa DATA DE VALIDADE.                    ///\n"); 
            printf("///                                                                   ///\n");    
            printf("///         Recomendamos utilizar a função ALTERAR PRODUTO.           ///\n");                                          
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n"); 
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(fp);
            free(proe);
            free(pro);
            exit(1);  
        }
    }

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

// ----------------------------- Validando a quantidade ----------------------------------
    char quantidade[10];
    do{
        printf("///            - Quantidade: ");
        scanf("%[^\n]", quantidade);
        getchar();

        validaDig = testeDigitosNumericos(quantidade);
        validaNull = verificaNulo(quantidade);

        if(validaDig || validaNull){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    pro->quant = converteCharParaInt(quantidade);

    // -------------------------------- Definindo status -----------------------------------

    strcpy(pro->status, "DISPONIVEL");

// ---------------------------------------------------------------------------------------

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                  Produto cadastrado com sucesso !                 ///\n");
    exibeProduto(pro);

    return pro;

}

void cadastrarProduto(void){
    Produto* prod;
    prod = telaCadastrarProduto();
    gravarProduto(prod);
    free(prod);
}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

char telaTipoPesquisa(void){
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
    printf("///           a) Pesquisar pelo Código de Barras                      ///\n");
    printf("///           b) Pesquisar pela Descrição                             ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            Informe o tipo de pesquisa : ");
        scanf("%[^\n]", &tipoPesq);
        getchar();

        validaDig = testeDigito(tipoPesq);

        if(validaDig){
            printf("Opção inválida, tente novamente!\n");
        }
    }while(validaDig);
    printf("///                                                                   ///\n");
    return tipoPesq;
}

ChaveP* telaPesquisarPeloCod(void){
    int validaCod;
    int validaData;
    int validaDig;
    int validaNull;
    ChaveP* key;
    key = (ChaveP*) malloc(sizeof(ChaveP));

    do{
        printf("///            - Código de Barras: ");
        scanf("%[^\n]", key->codBarras);
        getchar();

		validaCod = validaCodBarras(key->codBarras);
        validaDig = testeDigitosNumericos(key->codBarras);
        validaNull = verificaNulo(key->codBarras);

		if(!validaCod || validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}
	}while(!validaCod || validaDig || validaNull);

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataValidade);
        getchar();

        validaData = testaData(key->dataValidade);
        validaDig = testeDigitosNumericosData(key->dataValidade);
        validaNull = verificaNulo(key->dataValidade);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }
    }while(!validaData || validaDig || validaNull);

    return key;
}

Produto* pegarProdutoPeloCod(ChaveP* key){

    FILE* file;
    Produto* pro;
    pro = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "rb");

    while(fread(pro, sizeof(Produto), 1, file)){
        if(!strcmp(pro->codBarras, key->codBarras) && !strcmp(pro->dataValidade, key->dataValidade) && strcmp(pro->status, "x") != 0){
            fclose(file);
            return pro;
        }
    }
    fclose(file);
    return NULL;
}

char* telaPesquisarPelaDesc(void){
    int validaDig;
    int validaNull;
    char* nomeItem;
    nomeItem = (char*) malloc(51*sizeof(char));

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

    return nomeItem;

}

Produto* pegarProdutoPelaDesc(char* desc){
    FILE* file;
    Produto* pro;
    pro = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "rb");

    while(fread(pro, sizeof(Produto), 1, file)){
        if(!strcmp(pro->nomeItem, desc)){
            fclose(file);
            return pro;
        }
    }
    fclose(file);
    return NULL;

}

void pesquisarProduto(void){
    Produto* pro;
    ChaveP* key;
    char opcao;
    char* desc;

    opcao = telaTipoPesquisa();

    if(opcao == 'a'){
        key = telaPesquisarPeloCod();
        pro = pegarProdutoPeloCod(key);
        exibeProduto(pro);
        free(key);
        free(pro);

    }else if(opcao == 'b'){
        desc = telaPesquisarPelaDesc();
        pro = pegarProdutoPelaDesc(desc);
        exibeProduto(pro);
        free(desc);
        free(pro);

    }
}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

ChaveP* telaExcluirProduto(void){
    int validaCod;
    int validaData;
    int validaDig;
    int validaNull;
    ChaveP* key;
    key = (ChaveP*) malloc(sizeof(ChaveP));

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

    do{
        printf("///            - Código de Barras: ");
        scanf("%[^\n]", key->codBarras);
        getchar();
        
		validaCod = validaCodBarras(key->codBarras);
        validaDig = testeDigitosNumericos(key->codBarras);
        validaNull = verificaNulo(key->codBarras);

		if(!validaCod || validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod || validaDig || validaNull);

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataValidade);
        getchar();

        validaData = testaData(key->dataValidade);
        validaDig = testeDigitosNumericosData(key->dataValidade);
        validaNull = verificaNulo(key->dataValidade);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }
    }while(!validaData || validaDig || validaNull);

    return key;
}

void excluirProdutoLogicamente(Produto* pro){
    FILE* file;
    Produto* prod;
    char resposta;
    int validaDig;
    int validaOp;

    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "r+b");

    if(pro == NULL){
        exibeProduto(pro);

    } else{
        exibeProduto(pro);
        printf("///                                                                   ///\n");
        do{
            printf("///            - Confirmar a exclusão do produto (S/N) ? ");
            scanf("%[^\n]", &resposta);
            getchar();

            validaDig = testeDigito(resposta);
            validaOp = validaOpcao(resposta);
            

            if(!validaOp || validaDig){
                printf("///            Opcão inválida, tente novamente!\n");
            }

        }while(!validaOp || validaDig);

        if (resposta == 'S' || resposta == 's'){
            while(fread(prod, sizeof(Produto), 1, file)) {
                if(!strcmp(pro->codBarras, prod->codBarras) && !strcmp(pro->dataValidade, prod->dataValidade) && strcmp(prod->status, "x")){
                    strcpy(prod->status, "x");
                    fseek(file, -1*sizeof(Produto), SEEK_CUR);
                    fwrite(prod, sizeof(Produto), 1, file);
                    break;
                    
                }
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
    fclose(file);
}

void excluirProduto(void){
    Produto* pro;
    ChaveP* key;

    key = telaExcluirProduto();
    pro = pegarProdutoPeloCod(key);
    excluirProdutoLogicamente(pro);
    free(key);
    free(pro);

}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

ChaveP* telaAlterarProduto(void){
    int validaCod;
    int validaData;
    int validaDig;
    int validaNull;
    ChaveP* key;
    key = (ChaveP*) malloc(sizeof(ChaveP));

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
        scanf("%[^\n]", key->codBarras);
        getchar();
        
		validaCod = validaCodBarras(key->codBarras);
        validaDig = testeDigitosNumericos(key->codBarras);
        validaNull = verificaNulo(key->codBarras);

		if(!validaCod || validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod || validaDig || validaNull);

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataValidade);
        getchar();

        validaData = testaData(key->dataValidade);
        validaDig = testeDigitosNumericosData(key->dataValidade);
        validaNull = verificaNulo(key->dataValidade);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }
    }while(!validaData || validaDig || validaNull);

    return key;
}

Produto* telaAlterarTudo(){
    int validaDig;
    int validaNull;
    int validaData;
    Produto* pro;
    pro = (Produto*) malloc(sizeof(Produto));

    printf("///                                                                   ///\n");
    printf("///           INFORME OS NOVOS VALORES DO PRODUTO:                    ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            - Nova Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", pro->dataValidade);
        getchar();
    
        validaData = testaData(pro->dataValidade);
        validaDig = testeDigitosNumericosData(pro->dataValidade);
        validaNull = verificaNulo(pro->dataValidade); 

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }
    }while(!validaData || validaDig || validaNull);

    do{
        printf("///            - Nova Descrição: ");
        scanf("%[^\n]", pro->nomeItem);
        getchar();

        validaDig = testeDigitos(pro->nomeItem);
        validaNull = verificaNulo(pro->nomeItem);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }
    }while (validaDig || validaNull);
    
    do{
        printf("///            - Novo Local: ");
        scanf("%[^\n]", pro->local);
        getchar();

        validaDig = testeDigitos(pro->local);
        validaNull = verificaNulo(pro->local);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }
    }while (validaDig || validaNull);

    char quantidade[10];
    do{
        printf("///            - Nova Quantidade: ");
        scanf("%[^\n]", quantidade);
        getchar();
        
        validaDig = testeDigitosNumericos(quantidade);
        validaNull = verificaNulo(quantidade);

        if(validaDig || validaNull){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }
    }while (validaDig || validaNull); 

    pro->quant = converteCharParaInt(quantidade);

    return pro;   
}

char* telaAlterarValidade(void){
    int validaData;
    int validaDig;
    int validaNull;
    char* dataValidade;
    dataValidade = (char*) malloc(11*sizeof(char));

    do{
        printf("///            - a) Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", dataValidade);
        getchar();
    
        validaData = testaData(dataValidade);
        validaDig = testeDigitosNumericosData(dataValidade);
        validaNull = verificaNulo(dataValidade);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }
    }while(!validaData || validaDig || validaNull);

    return dataValidade;
}

char* telaAlterarDesc(void){
    int validaDig;
    int validaNull;
    char* nomeItem;
    nomeItem = (char*) malloc(51*sizeof(char));

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
    return nomeItem;
}

char* telaAlterarLocal(void){
    int validaDig;
    int validaNull;
    char* local;
    local = (char*) malloc(20*sizeof(char));    

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

    return local;
}

char* telaAlterarQuant(void){
    int validaDig;
    int validaNull;
    char* quant;
    quant = (char*) malloc(10*sizeof(char));

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

    return quant;
}

void regravarProduto(Produto* pro){
    int validaDig;
    int validaOp;
    char confirma;
    
    FILE* file;
    Produto* prod; // Variável para armazenar o produto a ser alterado.
    Produto* proe; // Variável que armazena os novos valores do produto.
    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "r+b");

    proe = telaAlterarTudo();
    printf("///                                                                    ///\n");
    
    do{
        printf("///            - Confirmar à alteração deste produto (S/N) ? ");
        scanf("%[^\n]", &confirma);
        getchar();

        validaDig = testeDigito(confirma);
        validaOp = validaOpcao(confirma);

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);

    if(confirma == 'S' || confirma == 's'){
        while(fread(prod, sizeof(Produto), 1, file)){
            if(!strcmp(pro->codBarras, pro->codBarras) && !strcmp(pro->dataValidade, pro->dataValidade) && strcmp(prod->status, "x")){
                strcpy(prod->dataValidade, proe->dataValidade);
                strcpy(prod->nomeItem, proe->nomeItem);
                strcpy(prod->local, proe->local);
                prod->quant = proe->quant;
                fseek(file, -1*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, file);
                break;
            }
        } 
        free(proe);
        printf("///                                                                   ///\n");
        printf("///            Produto alterado com sucesso!                          ///\n"); 
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(confirma == 'N' || confirma == 'n'){
        printf("///                                                                   ///\n");
        printf("///           Operação cancelada!                                     ///\n"); 
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(file);
}

void regravarCampo(Produto* pro){
    int validaDig;
    int validaOp;
    char opcao;
    FILE* file;
    Produto* prod; // Variável para armazenar o produto a ser alterado.
    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "r+b");
   
    printf("///                                                                   ///\n");
    printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Digite 'a' para alterar a validade                   ///\n");
    printf("///            - Digite 'b' para alterar a descrição                  ///\n");
    printf("///            - Digite 'c' para alterar o local                      ///\n");
    printf("///            - Digite 'd' para alterar a quantidade                 ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            - Informe a sua opção: ");
        scanf("%[^\n]", &opcao);
        getchar();

        validaDig = testeDigito(opcao);
        validaOp = validaOpcaoLetrasAD(opcao);
        
        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);
    printf("///                                                                   ///\n");

    if(opcao == 'A' || opcao == 'a'){
        char* dataValidade;
        dataValidade = telaAlterarValidade();
        while(fread(prod, sizeof(Produto), 1, file)) {  
            if(!strcmp(pro->codBarras, prod->codBarras) && !strcmp(pro->dataValidade, prod->dataValidade) && strcmp(prod->status, "x")){    
                strcpy(prod->dataValidade, dataValidade);
                fseek(file, -1*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, file);
                break;
            }
        }
        free(dataValidade);
        printf("///                                                                   ///\n");
        printf("///            A Data de Validade do produto foi alterada!            ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'B' || opcao == 'b'){
        char* nomeItem;
        nomeItem = telaAlterarDesc();
        while(fread(prod, sizeof(Produto), 1, file)) {   
            if(!strcmp(pro->codBarras, prod->codBarras) && !strcmp(pro->dataValidade, prod->dataValidade) && strcmp(prod->status, "x")){   
                strcpy(prod->nomeItem, nomeItem);
                fseek(file, -1*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, file);
                break;
            }
        }
        free(nomeItem);
        printf("///                                                                   ///\n");
        printf("///            A Descrição do produto foi alterada!                   ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'C' || opcao == 'c'){
        char* local;
        local = telaAlterarLocal();
        while(fread(prod, sizeof(Produto), 1, file)) {      
            if(!strcmp(pro->codBarras, prod->codBarras) && !strcmp(pro->dataValidade, prod->dataValidade) && strcmp(prod->status, "x")){
                strcpy(prod->local, local);
                fseek(file, -1*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, file);
                break;
            }
        }
        free(local);
        printf("///                                                                   ///\n");
        printf("///            O local de armazenamento do produto foi alterado!      ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'D' || opcao == 'd'){
        char* quant;
        quant = telaAlterarQuant();
        int quantidade;
        quantidade = converteCharParaInt(quant);
        while(fread(prod, sizeof(Produto), 1, file)) {   
            if(!strcmp(pro->codBarras, prod->codBarras) && !strcmp(pro->dataValidade, prod->dataValidade) && strcmp(prod->status, "x")){
                prod->quant = quantidade;
                fseek(file, -1*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, file);
                break;
            }
        }
        free(quant);
        printf("///                                                                   ///\n");
        printf("///            A quantidade do produto foi alterada!                  ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(file);   
}

void alterarProduto(void){
    int validaDig;
    int validaOp;
    char decisao;
    Produto* pro;
    ChaveP* key;

    key = telaAlterarProduto();
    pro = pegarProdutoPeloCod(key);

    if(pro == NULL){
        exibeProduto(pro);
    }else{
        exibeProduto(pro);

        do{
            printf("///          - Deseja alterar todos os items da compra (S/N) ");
            scanf("%[^\n]", &decisao);
            getchar();

            validaDig = testeDigito(decisao);
            validaOp = validaOpcao(decisao);
            
            if(!validaOp || validaDig){
                printf("///            Opcão inválida, tente novamente!\n");
            }
        }while(!validaOp || validaDig);

        if(decisao == 'S' || decisao == 's'){
            regravarProduto(pro);
            free(key);
            free(pro);

        }else if(decisao == 'N' || decisao == 'n'){
            regravarCampo(pro);
            free(key);
            free(pro);
        }
    }
    
}

// SEÇÃO RELACIONADA À LISTAGEM ________________________________________________________________________________

void listarProdutos(void){
    FILE* fp;
    Produto* pro;

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
    printf("///          = = = = = = MÓDULO LISTAR PRODUTOS: = = = = = =          ///\n");
    printf("///                                                                   ///\n");


    pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(fread(pro, sizeof(Produto), 1, fp)) {
        exibeProduto(pro);
    
    }
    fclose(fp);

}
