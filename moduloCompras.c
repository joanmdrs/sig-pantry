#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"
#include "moduloUtil.h"

typedef struct compra Compra;

struct compra {
    long int codCompra;
    char dataCompra[11];
    char horaCompra[9];
    int quant;
    double valor;
    char status;
    struct compra *prox;
};

typedef struct item Item;

struct item {
    long int codCompra;
    char descricao[51];
    int quant;
    double valor;
};

void gravarCompra(Compra* com){
    FILE* file;
    file = fopen("compras.dat", "ab");
    fwrite(com, sizeof(Compra), 1, file);
    fclose(file);
}

void gravarItem(Item* item){
    FILE* file;
    file = fopen("itens.dat", "ab");
    fwrite(item, sizeof(Item), 1, file);
    fclose(file);
}

long int geraCodCompra(void){

    FILE* fc;
    fc = fopen("compras.dat", "rb");

    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));

    long int codCompra;

    codCompra = geraNF();

    while(fread(com, sizeof(Compra), 1, fc)) {
        if ((com->codCompra == codCompra)) {
            codCompra = geraNF();
        }
    }
    fclose(fc);
    free(com);

    return codCompra;
}

long int preencheCodCompra(void){
    int validaDig;
    int validaNull;
    char codCompra[9];
    long int codigo;

    do{
        printf("///            - Código da compra: ");
        scanf("%[^\n]", codCompra);
        getchar();

        validaDig = testeDigitosNumericos(codCompra);
        validaNull = verificaNulo(codCompra);
        if(validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}
	}while(validaDig || validaNull);

    codigo = atoi(codCompra);
    return codigo;
}

char* preencheDataCompra(void){
    
    int validaData;
    int validaDig;
    int validaNull;

    char* dataCompra;
    dataCompra = (char*) malloc(11*sizeof(char));

    do{
        printf("///            - Data Compra (dd/mm/aaaa): ");
        scanf("%[^\n]", dataCompra);
        getchar();
    
        validaData = testaData(dataCompra);
        validaDig = testeDigitosNumericosData(dataCompra);
        validaNull = verificaNulo(dataCompra);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);


    char* dataAux;
    dataAux = dataInvertida(dataCompra);
    free(dataCompra);
    return dataAux;
}

char* preencheHoraCompra(void){
    int validaHora;
    int validaDig;
    int validaNull;

    char* horaCompra;
    horaCompra = (char*) malloc(9*sizeof(char));

    do{
        printf("///            - Horário Compra (hh:mm:ss): ");
        scanf("%[^\n]", horaCompra);
        getchar();
    
        validaHora = testaHora(horaCompra);
        validaDig = testeDigitosNumericosHora(horaCompra);
        validaNull = verificaNulo(horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return horaCompra;
}

char* preencheQuantCompra(void){
    int validaDig;
    int validaNull;
    char* quantC;
    quantC = (char*) malloc(20*sizeof(char));

    do{
        printf("///            - Quant. Itens da compra: ");
        scanf("%[^\n]", quantC);
        getchar();
    
        validaDig = testeDigitosNumericos(quantC);
        validaNull = verificaNulo(quantC);  

        if(validaDig || validaNull){
            printf("///            Quantidade inválida, tente novamente !\n");
        }
    }while(validaDig || validaNull);

    return quantC;
}

double preencheValorCompra(void){
    int validaDig;
    char valor[10];
    double valorCompra = 0.0;

    do{
        printf("///            - Valor da compra R$ ");
        scanf("%s", valor);
        getchar();
        
        validaDig = testeDigitosNumericosValorFlutuante(valor);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig);

    valorCompra = converteCharParaDouble(valor);
    return valorCompra;
}

void mostraCompras(Compra* com){
    printf("///         %ld\t", com->codCompra);

    char* data = dataReinvertida(com->dataCompra);
    strcpy(com->dataCompra, data); 
    free(data);

    printf("%s\t", com->dataCompra);
    printf("%s\t", com->horaCompra);
    printf("%d\t", com->quant);
    printf("R$%.2f\t\t", com->valor);
    if(com->status == 'x'){
        printf("%s\n", "Excluída");
    }else if(com->status == 'Y'){
        printf("%s\n", "Disponível");
    }
}

void exibirCompra(Compra* com){

    if(com == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            Não existem compras cadastradas com o CÓDIGO           ///\n");  
        printf("///            informado.                                             ///\n");    
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        exibeTecleEnter();

    } else {
        printf("///        ___________________________________________________        \n");
        printf("///                                                                   \n");
        printf("///              Código da compra: %ld \n",com->codCompra);

        char* data = dataReinvertida(com->dataCompra);
        strcpy(com->dataCompra, data); 
        free(data);
        
        printf("///                Data da compra: %s \n", com->dataCompra);
        printf("///             Horário da compra: %s \n", com->horaCompra);
        printf("///                 Qtd. produtos: %d \n", com->quant);
        printf("///                   Valor total: R$ %.2f \n", com->valor);
        printf("///       ___________________________________________________         \n");
        printf("///                                                                   \n");
    }
}

void exibirItem(Item* item){
    printf("///%23s\t", item->descricao);
    printf("%d\t", item->quant);
    printf("R$ %.2f\n", item->valor);
}

char menuCompras(void){
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
    printf("///            COMPRAS:                                               ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Cadastrar compra                                   ///\n");
    printf("///            2 - Pesquisar compra                                   ///\n");
    printf("///            3 - Excluir compra                                     ///\n");
    printf("///            4 - Alterar compra                                     ///\n");
    printf("///            5 - Listar compras                                     ///\n");
    printf("///            6 - Lixeira                                            ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    do{
        printf("Informe a sua opcao : ");
        scanf("%[^\n]", &opcao);
        getchar();

        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 6); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");
        }
    }while(!validaOp || !validaOpM);

	return opcao;
}

