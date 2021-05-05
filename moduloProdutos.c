#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloUtil.h"

typedef struct produto Produto;

struct produto {
    char codBarras[14];
    char dataValidade[11];
    char nomeItem[51];
    char local[20];
    int quant;
    double preco;
    char status[2];
    struct produto *prox;
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
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
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
    printf("///            6 - Lixeira                                            ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaI = testeDigito(opcao);
        validaII = validaOpcaoMenu(opcao, 6); 

        if(!validaI || !validaII){
            printf("Opção invalida, tente novamente!\n");
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

void mostraCabecalho(void){
    printf("///\n");
    printf("///          Produto:                 Codigo:          Validade:      Qtd.:    Preço: R$        Local:\n");
    printf("///\n");
}

void mostraProdutosControle(Produto* pro){
    printf("///%23s\t", pro->nomeItem);
    printf("%13s\t", pro->codBarras);
    printf("%10s\t", pro->dataValidade);
    printf("%d\t", pro->quant);
    printf("%.2f\t\t", pro->preco);
    printf("%-15s\t", pro->local);
    if(!strcmp(pro->status, "Y")){
        printf("%s\n", "Disponível");
    }else if(!strcmp(pro->status, "x")){
        printf("%s\n", "Excluído");
    }

}

void mostraProdutos(Produto* pro){
    printf("///          %-25s", pro->nomeItem);
    printf("%13s\t", pro->codBarras);
    printf("%10s\t", pro->dataValidade);
    printf("%d\t", pro->quant);
    printf("%.2f\t\t", pro->preco);
    printf("%-15s\n", pro->local);
}

void exibeProduto(Produto* prod){

    if(prod == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não foi encontrado nenhum produto com os dados           ///\n");  
        printf("///          fornecidos.                                              ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        exibeTecleEnter();

    } else {
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", prod->codBarras);
        printf("///              Data de Validade: %s \n", prod->dataValidade);
        printf("///                     Descrição: %s \n", prod->nomeItem);
        printf("///                         Local: %s \n", prod->local);
        printf("///                    Quantidade: %d \n", prod->quant);
        printf("///                         Preço: R$ %.2f \n", prod->preco);
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");

    }

}

// SEÇÃO RELACIONADA AO CADASTRO ______________________________________________________________________________

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

Produto* telaCadastrarProduto(void){

    limpaTela();
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
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

// ----------------------- Preenchendo o código de barras ----------------------------------

    char* codBarras;
    codBarras = preencheCodBarras();
    strcpy(pro->codBarras, codBarras);
    free(codBarras);

// ----------------------- Preenchendo a data de validade ----------------------------------

    char* dataValidade;
    dataValidade = preencheDataValidade();
    strcpy(pro->dataValidade, dataValidade);
    free(dataValidade);

    int achou = 0;
    while(fread(proe, sizeof(Produto), 1, fp)) {
        if (!strcmp(proe->codBarras, pro->codBarras) && !strcmp(proe->dataValidade, pro->dataValidade)) {
            achou = 1;
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
        }
    }

    if (achou == 0){
        // ----------------------- Preenchendo a descrição do produto ------------------------------

        char* nomeItem;
        nomeItem = preencheDesc();
        strcpy(pro->nomeItem, nomeItem);
        free(nomeItem);

        // ----------------------- Preenchendo o local do produto ----------------------------------

        char* local;
        local = preencheLocal();
        strcpy(pro->local, local);
        free(local);

        // ----------------------- Preenchendo a quantidade do produto -----------------------------

        char* quantidade;
        quantidade = preencheQuantPro();
        pro->quant = converteCharParaInt(quantidade);
        free(quantidade);

        // ------------------------ Preenchendo o preço do produto ----------------------------------

        pro->preco = preenchePrecoItem();

        // --------------------------- Definindo o status do produto -----------------------------------

        strcpy(pro->status, "Y");
        pro->prox = NULL;

        // ---------------------------------------------------------------------------------------

        printf("///        ___________________________________________________        \n");
        printf("///                                                                   \n");
        printf("///                  Produto cadastrado com sucesso !                 \n");
        exibeProduto(pro);
        exibeTecleEnter();
        return pro;
    }

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
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                                               ///\n");
    printf("///        ***********************************************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***********************************************************************************************        ///\n");
    printf("///        _______________________________________________________________________________________________        ///\n");
    printf("///                                                                                                               ///\n");
    printf("///        = = = = = = = = = = = = = = = = = = MÓDULO - PESQUISAR PRODUTO = = = = = = = = = = = = = = = =         ///\n");
    printf("///                                                                                                               ///\n");
    printf("///          a) Pesquisar pelo Código de Barras                                                                   ///\n");
    printf("///          b) Pesquisar pela Descrição                                                                          ///\n");
    printf("///                                                                                                               ///\n");

    do{
        printf("///          Informe o tipo de pesquisa : ");
        scanf("%[^\n]", &tipoPesq);
        getchar();

        validaDig = testeDigito(tipoPesq);

        if(validaDig){
            printf("Opção inválida, tente novamente!\n");
        }
    }while(validaDig);
    printf("///\n");
    return tipoPesq;
}

void pesquisarProduto(void){
    FILE* fp;
    Produto* pro;
    pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");

    char opcao;
    char* cod;
    char* desc;
    opcao = telaTipoPesquisa();

    if(opcao == 'a'){
        if (fp == NULL) {
            exibeErroArquivo();
        }else{
            cod = preencheCodBarras();
            printf("///        _______________________________________________________________________________________________\n");
            mostraCabecalho();
            while(fread(pro, sizeof(Produto), 1, fp)) {
                if(!strcmp(pro->codBarras, cod) && strcmp(pro->status,"x")){
                    mostraProdutos(pro);
                }
            }
            printf("///\n");
            printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
            printf("                                      >>> Tecle <ENTER> para continuar...\n");
            getchar();
            free(cod);
        } 

    }else if(opcao == 'b'){
        if (fp == NULL) {
            exibeErroArquivo();
        }else{
            desc = preencheDesc();
            printf("///        _______________________________________________________________________________________________\n");
            mostraCabecalho();
            while(fread(pro, sizeof(Produto), 1, fp)) {
                if(!strcmp(pro->nomeItem, desc) && strcmp(pro->status,"x")){
                    mostraProdutos(pro);
                }
            }
            printf("///\n");
            printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
            printf("                                      >>> Tecle <ENTER> para continuar...\n");
            getchar();
            free(desc);
        }  
    }
    free(pro);
    fclose(fp);
}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

ChaveP* telaExcluirProduto(void){

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
    printf("///            = = = = = MÓDULO EXCLUIR PRODUTO: = = = = =            ///\n");
    printf("///                                                                   ///\n");

    ChaveP* key;
    key = (ChaveP*) malloc(sizeof(ChaveP));

    char* codBarras;
    codBarras = preencheCodBarras();
    strcpy(key->codBarras, codBarras);
    free(codBarras);

    char* dataValidade;
    dataValidade = preencheDataValidade();
    strcpy(key->dataValidade, dataValidade);
    free(dataValidade);

    return key;
}

void excluirProdutoLogicamente(Produto* pro){
    FILE* file;
    Produto* prod;

    prod = (Produto*) malloc(sizeof(Produto));
    file = fopen("produtos.dat", "r+b");

    if(pro == NULL){
        exibeProduto(pro);

    } else{
        exibeProduto(pro);
        printf("///                                                                   ///\n");
        
        char confirma;
        confirma = confirmaExclusao();

        if (confirma == 'S' || confirma == 's'){
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
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        } else if (confirma == 'N' || confirma == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operação cancelada!                                    ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
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

// SEÇÃO RELACIONADA À ALTERAÇÃO _______________________________________________________________________________

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
        printf("///            - b) Nova Descrição: ");
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
        printf("///            - d) Nova Quantidade: ");
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

double telaAlterarPreco(void){

    int validaDig;
    int validaNull;

    double precoD = 0.0;
    char* precoC;
    precoC = (char*) malloc(10*sizeof(char));

    do{
        printf("///            - Novo preço: R$ ");
        scanf("%s", precoC);
        getchar();
        
        validaDig = testeDigitosNumericosValorFlutuante(precoC);
        validaNull = verificaNulo(precoC);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    precoD = converteCharParaDouble(precoC);
    free(precoC);
    return precoD;
}

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
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
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
    Produto* pro;
    pro = (Produto*) malloc(sizeof(Produto));

    printf("///                                                                   ///\n");
    printf("///           INFORME OS NOVOS VALORES DO PRODUTO:                    ///\n");
    printf("///                                                                   ///\n");

    char* dataValidade;
    dataValidade = telaAlterarValidade();
    strcpy(pro->dataValidade, dataValidade);
    free(dataValidade);

    char* nomeItem;
    nomeItem = telaAlterarDesc();
    strcpy(pro->nomeItem, nomeItem);
    free(nomeItem);
    
    char* local;
    local = telaAlterarLocal();
    strcpy(pro->local, local);
    free(local);

    char* quantidade;
    quantidade = telaAlterarQuant();
    pro->quant = converteCharParaInt(quantidade);
    free(quantidade);

    pro->preco = telaAlterarPreco();

    pro->prox = NULL;

    return pro;   
}

void regravarProduto(Produto* pro){ 
    
    FILE* file;
    Produto* prod; // Variável para armazenar o produto a ser alterado.
    Produto* proe; // Variável que armazena os novos valores do produto.
    prod = (Produto*) malloc(sizeof(Produto));
    proe = telaAlterarTudo();
    file = fopen("produtos.dat", "r+b");
    printf("///                                                                    ///\n");

    char confirma;
    confirma = confirmaAlteracao();

    if(confirma == 'S' || confirma == 's'){
        while(fread(prod, sizeof(Produto), 1, file)){
            if(!strcmp(pro->codBarras, pro->codBarras) && !strcmp(pro->dataValidade, pro->dataValidade) && strcmp(prod->status, "x")){
                strcpy(prod->dataValidade, proe->dataValidade);
                strcpy(prod->nomeItem, proe->nomeItem);
                strcpy(prod->local, proe->local);
                prod->quant = proe->quant;
                prod->preco = proe->preco;
                prod->prox = proe->prox;
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
    printf("///           ESCOLHA O CAMPO A ALTERAR:                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Digite 'a' para alterar a validade                   ///\n");
    printf("///            - Digite 'b' para alterar a descrição                  ///\n");
    printf("///            - Digite 'c' para alterar o local                      ///\n");
    printf("///            - Digite 'd' para alterar a quantidade                 ///\n");
    printf("///            - Digite 'e' para alterar o preço                      ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            - Informe a sua opção: ");
        scanf("%[^\n]", &opcao);
        getchar();

        validaDig = testeDigito(opcao);
        validaOp = validaOpcaoLetrasAE(opcao);
        
        if(!validaOp || validaDig){
            printf("///            Opção inválida, tente novamente!\n");
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

    }else if(opcao == 'E' || opcao == 'e'){
        double preco;
        preco = telaAlterarPreco();
        while(fread(prod, sizeof(Produto), 1, file)) {   
            if(!strcmp(pro->codBarras, prod->codBarras) && !strcmp(pro->dataValidade, prod->dataValidade) && strcmp(prod->status, "x")){
                prod->preco = preco;
                fseek(file, -1*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, file);
                break;
            }
        }
        printf("///                                                                   ///\n");
        printf("///            O preço do produto foi alterado!                       ///\n");
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
            printf("///          - Deseja alterar todos os campos do produto (S/N) ");
            scanf("%[^\n]", &decisao);
            getchar();

            validaDig = testeDigito(decisao);
            validaOp = validaOpcao(decisao);
            
            if(!validaOp || validaDig){
                printf("///            Opção inválida, tente novamente!\n");
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
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                                                        ///\n");
    printf("///        *********************************************************************************************************       ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *       ///\n");
    printf("///        * * * * * * * * * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * * * * * * * *       ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *       ///\n");
    printf("///        *********************************************************************************************************       ///\n");
    printf("///        _________________________________________________________________________________________________________       ///\n");
    printf("///                                                                                                                        ///\n");
    printf("///        = = = = = = = = = = = = = = = = = = = = MÓDULO - LISTAR PRODUTOS = = = = = = = = = = = = = = = = = = = =        ///\n");
    printf("///\n");
    printf("///               Produto:      Código:         Validade:      Qtd.:    Preço: R$       Local:          Status:               \n");
    printf("///\n");

    pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }else{
        while(fread(pro, sizeof(Produto), 1, fp)) {
            mostraProdutosControle(pro);
        }
        printf("///\n");
        printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("                                         >>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    free(pro);
    fclose(fp);

}

void excluirProdutos(void){

    limpaTela();
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                                                        ///\n");
    printf("///        *********************************************************************************************************       ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *       ///\n");
    printf("///        * * * * * * * * * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * * * * * * * *       ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *       ///\n");
    printf("///        *********************************************************************************************************       ///\n");
    printf("///        _________________________________________________________________________________________________________       ///\n");
    printf("///                                                                                                                        ///\n");
    printf("///        = = = = = = = = = = = = = = = = = = = = = = MÓDULO - LIXEIRA = = = = = = = = = = = = = = = = = = = = = =        ///\n");
    printf("///\n");
    printf("///               Produto:      Código:         Validade:      Qtd.:    Preço: R$       Local:          Status:              \n");
    printf("///\n");

    char confirma;
    int cont = 0;
    FILE* original;
    FILE* novo;

    Produto* pro;
    Produto* proe;
    proe = (Produto*) malloc(sizeof(Produto));
    pro = (Produto*) malloc(sizeof(Produto));

    original = fopen("produtos.dat", "rb");

    if(original == NULL){
        exibeErroArquivo();

    }else{
        while(fread(proe, sizeof(Produto), 1, original)) {
            if(!strcmp(proe->status,"x")){
                mostraProdutosControle(proe);
                cont += 1;
            }
        }
        fclose(original);
        free(proe);
        printf("///\n");
        printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///\n");

        if(cont > 0){
            confirma = confirmaEsvaziarLixeira();

            if(confirma == 'S' || confirma == 's'){
                original = fopen("produtos.dat", "rb");
                novo = fopen("novo.dat", "ab");
            
                while(fread(pro, sizeof(Produto), 1, original)) {
                    if(!strcmp(pro->status, "Y")){
                        fwrite(pro, sizeof(Produto), 1, novo);
                    }
                }
                fclose(original);
                fclose(novo);
                free(pro);
                remove("produtos.dat");
                rename("novo.dat", "produtos.dat");

                telaLixeiraVazia();

            }else if(confirma == 'N' || confirma == 'n'){
                telaLixeiraSemAlteracoes();

            }
        }else{
            telaLixeiraVazia();
        }
    }
}


