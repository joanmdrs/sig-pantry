#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloUtil.h"
#include "moduloProdutos.h"
#include "moduloCompras.h"

char menuRelatorios(void){
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
    printf("///            RELATÓRIOS:                                            ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - PRODUTOS                                           ///\n");
    printf("///            2 - COMPRAS                                            ///\n");
    printf("///            3 - CONSUMOS                                           ///\n");
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

// SEÇÃO RELACIONADA AOS RELATÓRIOS DE PRODUTOS ________________________________________________________

char menuRelatorioProdutos(void){

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
    printf("///            RELATÓRIOS - PRODUTOS:                                 ///\n");    
    printf("///                                                                   ///\n");
    printf("///            1 - Produtos vencidos                                  ///\n");
    printf("///            2 - Produtos à vencer                                  ///\n");
    printf("///            3 - Produtos em ordem                                  ///\n");
    printf("///            4 - Produtos por local                                 ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 4); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

void exibeRelProd(Produto* pro){
    printf("%26s\t", pro->nomeItem);
    printf("%13s\t", pro->codBarras);
    printf("%10s\t", pro->dataValidade);
    printf("%d\t", pro->quant);
    printf("%s\n", pro->local);
}

void exibirProdutos(Produto* pro){
    printf("                Produto  : %s\n", pro->nomeItem);
    printf("                Código   : %s\n", pro->codBarras);
    printf("                Validade : %s\n", pro->dataValidade);
    printf("                Local    : %s\n", pro->local);
    printf("                Quant.   : %d\n", pro->quant);
    printf("              _____________________________________________\n");
    printf("\n");

}

void exibirLista(Produto* aux){

    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                             ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        _____________________________________________________________________________        ///\n");
    printf("///                                                                                             ///\n");
    printf("///        = = = = = = = = = = = RELATÓRIO - PRODUTOS ORDENADOS = = = = = = = = = = = =         ///\n\n");
    printf("                  Produto:      Código:         Validade:      Qtd.:    Local:\n\n");

    while (aux != NULL){
        printf("%26s\t", aux->nomeItem);
        printf("%13s\t", aux->codBarras);
        printf("%10s\t", aux->dataValidade);
        printf("%d\t", aux->quant);
        printf("%s\n", aux->local);
        aux = aux->prox;
    }
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void apagarLista(Produto **lista){
    Produto *pro;
    
    while (*lista != NULL){
   	    pro = *lista;
        *lista = (*lista)->prox;
        free(pro);
    }   
}

void relProdVencidos(void){
    FILE *fp;
    Produto* pro;
    int vencido;

    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                             ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        _____________________________________________________________________________        ///\n");
    printf("///                                                                                             ///\n");
    printf("///        = = = = = = = = = = = = RELATÓRIO - PRODUTOS VENCIDOS = = = = = = = = = = = =        ///\n\n");
    printf("                  Produto:      Código:         Validade:      Qtd.:    Local:\n\n");

    pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }else{
        while(fread(pro, sizeof(Produto), 1, fp)) {
            vencido = itensVencidos(pro->dataValidade);
            if(vencido == 1){
                exibeRelProd(pro);
            }
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);

}

void relProdParaVencer(void){
    FILE *fp;
    Produto* pro;
    int vencer;

    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                             ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        _____________________________________________________________________________        ///\n");
    printf("///                                                                                             ///\n");
    printf("///        = = = = = = = = = = = = RELATÓRIO - PRODUTOS À VENCER = = = = = = = = = = = =        ///\n\n");
    printf("                  Produto:      Código:         Validade:      Qtd.:    Local:\n\n");

    pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }else{
        while(fread(pro, sizeof(Produto), 1, fp)) {
            vencer = itensParaVencer(pro->dataValidade);
            if(vencer == 1){
                exibeRelProd(pro);
            }
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}

void relProdOrdenados(Produto **lista){

    FILE *fp;
    Produto* pro;

    apagarLista(&(*lista));
    *lista = NULL;

    fp = fopen("produtos.dat","rb");

    if (fp == NULL){
        exibeErroArquivo();

    }else{

        pro = (Produto*) malloc(sizeof(Produto));
        while (fread(pro, sizeof(Produto), 1, fp)){

            if ((*lista == NULL) || (strcmp(pro->nomeItem, (*lista)->nomeItem) < 0)) {
                pro->prox = *lista;
                *lista = pro;

            }else{
                Produto* ant = *lista;
                Produto* atu = (*lista)->prox;
                
                while ((atu != NULL) && (strcmp(atu->nomeItem, pro->nomeItem) < 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = pro;
                pro->prox = atu;
            }
            pro = (Produto*) malloc(sizeof(Produto));
        }
        free(pro);
        fclose(fp);
    }
}

void relProdLocal(void){
    FILE *fp;
    Produto* pro;

    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                             ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * *   SIG-PANTRY - Controle de Despensa   * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        _____________________________________________________________________________        ///\n");
    printf("///                                                                                             ///\n");
    printf("///        = = = = = = = = = = = = RELATÓRIO - PRODUTOS POR LOCAL = = = = = = = = = = = =       ///\n");
    printf("///                                                                                             ///\n");

    char* local;
    local = preencheLocal();

    printf("///        _____________________________________________________________________________        ///\n\n");
    printf("                  Produto:      Código:         Validade:      Qtd.:    Local:\n\n");

    pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }else{
        while(fread(pro, sizeof(Produto), 1, fp)) {
            if(!strcmp(pro->local, local)){
                exibeRelProd(pro);
            }
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    free(local);
    fclose(fp);
}

// SEÇÃO RELACIONADA AOS RELATÓRIOS DE COMPRAS _________________________________________________________

char menuRelatorioCompras(void){
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
    printf("///            RELATÓRIOS - COMPRAS:                                  ///\n");    
    printf("///                                                                   ///\n");
    printf("///            1 - Compras Diárias                                    ///\n");
    printf("///            2 - Compras Mensais                                    ///\n");
    printf("///            3 - Compras Anuais                                     ///\n");
    printf("///            4 - Compras: Ordem por valor                           ///\n");
    printf("///            5 - Compras: Ordem cronológica                         ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    
    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 5); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

void exibeRelCompra(Compra* com){
    printf("               %ld\t\t", com->codCompra);
    printf("%s\t", com->dataCompra);
    printf("%s\t", com->horaCompra);
    printf("%d\t", com->quant);
    printf("%.2f\n", com->valor);
}

void exibirListaOrdemValor(Compra* aux){
    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                     ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        _____________________________________________________________________        ///\n");
    printf("///                                                                                     ///\n");
    printf("///           = = = = = = = RELATÓRIO - ORDEM CRESCENTE - VALORES = = = = = = =         ///\n");
    printf("///                                                                                     ///\n");
    printf("               Código:          Data:           Hora:         Qtd.:    Valor: R$         \n\n");

    while (aux != NULL){
        printf("               %ld\t\t", aux->codCompra);
        printf("%s\t", aux->dataCompra);
        printf("%s\t", aux->horaCompra);
        printf("%d\t", aux->quant);
        printf("%.2f\n", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exibirListaOrdemCrono(Compra* aux){

    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                     ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        _____________________________________________________________________        ///\n");
    printf("///                                                                                     ///\n");
    printf("///           = = = = = = = = = RELATÓRIO - ORDEM CRONOLÓGICA = = = = = = = = =         ///\n");
    printf("///                                                                                     ///\n");
    printf("               Código:          Data:           Hora:         Qtd.:    Valor: R$         \n\n");

    while (aux != NULL){
        printf("               %ld\t\t", aux->codCompra);
        printf("%s\t", aux->dataCompra);
        printf("%s\t", aux->horaCompra);
        printf("%d\t", aux->quant);
        printf("%.2f\n", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void apagarListaCompra(Compra **lista){
    Compra *com;
    
    while (*lista != NULL){
   	    com = *lista;
        *lista = (*lista)->prox;
        free(com);
    }
}

void relComprasDiarias(void){
    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                     ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        _____________________________________________________________________        ///\n");
    printf("///                                                                                     ///\n");
    printf("///            = = = = = = = = RELATÓRIO - COMPRAS DIÁRIAS = = = = = = = =              ///\n");
    printf("///                                                                                     ///\n");
    char* data;
    data = preencheDataCompra();
    printf("           _____________________________________________________________________           \n\n");
    printf("               Código:          Data:           Hora:         Qtd.:    Valor: R$           \n\n");
    double total = 0.0;
    int cont = 0;

    FILE* fp;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));
    fp = fopen("compras.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }

    while(fread(com, sizeof(Compra), 1, fp)) {
        if(strcmp(com->dataCompra, data) == 0){
            total = total + com->valor;
            cont += 1;
            exibeRelCompra(com);
        
        }        
    }
    if(cont == 0){
        printf("           _____________________________________________________________________           \n\n");
        printf("              Não há registro de compras para o dia informado                              \n");
        printf("           _____________________________________________________________________           \n\n");

    }else{
        printf("           _____________________________________________________________________           \n\n");
        printf("              Total Gasto: R$ %.2f \n", total);
        printf("              Quantidade de compras: %d \n", cont);
    }
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    free(data);
    fclose(fp);
    
}

void relComprasMensais(void){
    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                     ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        _____________________________________________________________________        ///\n");
    printf("///                                                                                     ///\n");
    printf("///            = = = = = = = = RELATÓRIO - COMPRAS MENSAIS = = = = = = = =              ///\n");
    printf("///                                                                                     ///\n");
    char* recorta;
    char* data;
    data = preencheMesEAno();
    printf("           _____________________________________________________________________           \n\n");
    printf("               Código:          Data:           Hora:         Qtd.:    Valor: R$           \n\n");
    double total = 0.0;
    int cont = 0;

    FILE* fp;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));
    fp = fopen("compras.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }

    while(fread(com, sizeof(Compra), 1, fp)) {
        recorta = recortaMesEAno(com->dataCompra);
        if(strcmp(recorta, data) == 0){
            total = total + com->valor;
            cont += 1;
            exibeRelCompra(com);
        
        }        
    }
    if(cont == 0){
        printf("           _____________________________________________________________________           \n\n");
        printf("              Não há registro de compras para o mês informado                              \n");
        printf("           _____________________________________________________________________           \n\n");

    }else{
        printf("           _____________________________________________________________________           \n\n");
        printf("              Total Gasto: R$ %.2f \n", total);
        printf("              Quantidade de compras: %d \n", cont);
    }
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    free(data);
    free(recorta);
    fclose(fp);
}

void relComprasAnuais(void){
    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                     ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *********************************************************************        ///\n");
    printf("///        _____________________________________________________________________        ///\n");
    printf("///                                                                                     ///\n");
    printf("///             = = = = = = = = RELATÓRIO - COMPRAS ANUAIS = = = = = = = =              ///\n");
    printf("///                                                                                     ///\n");

    char* recorta;
    char* data;
    data = preencheAno();
    printf("           _____________________________________________________________________           \n\n");
    printf("               Código:          Data:           Hora:         Qtd.:    Valor: R$           \n\n");
    double total = 0.0;
    int cont = 0;

    FILE* fp;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));
    fp = fopen("compras.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }

    while(fread(com, sizeof(Compra), 1, fp)) {
        recorta = recortaAno(com->dataCompra);
        if(strcmp(recorta, data) == 0){
            total = total + com->valor;
            cont += 1;
            exibeRelCompra(com);
        
        }        
    }
    if(cont == 0){
        printf("           _____________________________________________________________________           \n\n");
        printf("              Não há registro de compras para o ano informado                              \n");
        printf("           _____________________________________________________________________           \n\n");

    }else{
        printf("           _____________________________________________________________________           \n\n");
        printf("              Total Gasto: R$ %.2f \n", total);
        printf("              Quantidade de compras: %d \n", cont);
    }
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
    free(data);
    free(recorta);
    fclose(fp);
    
    
}

void relCompOrdemValor(Compra **lista){

    FILE *fp;
    Compra* com;

    apagarListaCompra(&(*lista));
    *lista = NULL;

    fp = fopen("compras.dat","rb");

    if (fp == NULL){
        exibeErroArquivo();

    }else{

        com = (Compra*) malloc(sizeof(Compra));
        while (fread(com, sizeof(Compra), 1, fp)){

            if ((*lista == NULL) || com->valor < (*lista)->valor ) {
                com->prox = *lista;
                *lista = com;

            }else{
                Compra* ant = *lista;
                Compra* atu = (*lista)->prox;
                
                while ((atu != NULL) && atu->valor < com->valor) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = com;
                com->prox = atu;
            }
            com = (Compra*) malloc(sizeof(Compra));
        }
        free(com);
        fclose(fp);
    }
}

void relCompOrdemCrono(Compra **lista){
    FILE *fp;
    Compra* com;

    apagarListaCompra(&(*lista));
    *lista = NULL;

    fp = fopen("compras.dat","rb");

    if (fp == NULL){
        exibeErroArquivo();

    }else{

        com = (Compra*) malloc(sizeof(Compra));
        while (fread(com, sizeof(Compra), 1, fp)){

            if ((*lista == NULL) || (strcmp(com->dataCompra, (*lista)->dataCompra) < 0)) {
                com->prox = *lista;
                *lista = com;

            }else{
                Compra* ant = *lista;
                Compra* atu = (*lista)->prox;
                
                while ((atu != NULL) && (strcmp(atu->dataCompra, com->dataCompra) < 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = com;
                com->prox = atu;
            }
            com = (Compra*) malloc(sizeof(Compra));
        }
        free(com);
        fclose(fp);
    }

}

// SEÇÃO RELACIONADA AOS RELATÓRIOS DE CONSUMOS _________________________________________________________

char menuRelatorioConsumo(void){
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
    printf("///            RELATÓRIOS - CONSUMO:                                  ///\n");    
    printf("///                                                                   ///\n");
    printf("///            1 - Consumos Diários                                   ///\n");
    printf("///            2 - Consumos Mensais                                   ///\n");
    printf("///            3 - Consumos Anuais                                    ///\n");
    printf("///            4 - Consumos: Ordem por valor                          ///\n");
    printf("///            5 - Consumos: Ordem cronológica                        ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opção : ");
        scanf("%[^\n]", &opcao);
        getchar();
        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 5); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