// SEÇÃO RELACIONADA AO CADASTRO _______________________________________________________________________________

void cadastrarCompra(void){

    double valorCompra = 0.0;

    limpaTela();
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIG-PANTRY - Controle de Despensa   * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO CADASTRAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    FILE* fp;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));
    Produto* pro;
    Produto* proe;
    Item* item;

    long int codCompra = geraCodCompra(); // Gerando o codigo da compra
    printf("///            - Código da compra: %ld \n", codCompra);
    com->codCompra = codCompra;

    char* dataCompra = retornaData();
    strcpy(com->dataCompra, dataCompra); // Pegando a data da compra automaticamente
    free(dataCompra);
    char* data = dataReinvertida(com->dataCompra);
    printf("///            - Data da compra: %s \n", data);

    char* horaCompra = retornaHora();
    strcpy(com->horaCompra, horaCompra); // Pegando a hora da compra automaticamente
    free(horaCompra);
    printf("///            - Horário da compra: %s \n", com->horaCompra);

    char* quant = preencheQuantCompra();
    int quantidade = converteCharParaInt(quant);
    com->quant = quantidade; // Preenchendo a quantidade de itens da compra

    com->status = 'Y'; 

    com->prox = NULL;

    for(int i = 0; i < quantidade; i++){

        fp = fopen("produtos.dat", "r+b");
        pro = (Produto*) malloc(sizeof(Produto));
        proe = (Produto*) malloc(sizeof(Produto));
        item = (Item*) malloc(sizeof(Item));

        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

        item->codCompra = com->codCompra;

        char* codBarras = preencheCodBarras();
        strcpy(pro->codBarras, codBarras); // Preenchendo o código de barras
        free(codBarras);

        char* dataValidade = preencheDataValidade();
        strcpy(pro->dataValidade, dataValidade); // Preenchendo a data de validade
        free(dataValidade);

        double preco = 0.0;
        int achou = 0;
        while(fread(proe, sizeof(Produto), 1, fp)) {
            if (!strcmp(proe->codBarras, pro->codBarras) && !strcmp(proe->dataValidade, pro->dataValidade) && strcmp(proe->status, "x")) {
                achou = 1;
                printf("///            - Descrição do Item: %s\n", proe->nomeItem);
                printf("///            - Local: %s\n", proe->local);

                char* quantP = preencheQuantPro();
                int quantidadeP = converteCharParaInt(quantP);

                preco = preenchePrecoItem();
                proe->quant += quantidadeP;
                proe->preco = preco;
                valorCompra += (quantidadeP * preco);

                strcpy(item->descricao, proe->nomeItem);
                item->quant = quantidadeP;
                item->valor = preco;
                gravarItem(item);
                free(item);
                fseek(fp, -1*sizeof(Produto), SEEK_CUR);
                fwrite(proe, sizeof(Produto), 1, fp);
                free(pro);
                break;
            }
        }
        fclose(fp);
        free(proe);

        if (achou == 0){
            char* nomeItem = preencheDesc();
            strcpy(pro->nomeItem, nomeItem); // Preenchendo a descrição
            strcpy(item->descricao, nomeItem);
            free(nomeItem);

            char* local = preencheLocal();
            strcpy(pro->local, local); // Preenchendo o local
            free(local);

            char* quantP = preencheQuantPro();
            int quantidadeP = converteCharParaInt(quantP);
            pro->quant = quantidadeP; // Preenchendo a quantidade
            item->quant = quantidadeP;

            preco = preenchePrecoItem();
            pro->preco = preco;
            item->valor = preco;
            valorCompra += (quantidadeP * preco);

            strcpy(pro->status, "Y");
            pro->prox = NULL;

            gravarItem(item);
            gravarProduto(pro);
            free(pro);
            free(item);
        }

    } 
    com->valor = valorCompra; // Preenchendo o valor da compra
    gravarCompra(com);
    printf("///        ___________________________________________________        \n");
    printf("///                                                                   \n");
    printf("///                  Compra cadastrada com sucesso !                  \n");
    exibirCompra(com);
    exibeTecleEnter();
    free(com);
    free(data);
}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

