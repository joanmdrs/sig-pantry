#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"

typedef struct compra Compra;

struct compra {
    char quantItens[10];
    Produto itens[100];
    float valorItem[100];
    float valorCompra;
    char dataCompra[11];
    char horaCompra[6];
    char status[10];
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

/* A função menuCompras irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listar, referentes ao módulo compras. */

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

    float valor = 0.0;
    float total = 0.0;
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
            quantC = converteCharParaInt(com->itens[i].quant);

            if(validaDig || validaNull){
                printf("///            Dígitos inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        // ----------------------------- Validando o valor do item -------------------------------
                
        do{     
            char preco[10];           
            printf("///            - Valor do Item: R$ ");
            scanf("%[^\n]", preco);
            getchar();

            validaDig = testeDigitosNumericosValorFlutuante(preco);
            validaNull = verificaNulo(preco);

            if (validaDig || validaNull){
                printf("///            Preço do item inválido, tente novamente !\n");
            }
            

            com->valorItem[i] = converteCharParaDouble(preco);
        
        }while (validaDig || validaNull);


        // ------------------------- Calculando o valor da compra ----------------------------------

        valor = quantC * (com->valorItem[i]);
        total += valor;

        com->valorCompra = total;

    }    

    // ------------------------- Validando a data da compra ----------------------------------

    printf("///\n");
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
        
    // ---------------------------------------------------------------------------------------
    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Compra cadastrada com sucesso !                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          Lista de Itens:                                          ///\n");
    printf("///                                                                   ///\n");

    for (int i = 0; i < q; i++){
        printf("///        ___________________________________________________        ///\n");
        printf("///            Item %d \n", i+1);
        printf("///                                                                   ///\n");
        printf("///          Código de Barras: %s \n", com->itens[i].codBarras);
        printf("///          Descrição do Item: %s \n", com->itens[i].nomeItem);
        printf("///          Data de Validade: %s \n", com->itens[i].dataValidade);
        printf("///          Local: %s \n", com->itens[i].local);
        printf("///          Status: %s \n", com->itens[i].status);
        printf("///          Quant.: %s \n", com->itens[i].quant);
        printf("///          Val. Item: R$ %.2f \n", com->valorItem[i]);

    }

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          Data: %s \n", com->dataCompra);
    printf("///          Horário: %s \n", com->horaCompra);
    printf("///          Val. Compra: R$ %.2f \n", com->valorCompra);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 >>> Tecle <ENTER> para continuar...               ///\n");
    getchar();

    return com;

}

void cadastrarCompra(){

    Compra* com;

    com = telaCadastrarCompra();

    gravarCompra(com);

    free(com);

}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

Chave* telaPesquisarCompra(){

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

    while(!feof(file)){
        fread(com, sizeof(Compra), 1, file);
        if(!strcmp(com->dataCompra, key->dataCompra) && !strcmp(com->horaCompra, key->horaCompra)){
            fclose(file);
            return com;
        }
    }

    fclose(file);
    return NULL;
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
        printf("///                        COMPRA LOCALIZADA!                         ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///             Data da compra: %s \n", com->dataCompra);
        printf("///             Horário da compra: %s \n", com->horaCompra);
        printf("///             Valor da compra: R$ %.2f \n", com->valorCompra);
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
            printf("///            Val. Item: R$ %.2f \n", com->valorItem[i]);

        }

    }

    printf("///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

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

    char resposta;

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

/*

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

// ---------------------------------------------------------------------------------------

        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                        VALOR DE ENTRADA:                          ///\n");
        printf("///                                                                   ///\n");
        printf("///             Opção escolhida: %c \n", resposta);
        printf("/// _________________________________________________________________ ///\n");

        if (resposta == 'S' || resposta == 's'){
            strcpy(com->status, "x");
            printf("///                                                                   ///\n");
            printf("///            Compra excluída com sucesso!                           ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(resposta == 'N' || resposta == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operação cancelada!                                    ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }

        }else {
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");  
            printf("///          Não há registro de compras para o dia e horário          ///\n");    
            printf("///          informado.                                               ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }
        

// --------------------------------------------------------------------------------------- */

    
    
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

Chave* telaAlterarCompra(){

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

void alterarTudo(Compra* com_lida){

    int validaCod;
    int validaDig;
    int validaNull;
    int validaData;
    int quantC;
    float valor = 0.0;
    float total = 0.0;

    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));

    printf("///                                                                   ///\n");
    printf("///           NOVA LISTA DE ITENS:                                    ///\n");
    printf("///                                                                   ///\n");
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

        Produto* pro;
        pro = (Produto*) malloc(sizeof(Compra));

        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

        // ----------------------- Validando o código de barras ----------------------------------

        do{
            printf("///            - Código de Barras: ");
            scanf("%[^\n]", pro->codBarras);
            getchar();
        
            validaCod = validaCodBarras(pro->codBarras);
            validaNull = verificaNulo(pro->codBarras);

            if(!validaCod || validaNull){
                printf("///            Código inválido, tente novamente !\n");
            }

        }while(!validaCod || validaNull);

        // ----------------------- Validando a descrição do produto ------------------------------

        do{
            printf("///            - Descrição do Item: ");
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

        // ----------------------------- Validando o valor do item -------------------------------
        
        do{     
            char preco[10];  

            printf("///            - Valor do Item: R$ ");
            scanf("%[^\n]", preco);
            getchar();

            validaDig = testeDigitosNumericosValorFlutuante(preco);
            validaNull = verificaNulo(preco);

            if (validaDig || validaNull){
                printf("///            Preço do item inválido, tente novamente !\n");
            }
            

            com->valorItem[i] = converteCharParaDouble(preco);
        
        }while (validaDig || validaNull);


        // ------------------------- Calculando o valor da compra ----------------------------------

        quantC = converteCharParaInt(pro->quant);

        valor = quantC * (com->valorItem[i]);
        total += valor;

        com->valorCompra = total;

        // ------------------------- Adicionando o produto ao vetor de Produtos ----------------------

        strcpy(com->itens[i].codBarras, pro->codBarras);
        strcpy(com->itens[i].nomeItem, pro->nomeItem);
        strcpy(com->itens[i].dataValidade, pro->dataValidade);
        strcpy(com->itens[i].local, pro->local);
        strcpy(com->itens[i].status, pro->status);

        // ------------------------- Valores de entrada cadastrados ----------------------------------
            
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
        printf("///                                                                   ///\n");
        printf("///            Item %d \n", i+1);
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", pro->codBarras);
        printf("///             Descrição do Item: %s \n", pro->nomeItem);
        printf("///              Data de Validade: %s \n", pro->dataValidade);
        printf("///                    Quantidade: %s \n", pro->quant);
        printf("///                 Valor do Item: R$ %.2f \n", com->valorItem[i]);
        printf("///               Valor da compra: R$ %.2f \n", com->valorCompra);
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");

        free(pro);

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
    char local[10];
    char status[10];
    char quant[10];
    char valorItem[10];
    float preco = 0.0;


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

        // ----------------------- Validando o código de barras ----------------------------------

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

        // ----------------------- Validando a data de validade ----------------------------------

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

        // ---------------------------------------------------------------------------------------

        int q = atoi(com_lida->quantItens);

        for(int i = 0; i < q; i++){

            if (!strcmp(codBarras, com_lida->itens[i].codBarras) && !strcmp(dataValidade,com_lida->itens[i].dataValidade)){
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///                        ITEM ENCONTRADO !                          ///\n");
                printf("///                                                                   ///\n");
                printf("///             Código de Barras: %s \n", com_lida->itens[i].codBarras);
                printf("///             Descrição do Item: %s \n", com_lida->itens[i].nomeItem);
                printf("///             Data de Validade: %s \n", com_lida->itens[i].dataValidade);
                printf("///             Quantidade: %d \n", com_lida->itens[i].quant);
                printf("///             Valor do Item: R$ %.2f \n", com_lida->valorItem[i]);
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
                printf("///                                                                   ///\n");
                printf("///            - Digite 'a' para alterar a descrição                  ///\n");
                printf("///            - Digite 'b' para alterar a validade                   ///\n");
                printf("///            - Digite 'c' para alterar a quantidade                 ///\n");
                printf("///            - Digite 'd' para alterar o valor                      ///\n");
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

                    while(!feof(file)) {
                        fread(com, sizeof(Compra), 1, file);
                        strcpy(com->itens[i].nomeItem, nomeItem);        
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                        break;
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A descrição do item foi alterado!                      ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                
                }

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

                    while(!feof(file)) {
                        fread(com, sizeof(Compra), 1, file);
                        strcpy(com->itens[i].dataValidade, dataValidade);        
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                        break;
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A data de validade do item foi alterada!               ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");

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

                    while(!feof(file)) {
                        fread(com, sizeof(Compra), 1, file);
                        strcpy(com->itens[i].quant, quant);        
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                        break;
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A quantidade do item foi alterada!                     ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");

                // ----------------------------- Alterando o valor do item e da compra -------------------------------

                }else if(respostaLetras == 'D' || respostaLetras == 'd'){
                    printf("///                                                                   ///\n");
            
                    do{
                        printf("///            - d) Novo Valor: ");
                        scanf("%[^\n]", valorItem);
                        getchar();
                        
                        validaDig = testeDigitosNumericosValorFlutuante(valorItem);
                        validaNull = verificaNulo(valorItem);

                        if(validaDig || validaNull){
                            printf("///            Dígitos inválidos, tente novamente !\n");
                        }

                        preco = converteCharParaDouble(valorItem);

                    }while (validaDig|| validaNull);

                    com->valorCompra -= com->valorItem[i]; // Removo o valor antigo da compra

                    while(!feof(file)) {
                        fread(com, sizeof(Compra), 1, file);
                        com->valorItem[i] = preco;
                        com->valorCompra += preco;
                        fseek(file, -1*sizeof(Compra), SEEK_CUR);
                        fwrite(com, sizeof(Compra), 1, file);
                        break;
                    }
                    printf("///                                                                   ///\n");
                    printf("///      O valor do item foi alterado! E respectivamente, o valor da  ///\n");
                    printf("///      compra também foi modificado.                                ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");

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

void alterarCompra(){

    Chave* key;
    Compra* com;

    key = telaAlterarCompra();
    com = pegarCompra(key);

    exibirCompra(com);

}