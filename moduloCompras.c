#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"

typedef struct compra Compra;

struct compra {
    char dataCompra[11];
    char horaCompra[6];
    char valorCompra[10];
    char quantItens[10];
    Produto itens[100];
    char status[12];
};

typedef struct chave Chave;

struct chave{
    char dataCompra[11];
    char horaCompra[6];
};

void gravarCompra(Compra* com){
    FILE* file;

    file = fopen("compras.dat", "ab");

    fwrite(com, sizeof(Compra), 1, file);

    fclose(file);
}

void exibirCompra(Compra* com){

    if(com == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///         Não existem compras cadastradas com a DATA e HORA         ///\n");  
        printf("///         fornecidas.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///             Data da compra: %s \n", com->dataCompra);
        printf("///             Horário da compra: %s \n", com->horaCompra);
        printf("///             Valor da compra: R$ %s \n", com->valorCompra);
        printf("///             Status: %s \n", com->status);
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            LISTA DE ITENS:                                        ///\n");
        printf("///                                                                   ///\n");

        int q = atoi(com->quantItens);

        for (int i = 0; i < q; i++){
            printf("               Item %d \n", i+1);
            printf("///\n");
            printf("///            Código de Barras: %s \n", com->itens[i].codBarras);
            printf("///            Descrição do Item: %s \n", com->itens[i].nomeItem);
            printf("///            Data de Validade: %s \n", com->itens[i].dataValidade);
            printf("///            Local: %s \n", com->itens[i].local);
            printf("///            Status: %s \n", com->itens[i].status);
            printf("///            Quant.: %s \n", com->itens[i].quant);

        }

    }

    printf("///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

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
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
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

// SEÇÃO RELACIONADA AO CADASTRO ________________________________________________________________________________

Compra* telaCadastrarCompra(void){

    int validaCod;
    int validaDig;
    int validaData;
    int validaHora;
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
    printf("///           = = = = =  MÓDULO CADASTRAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    // ----------------------- Alocando espaço de memória ----------------------------------

    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));

    // ----------------------- Validando a quantidade de itens ----------------------------------

    do{
        printf("///            - Quant. Itens da compra: ");
        scanf("%[^\n]", com->quantItens);
        getchar();
    
        validaDig = testeDigitosNumericos(com->quantItens);
        validaNull = verificaNulo(com->quantItens);

		if(validaDig || validaNull){
			printf("///            Quantidade inválida, tente novamente !\n");
		}

	}while(validaDig || validaNull);

    int q = atoi(com->quantItens);

    for(int i = 0; i < q; i++){

        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

        // ----------------------- Validando o código de barras ----------------------------------

        do{
            printf("///            - Código de Barras: ");
            scanf("%[^\n]", com->itens[i].codBarras);
            getchar();
        
            validaCod = validaCodBarras(com->itens[i].codBarras);
            validaDig = testeDigitosNumericos(com->itens[i].codBarras);
            validaNull = verificaNulo(com->itens[i].codBarras);

            if(!validaCod || validaDig || validaNull){
                printf("///            Código inválido, tente novamente !\n");
            }

        }while(!validaCod || validaDig || validaNull);

        // ----------------------- Validando a descrição do produto ------------------------------

        do{
            printf("///            - Descrição do Item: ");
            scanf("%[^\n]", com->itens[i].nomeItem);
            getchar();

            validaDig = testeDigitos(com->itens[i].nomeItem);
            validaNull = verificaNulo(com->itens[i].nomeItem);

            if(validaDig || validaNull){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        // ----------------------- Validando a data de validade ----------------------------------

        do{
            printf("///            - Data Val. (dd/mm/aaaa): ");
            scanf("%[^\n]", com->itens[i].dataValidade);
            getchar();

            validaData = testaData(com->itens[i].dataValidade);
            validaDig = testeDigitosNumericosData(com->itens[i].dataValidade);
            validaNull = verificaNulo(com->itens[i].dataValidade);

            if (!validaData || validaDig || validaNull) {
                printf("///            Data inválida, tente novamente !\n");
            }

        }while(!validaData || validaDig || validaNull);

        // -------------------------------- Validando o local ------------------------------------

        do{
            printf("///            - Local: ");
            scanf("%[^\n]", com->itens[i].local);
            getchar();

            validaDig = testeDigitos(com->itens[i].local);
            validaNull = verificaNulo(com->itens[i].local);

            if(validaDig || validaNull){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        // -------------------------------- Validando o status -----------------------------------

        do{
            printf("///            - Status: ");
            scanf("%[^\n]", com->itens[i].status);
            getchar();

            validaDig = testeDigitos(com->itens[i].status);
            validaNull = verificaNulo(com->itens[i].status);

            if(validaDig || validaNull){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        // ----------------------------- Validando a quantidade ----------------------------------
      
        do{
            printf("///            - Quantidade: ");
            scanf("%[^\n]", com->itens[i].quant);
            getchar();
            
            validaDig = testeDigitosNumericos(com->itens[i].quant);
            validaNull = verificaNulo(com->itens[i].quant);

            if(validaDig || validaNull || strcmp(com->itens[i].quant, "0") == 0){
                printf("///            Dígitos inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);
    } 
    printf("///\n");

    // ----------------------------- Validando o valor da compra -------------------------------
                
    do{     
        printf("///            - Valor da compra: R$ ");
        scanf("%[^\n]", com->valorCompra);
        getchar();

        validaDig = testeDigitosNumericosValorFlutuante(com->valorCompra);
        validaNull = verificaNulo(com->valorCompra);

        if (validaDig || validaNull){
            printf("///            Preço do item inválido, tente novamente !\n");
        }
    
    }while (validaDig || validaNull);

    // ------------------------- Validando a data da compra ----------------------------------
    do{
        printf("///            - Data Compra (dd/mm/aaaa): ");
        scanf("%[^\n]", com->dataCompra);
        getchar();
    
        validaData = testaData(com->dataCompra);
        validaDig = testeDigitosNumericosData(com->dataCompra);
        validaNull = verificaNulo(com->dataCompra);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

    // ------------------------- Validando a hora da compra ----------------------------------

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", com->horaCompra);
        getchar();
    
        validaHora = testaHora(com->horaCompra);
        validaDig = testeDigitosNumericosHora(com->horaCompra);
        validaNull = verificaNulo(com->horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    // -----------------Definindo o status da compra -----------------------------------------

    strcpy(com->status, "DISPONÍVEL");
            
    // ------------------------- Exibindo os valores da compra ----------------------------------

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Compra cadastrada com sucesso !                   ///\n");
    exibirCompra(com);
   
    return com;

}

void cadastrarCompra(void){

    Compra* com;

    com = telaCadastrarCompra();

    gravarCompra(com);

    free(com);

}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

Chave* telaPesquisarCompra(void){

    int validaDig;
    int validaData;
    int validaHora;
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
    printf("///           = = = = =  MÓDULO PESQUISAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    Chave* key;
    key = (Chave*) malloc(sizeof(Chave));

    do{
        printf("///            - Data Compra (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataCompra);
        getchar();
    
        validaData = testaData(key->dataCompra);
        validaDig = testeDigitosNumericosData(key->dataCompra);
        validaNull = verificaNulo(key->dataCompra);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", key->horaCompra);
        getchar();
    
        validaHora = testaHora(key->horaCompra);
        validaDig = testeDigitosNumericosHora(key->horaCompra);
        validaNull = verificaNulo(key->horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return key;

}

Compra* pegarCompra(Chave* key){

    FILE* file;
    Compra* com;

    com = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "rb");

    while(fread(com, sizeof(Compra), 1, file)){
        if(!strcmp(com->dataCompra, key->dataCompra) && !strcmp(com->horaCompra, key->horaCompra)){
            fclose(file);
            return com;
        }
    }

    fclose(file);
    return NULL;
}

void pesquisarCompra(void){

    Compra* com;
    Chave* key;

    key = telaPesquisarCompra();
    com = pegarCompra(key);
    exibirCompra(com);

    free(key);
    free(com);

}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

Chave* telaExcluirCompra(){

    int validaDig;
    int validaData;
    int validaHora;
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
    printf("///            = = = = =  MÓDULO EXCLUIR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");

    Chave* key;
    key = (Chave*) malloc(sizeof(Chave));

    // ------------------------- Validando a data da compra ----------------------------------

    do{
        printf("///            - Data Compra (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataCompra);
        getchar();
    
        validaData = testaData(key->dataCompra);
        validaDig = testeDigitosNumericosData(key->dataCompra);
        validaNull = verificaNulo(key->dataCompra);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

// ------------------------- Validando a hora da compra ----------------------------------

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", key->horaCompra);
        getchar();
    
        validaHora = testaHora(key->horaCompra);
        validaDig = testeDigitosNumericosHora(key->horaCompra);
        validaNull = verificaNulo(key->horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return key;

}

void excluirLogicamente(Compra* com){

    FILE* file;
    Compra* comp;
    char resposta;

    int validaDig;
    int validaOp;

    comp = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "r+b");

    if(com == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não foram encontradas compras com a DATA e HORA          ///\n");  
        printf("///          fornecidas.                                              ///\n");    
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    } else{
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

            while(!feof(file)) {
                fread(comp, sizeof(Compra), 1, file);
                if(!strcmp(com->dataCompra, comp->dataCompra) && !strcmp(com->horaCompra, comp->horaCompra) && strcmp("x",comp->status)){
                    strcpy(comp->status, "x");
                    fseek(file, -1*sizeof(Compra), SEEK_CUR);
                    fwrite(comp, sizeof(Compra), 1, file);
                    break;
                }
            }

            printf("///                                                                   ///\n");
            printf("///            Compra excluída com sucesso!                           ///\n"); 
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

void excluirCompra(void){

    Compra* com;
    Chave* key;

    key = telaExcluirCompra();
    com = pegarCompra(key);
    exibirCompra(com);
    excluirLogicamente(com);

    free(key);
    free(com);

}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

Chave* telaAlterarCompra(void){

    int validaDig;
    int validaData;
    int validaHora;
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
    printf("///            = = = = =  MÓDULO ALTERAR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");

    Chave* key;
    key = (Chave*) malloc(sizeof(Chave));
    
    do{
        printf("///            - Data Compra (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataCompra);
        getchar();
    
        validaData = testaData(key->dataCompra);
        validaDig = testeDigitosNumericosData(key->dataCompra);
        validaNull = verificaNulo(key->dataCompra);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", key->horaCompra);
        getchar();
    
        validaHora = testaHora(key->horaCompra);
        validaDig = testeDigitosNumericosHora(key->horaCompra);
        validaNull = verificaNulo(key->horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return key;

}

void alterarTudo(Compra* com_lida){

    int validaCod;
    int validaDig;
    int validaNull;
    int validaData;
    int validaOp;
    char decisao;

    FILE* file;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));

    Compra* com_pre;    
    com_pre = (Compra*) malloc(sizeof(Compra));

    file = fopen("compras.dat", "r+b");

    if(com_lida == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///         Não existem compras cadastradas com a DATA e HORA         ///\n");  
        printf("///         fornecidas.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        printf("///                                                                   ///\n");
        printf("///           NOVA LISTA DE ITENS:                                    ///\n");
        printf("///                                                                   ///\n");

        // ----------------------- Validando a quantidade de itens ----------------------------------

        do{
            printf("///            - Quant. Itens da compra: ");
            scanf("%[^\n]", com_pre->quantItens);
            getchar();
        
            validaDig = testeDigitosNumericos(com_pre->quantItens);
            validaNull = verificaNulo(com_pre->quantItens);

            if(validaDig || validaNull){
                printf("///            Quantidade inválida, tente novamente !\n");
            }

        }while(validaDig || validaNull);

        int quant = atoi(com_pre->quantItens);

        for(int i = 0; i < quant; i++){

            printf("///\n");
            printf("///            Item %d \n", i+1);
            printf("///\n");

            // ----------------------- Validando o código de barras ----------------------------------

            do{
                printf("///            - Código de Barras: ");
                scanf("%[^\n]", com_pre->itens[i].codBarras);
                getchar();
            
                validaCod = validaCodBarras(com_pre->itens[i].codBarras);
                validaNull = verificaNulo(com_pre->itens[i].codBarras);

                if(!validaCod || validaNull){
                    printf("///            Código inválido, tente novamente !\n");
                }

            }while(!validaCod || validaNull);

            // ----------------------- Validando a descrição do produto ------------------------------

            do{
                printf("///            - Descrição do Item: ");
                scanf("%[^\n]", com_pre->itens[i].nomeItem);
                getchar();

                validaDig = testeDigitos(com_pre->itens[i].nomeItem);
                validaNull = verificaNulo(com_pre->itens[i].nomeItem);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }
            
            }while (validaDig || validaNull);

            // ----------------------- Validando a data de validade ----------------------------------

            do{
                printf("///            - Data Val. (dd/mm/aaaa): ");
                scanf("%[^\n]", com_pre->itens[i].dataValidade);
                getchar();
            
                validaData = testaData(com_pre->itens[i].dataValidade);
                validaDig = testeDigitosNumericosData(com_pre->itens[i].dataValidade);
                validaNull = verificaNulo(com_pre->itens[i].dataValidade);

                if (!validaData || validaDig || validaNull) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData || validaDig || validaNull);

            // ----------------------------- Validando a quantidade ----------------------------------
            
            do{
                printf("///            - Quantidade: ");
                scanf("%[^\n]", com_pre->itens[i].quant);
                getchar();
                
                validaDig = testeDigitosNumericos(com_pre->itens[i].quant);
                validaNull = verificaNulo(com_pre->itens[i].quant);

                if(validaDig || validaNull){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);

        }

        // ----------------------------- Validando o valor da compra -------------------------------
                
        do{     
            printf("///            - Valor da compra: R$ ");
            scanf("%[^\n]", com_pre->valorCompra);
            getchar();

            validaDig = testeDigitosNumericosValorFlutuante(com_pre->valorCompra);
            validaNull = verificaNulo(com_pre->valorCompra);

            if (validaDig || validaNull){
                printf("///            Valor da compra inválida, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        // ----------------------------- Solicitando confirmação -----------------------------------

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

            while(fread(com, sizeof(Compra), 1, file)) {
                if(!strcmp(com->dataCompra, com_lida->dataCompra) && !strcmp(com->horaCompra, com_lida->horaCompra)){
                    strcpy(com->valorCompra, com_pre->valorCompra);
                    for(int i = 0; i < quant; i++){
                        strcpy(com->quantItens, com_pre->quantItens);
                        strcpy(com->itens[i].codBarras, com_pre->itens[i].codBarras);
                        strcpy(com->itens[i].nomeItem, com_pre->itens[i].nomeItem);
                        strcpy(com->itens[i].dataValidade, com_pre->itens[i].dataValidade);
                        strcpy(com->itens[i].quant, com_pre->itens[i].quant);
                    }
                    fseek(file, -1*sizeof(Compra), SEEK_CUR);
                    fwrite(com, sizeof(Compra), 1, file);
                }
            } 

            printf("///                                                                   ///\n");
            printf("///            Produto alterado com sucesso!                          ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        } else if(decisao == 'N' || decisao == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operação cancelada!                                    ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }
    }
}

void alterarItem(Compra* com_lida){

    int validaDig;
    int validaCod;
    int validaData;
    int validaNull;
    int validaOp;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];
    char valorCompra[10];

    FILE* file;
    Compra* com;

    com = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "r+b");

    if(com_lida == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não foram encontradas compras com a DATA e HORA          ///\n");  
        printf("///          informada.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    } else {
        printf("///                                                                   ///\n");
        printf("///           INFORME O ITEM A ALTERAR:                               ///\n");
        printf("///                                                                   ///\n");

        do{
            printf("///            - Código de Barras: ");
            scanf("%[^\n]", codBarras);
            getchar();
        
            validaCod = validaCodBarras(codBarras);
            validaNull = verificaNulo(codBarras);

            if(!validaCod || validaNull){
                printf("///            Código inválido, tente novamente !\n");
            }
        }while(!validaCod || validaNull);

        do{
            printf("///            - Data de Validade (dd/mm/aaaa): ");
            scanf("%[^\n]", dataValidade);
            getchar();

            validaData = testaData(dataValidade);
            validaDig = testeDigitosNumericosData(dataValidade);
            validaNull = verificaNulo(dataValidade);

            if (!validaData || validaDig || validaNull) {
                printf("///            Data inválida, tente novamente !\n");
            }

        }while(!validaData || validaDig || validaNull);

        int q = atoi(com_lida->quantItens);

        for(int i = 0; i < q; i++){
            if (!strcmp(codBarras, com_lida->itens[i].codBarras) && !strcmp(dataValidade,com_lida->itens[i].dataValidade)){
                int itemAch = i;
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///                        ITEM ENCONTRADO !                          ///\n");
                printf("///                                                                   ///\n");
                printf("///             Código de Barras: %s \n", com_lida->itens[i].codBarras);
                printf("///             Descrição do Item: %s \n", com_lida->itens[i].nomeItem);
                printf("///             Data de Validade: %s \n", com_lida->itens[i].dataValidade);
                printf("///             Quantidade: %s \n", com_lida->itens[i].quant);
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
                printf("///                                                                   ///\n");
                printf("///            - Digite 'a' para alterar a descrição                  ///\n");
                printf("///            - Digite 'b' para alterar a validade                   ///\n");
                printf("///            - Digite 'c' para alterar a quantidade                 ///\n");
                printf("///            - Digite 'd' para alterar o valor da compra            ///\n");
                printf("///        ___________________________________________________        ///\n");
                printf("///                                                                   ///\n");

                do{
                    printf("///            - Informe a sua opção: ");
                    scanf("%[^\n]", &respostaLetras);
                    getchar();

                    validaDig = testeDigito(respostaLetras);
                    validaOp = validaOpcaoLetrasAD(respostaLetras);
                    

                    if(!validaOp || validaDig){
                        printf("///            Opcão inválida, tente novamente!\n");
                    }

                }while(!validaOp || validaDig);

// ----------------------- Alterando a descrição da compra -------------------------------

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

                    while(fread(com, sizeof(Compra), 1, file)){
                        strcpy(com->itens[itemAch].nomeItem, nomeItem);        
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A descrição do item foi alterado!                      ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

                // ----------------------- Alterando a data de validade ----------------------------------

                }else if(respostaLetras == 'B' || respostaLetras == 'b'){
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

                    while(fread(com, sizeof(Compra), 1, file)){
                        strcpy(com->itens[itemAch].dataValidade, dataValidade);        
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A data de validade do item foi alterada!               ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

                // ----------------------------- Alterando a quantidade ----------------------------------

                }else if(respostaLetras == 'C' || respostaLetras == 'c'){   
                    printf("///                                                                   ///\n");
                    do{
                        printf("///            - c) Nova Quantidade: ");
                        scanf("%[^\n]", quant);
                        getchar();
                        
                        validaDig = testeDigitosNumericos(quant);
                        validaNull = verificaNulo(quant);

                        if(validaDig || validaNull){
                            printf("///            Dígitos inválidos, tente novamente !\n");
                        }
                    }while (validaDig || validaNull);

                    while(fread(com, sizeof(Compra), 1, file)){
                        strcpy(com->itens[itemAch].quant, quant);        
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A quantidade do item foi alterada!                     ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

                // ----------------------------- Alterando o valor da compra -------------------------------

                }else if(respostaLetras == 'D' || respostaLetras == 'd'){
                    printf("///                                                                   ///\n");
                    do{     
                        printf("///            - Valor da compra: R$ ");
                        scanf("%[^\n]", valorCompra);
                        getchar();

                        validaDig = testeDigitosNumericosValorFlutuante(valorCompra);
                        validaNull = verificaNulo(valorCompra);

                        if (validaDig || validaNull){
                            printf("///            Valor da compra inválido, tente novamente !\n");
                        }

                    }while (validaDig || validaNull);
            
                    while(fread(com, sizeof(Compra), 1, file)) {
                        strcpy(com->valorCompra, valorCompra);
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            O valor da compra foi alterado!                        ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();
                }
            } else{
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
                printf("///                                                                   ///\n");
                printf("/////////////////////////////////////////////////////////////////////////\n\n");
                printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
            }
        }
    }
}

void alterarCompra(void){
    Chave* key;
    Compra* com;
    char resposta;
    int validaDig;
    int validaOp;

    key = telaAlterarCompra();
    com = pegarCompra(key);

    if(com == NULL){
        exibirCompra(com);
    }else{
        exibirCompra(com);
        do{
            printf("///          - Deseja alterar todos os items da compra (S/N) ");
            scanf("%[^\n]", &resposta);
            getchar();

            validaDig = testeDigito(resposta);
            validaOp = validaOpcao(resposta);
            
            if(!validaOp || validaDig){
                printf("///            Opcão inválida, tente novamente!\n");
            }
        }while(!validaOp || validaDig);

        if (resposta == 'S' || resposta == 's'){
            alterarTudo(com);
            free(key);
            free(com);

        } else if(resposta == 'N' || resposta == 'n'){
            alterarItem(com);
            free(key);
            free(com);
        }
    }
}

void listarCompras(void){

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
    printf("///          = = = = = = MÓDULO LISTAR COMPRAS: = = = = = =          ///\n");
    printf("///                                                                   ///\n");

    FILE* fp;
    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));
    fp = fopen("compras.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(fread(com, sizeof(Compra), 1, fp)) {
        if (strcmp(com->status, "x")) {
            exibirCompra(com);
        }
    }
    fclose(fp);
}