long int telaPesquisarCompra(void){

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIG-PANTRY - Controle de Despensa   * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO PESQUISAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");
 
    long int codigo;
    codigo = preencheCodCompra();
    return codigo;
}

Compra* pegarCompra(long int codigo){

    FILE* file;
    Compra* com;

    com = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "rb");

    while(fread(com, sizeof(Compra), 1, file)){
        if(com->codCompra == codigo && com->status != 'x'){
            fclose(file);
            return com;
        }
    }
    fclose(file);
    return NULL;
}

void pesquisarCompra(void){
    FILE* fi;
    Item* item;
    item = (Item*) malloc(sizeof(Item));
    Compra* com;
    long int codigo;
    codigo = telaPesquisarCompra();
    com = pegarCompra(codigo);
    exibirCompra(com);
    fi = fopen("itens.dat", "rb");
    if(com != NULL){ 
        printf("///        = = = = = = = = = LISTA DE ITENS = = = = = = = = =          \n");
        printf("///\n");
        printf("///                Produto:    Qtd.:    Preço:\n");
        printf("///\n");
        while(fread(item, sizeof(Item), 1, fi)){
            if(com->codCompra == item->codCompra){
                exibirItem(item);
            }
        }
        printf("///\n");
        exibeTecleEnter();
    }
    fclose(fi);
    free(item);
    free(com);

}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

long int telaExcluirCompra(void){

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
    printf("///            = = = = =  MÓDULO EXCLUIR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");

    long int codigo;
    codigo = preencheCodCompra();
    return codigo;
}

void excluirCompraLog(Compra* com){
    char confirma;
    FILE* file;
    Compra* comp;
    comp = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "r+b");

    if(com == NULL){
        exibirCompra(com);

    } else{
        confirma = confirmaExclusao();

        if (confirma == 'S' || confirma == 's'){
            while(fread(comp, sizeof(Compra), 1, file)){
                if(comp->codCompra == com->codCompra && comp->status != 'x'){
                    comp->status = 'x';
                    fseek(file, -1*sizeof(Compra), SEEK_CUR);
                    fwrite(comp, sizeof(Compra), 1, file);   
                    break;
                }
            }
            fclose(file);
        
            printf("///                                                                   ///\n");
            printf("///            Compra excluída com sucesso!                           ///\n"); 
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
            fclose(file);
        }
    } 
    fclose(file);
}

void excluirCompra(void){
    Compra* com;
    long int codigo;
    codigo = telaExcluirCompra();
    com = pegarCompra(codigo);
    exibirCompra(com);
    //exibeTecleEnter();
    
    if(com != NULL){
        excluirCompraLog(com);
    }
    free(com);
}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

long int telaAlterarCompra(void){

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
    printf("///            = = = = =  MÓDULO ALTERAR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");

    long int codigo;
    codigo = preencheCodCompra();
    return codigo;
}

char telaEscolha(void){
    int validaDig;
    int validaOp;
    char opcao;

    do{
        printf("///            - Informe a sua opção: ");
        scanf("%[^\n]", &opcao);
        getchar();

        validaDig = testeDigito(opcao);
        validaOp = validaOpcaoLetrasAC(opcao);
        
        if(!validaOp || validaDig){
            printf("///            Opção inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);
    printf("///                                                                   ///\n");
    return opcao;
}

void regravarCompra(Compra* com){

    FILE* file;
    Compra* comp;
    comp = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "r+b");
    char opcao;
   
    printf("///                                                                   ///\n");
    printf("///           ESCOLHA O QUER ALTERAR:                                 ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Digite 'a' para alterar a data da compra             ///\n");
    printf("///            - Digite 'b' para alterar a hora da compra             ///\n");
    printf("///            - Digite 'c' para alterar o valor da compra            ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    opcao = telaEscolha();

    if(opcao == 'a'){
        char* dataCompra;
        dataCompra = preencheDataCompra();

        while(fread(comp, sizeof(Compra), 1, file)){
            if(comp->codCompra == com->codCompra && comp->status != 'x'){
                strcpy(comp->dataCompra, dataCompra);
                fseek(file, -1*sizeof(Compra), SEEK_CUR);
                fwrite(comp, sizeof(Compra), 1, file);
                break;
            }
        }
        fclose(file);
        free(dataCompra);
        free(comp);
        printf("///                                                                   ///\n");
        printf("///            A data da compra foi alterada!                         ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'b'){
        char* horaCompra;
        horaCompra = preencheHoraCompra();
        
        while(fread(comp, sizeof(Compra), 1, file)){
            if(comp->codCompra == com->codCompra && comp->status != 'x'){
                strcpy(comp->horaCompra, horaCompra);
                fseek(file, -1*sizeof(Compra), SEEK_CUR);
                fwrite(comp, sizeof(Compra), 1, file);
                break;
            }
        }
        fclose(file);
        free(horaCompra);
        free(comp);
        printf("///                                                                   ///\n");
        printf("///            A hora da compra foi alterada!                         ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'c'){
        double valorCompra = 0.0;
        valorCompra = preencheValorCompra();

        while(fread(comp, sizeof(Compra), 1, file)){
            if(comp->codCompra == com->codCompra && comp->status != 'x'){
                comp->valor = valorCompra;
                fseek(file, -1*sizeof(Compra), SEEK_CUR);
                fwrite(comp, sizeof(Compra), 1, file);
                break;
            }
        }
        fclose(file);
        free(comp);
        printf("///                                                                   ///\n");
        printf("///            O valor da compra foi alterado!                        ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }
    fclose(file);
}

void alterarCompra(void){
    Compra* com;
    long int codigo;
    codigo = telaAlterarCompra();
    com = pegarCompra(codigo);
    exibirCompra(com);
    //exibeTecleEnter();
    
    if(com != NULL){
        regravarCompra(com);
    }
    free(com);
}

void listarCompras(void){

    limpaTela();
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                                  ///\n");
    printf("///        *********************************************************************************         ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         ///\n");
    printf("///        * * * * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * * * * *         ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         ///\n");
    printf("///        *********************************************************************************         ///\n");
    printf("///        _________________________________________________________________________________         ///\n");
    printf("///                                                                                                  ///\n");
    printf("///        = = = = = = = = = = = = = = =  MÓDULO - LISTAR COMPRAS = = = = = = = = = = = = =          ///\n");
    printf("///\n");
    printf("///         Código:     Data:           Hora:         Qtd.:     Valor:          Status:                 \n");
    printf("///\n");

    FILE* fp;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));
    fp = fopen("compras.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }else{
        while(fread(com, sizeof(Compra), 1, fp)) {
            mostraCompras(com);
        }
        printf("///\n");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    free(com);
    fclose(fp);
}

void excluirCompras(void){
    limpaTela();
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                                  ///\n");
    printf("///        *********************************************************************************         ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         ///\n");
    printf("///        * * * * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * * * * *         ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         ///\n");
    printf("///        *********************************************************************************         ///\n");
    printf("///        _________________________________________________________________________________         ///\n");
    printf("///                                                                                                  ///\n");
    printf("///        = = = = = = = = = = = = = = = = MÓDULO - LIXEIRA = = = = = = = = = = = = = = = =          ///\n");
    printf("///\n");
    printf("///         Código:     Data:           Hora:         Qtd.:     Valor:          Status:                 \n");
    printf("///\n");

    char confirma;
    int cont = 0;
    FILE* original;
    FILE* novo;

    Compra* com;
    Compra* comp;

    com = (Compra*) malloc(sizeof(Compra));
    comp = (Compra*) malloc(sizeof(Compra));

    original = fopen("compras.dat", "rb");

    if(original == NULL){
        exibeErroArquivo();

    }else{
        while(fread(comp, sizeof(Compra), 1, original)) {
            if(comp->status == 'x'){
                mostraCompras(comp);
                cont += 1;
            }
        }
        fclose(original);
        free(comp);
        printf("///\n");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///\n");

        if(cont > 0){
            confirma = confirmaEsvaziarLixeira();

            if(confirma == 'S' || confirma == 's'){
                original = fopen("compras.dat", "rb");
                novo = fopen("novo.dat", "ab");
            
                while(fread(com, sizeof(Compra), 1, original)) {
                    if(com->status == 'Y'){
                        fwrite(com, sizeof(Compra), 1, novo);
                    }
                }
                fclose(original);
                fclose(novo);
                free(com);
                remove("compras.dat");
                rename("novo.dat", "compras.dat");

                telaLixeiraVazia();

            }else if(confirma == 'N' || confirma == 'n'){
                telaLixeiraSemAlteracoes();

            }
        }else{
            telaLixeiraVazia();
        }
    }
}

