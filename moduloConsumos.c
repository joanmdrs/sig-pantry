#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"

typedef struct consumo Consumo;

struct consumo {
    char quantItens[10];
    Produto itens[100];
    char dataConsumo[11];
    char horaConsumo[6];
    char status[10];
};

typedef struct chaveC ChaveC;

struct chaveC{
    char dataConsumo[11];
    char horaConsumo[6];
};

void gravarConsumo(Consumo* con){
    FILE* file;

    file = fopen("consumos.dat", "ab");

    fwrite(con, sizeof(Consumo), 1, file);

    fclose(file);
}

void exibirConsumo(Consumo* con){
        if(con == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///         Não existem consumos cadastrados com a DATA e HORA        ///\n");  
        printf("///         fornecidas.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///             Data do consumo: %s \n", con->dataConsumo);
        printf("///             Horário do consumo: %s \n", con->horaConsumo);
        printf("///             Status: %s \n", con->status);
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            LISTA DE ITENS:                                        ///\n");
        printf("///                                                                   ///\n");

        int q = atoi(con->quantItens);

        for (int i = 0; i < q; i++){
            printf("               Item %d \n", i+1);
            printf("///\n");
            printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
            printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
            int quantC = converteCharParaInt(con->itens[i].quant);
            printf("///                    Quantidade: %d \n", quantC);
            printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);

        }

    }

    printf("///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

/* A função menuConsumo irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listar, referentes ao módulo consumo. */

char menuConsumo(void){
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
    printf("///            CONSUMOS:                                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Cadastrar consumo                                  ///\n");
    printf("///            2 - Pesquisar consumo                                  ///\n");
    printf("///            3 - Excluir consumo                                    ///\n");
    printf("///            4 - Alterar consumo                                    ///\n");
    printf("///            5 - Listar consumos                                    ///\n");
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

/* A função telaCadastrarConsumo realiza o cadastro de um consumo. */

Consumo* telaCadastrarConsumo(void){

    int validaCod;
    int validaDig;
    int validaData;
    int validaHora;
    int validaNull;

    int quantC[10];

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
    printf("///          = = = = =  MÓDULO CADASTRAR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

// ----------------------- Alocando espaço de memória ----------------------------------

    Consumo* con;
    con = (Consumo*) malloc(sizeof(Consumo));    

// ----------------------- Validando a quantidade de itens ----------------------------------

    do{
        printf("///            - Quant. Itens do consumo: ");
        scanf("%[^\n]", con->quantItens);
        getchar();
    
        validaDig = testeDigitosNumericos(con->quantItens);
        validaNull = verificaNulo(con->quantItens);

		if(validaDig || validaNull){
			printf("///            Quantidade inválida, tente novamente !\n");
		}

	}while(validaDig || validaNull);

    int q = atoi(con->quantItens);

    for(int i = 0; i < q; i++){

        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

// ----------------------- Validando o código de barras ----------------------------------

        do{
            printf("///            - Código de Barras: ");
            scanf("%[^\n]", con->itens[i].codBarras);
            getchar();
        
            validaCod = validaCodBarras(con->itens[i].codBarras);
            validaDig = testeDigitosNumericos(con->itens[i].codBarras);
            validaNull = verificaNulo(con->itens[i].codBarras);

            if(!validaCod || validaDig || validaNull){
                printf("///            Código inválido, tente novamente !\n");
            }

        }while(!validaCod || validaDig || validaNull);

// ----------------------- Validando a descrição do produto ------------------------------

        do{
            printf("///            - Descrição do Item: ");
            scanf("%[^\n]", con->itens[i].nomeItem);
            getchar();

            validaDig = testeDigitos(con->itens[i].nomeItem);
            validaNull = verificaNulo(con->itens[i].nomeItem);

            if(validaDig || validaNull){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

// ----------------------- Validando a data de validade ----------------------------------

        do{
            printf("///            - Data Val. (dd/mm/aaaa): ");
            scanf("%[^\n]", con->itens[i].dataValidade);
            getchar();
        
            validaData = testaData(con->itens[i].dataValidade);
            validaDig = testeDigitosNumericosData(con->itens[i].dataValidade);
            validaNull = verificaNulo(con->itens[i].dataValidade);

            if (!validaData || validaDig || validaNull) {
                printf("///            Data inválida, tente novamente !\n");
            }

        }while(!validaData || validaDig || validaNull);

// ----------------------------- Validando a quantidade ----------------------------------
        
        do{
            printf("///            - Quantidade: ");
            scanf("%[^\n]", con->itens[i].quant);
            getchar();
            
            validaDig = testeDigitosNumericos(con->itens[i].quant);
            validaNull = verificaNulo(con->itens[i].quant);

            if(validaDig || validaNull){
                printf("///            Dígitos inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        quantC[i] = converteCharParaInt(con->itens[i].quant);

    }

// ------------------------- Validando a data do consumo ----------------------------------
    printf("///                                                                   ///\n");

    do{
        printf("///            - Data Consumo (dd/mm/aaaa): ");
        scanf("%[^\n]", con->dataConsumo);
        getchar();
    
        validaData = testaData(con->dataConsumo);
        validaDig = testeDigitosNumericosData(con->dataConsumo);
        validaNull = verificaNulo(con->dataConsumo);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

// ------------------------- Validando a hora do consumo ----------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%[^\n]", con->horaConsumo);
        getchar();

        validaHora = testaHora(con->horaConsumo);
        validaDig = testeDigitosNumericosHora(con->horaConsumo);
        validaNull = verificaNulo(con->horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    strcpy(con->status, "Disponível");
        
// ---------------------------------------------------------------------------------------

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Consumo cadastrado com sucesso !                  ///\n");
    exibirConsumo(con);


    return con;

}

void cadastrarConsumo(void){

    Consumo* con;

    con = telaCadastrarConsumo();

    gravarConsumo(con);

    free(con);

}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

ChaveC* telaPesquisarConsumo(void){

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
    printf("///           = = = = =  MÓDULO PESQUISAR CONSUMO: = = = = =          ///\n");
    printf("///                                                                   ///\n");

    ChaveC* key;
    key = (ChaveC*) malloc(sizeof(ChaveC));

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Data Consumo (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataConsumo);
        getchar();
    
        validaData = testaData(key->dataConsumo);
        validaDig = testeDigitosNumericosData(key->dataConsumo);
        validaNull = verificaNulo(key->dataConsumo);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%[^\n]", key->horaConsumo);
        getchar();

        validaHora = testaHora(key->horaConsumo);
        validaDig = testeDigitosNumericosHora(key->horaConsumo);
        validaNull = verificaNulo(key->horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return key;
}

Consumo* pegarConsumo(ChaveC* key){

    FILE* file;
    Consumo* con;

    con = (Consumo*) malloc(sizeof(Consumo));
    file = fopen("consumos.dat", "rb");

    while(fread(con, sizeof(Consumo), 1, file)){
        if(!strcmp(con->dataConsumo, key->dataConsumo) && !strcmp(con->horaConsumo, key->horaConsumo)){
            fclose(file);
            return con;
        }
    }

    fclose(file);
    return NULL;
}

void pesquisarConsumo(void){

    Consumo* con;
    ChaveC* key;

    key = telaPesquisarConsumo();
    con = pegarConsumo(key);
    exibirConsumo(con);

    free(key);
    free(con);
}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

/* A função telaExcluirConsumo realiza a exclusão de um consumo. */

void telaExcluirConsumo(Consumo* con){

    char resposta;
    char dataConsumo[11];
    char horaConsumo[9];

    int validaOp;
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
    printf("///            = = = = =  MÓDULO EXCLUIR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Data Consumo (dd/mm/aaaa): ");
        scanf("%[^\n]", dataConsumo);
        getchar();
    
        validaData = testaData(dataConsumo);
        validaDig = testeDigitosNumericosData(dataConsumo);
        validaNull = verificaNulo(dataConsumo);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%[^\n]", horaConsumo);
        getchar();
    
        validaHora = testaHora(horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);
        validaNull = verificaNulo(horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);
// ---------------------------------------------------------------------------------------

    if (!strcmp(dataConsumo,con->dataConsumo) && !strcmp(horaConsumo,con->horaConsumo) && strcmp("x",con->status)){
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            CONSUMO LOCALIZADO!                                    ///\n");
        printf("///                                                                   ///\n");
        printf("///            Lista de Itens:                                        ///\n");
        printf("///                                                                   ///\n");

        int q = atoi(con->quantItens);

        for (int i = 0; i < q; i++){
            printf("/// _________________________________________________________________ ///\n");
            printf("///            Item %d \n", i+1);
            printf("///                                                                   ///\n");
            printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
            printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
            int quantC = converteCharParaInt(con->itens[i].quant);
            printf("///                    Quantidade: %d \n", quantC);
            printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);
        }

        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Data do consumo: %s \n", con->dataConsumo);
        printf("///            - Horário da consumo: %s \n", con->horaConsumo);
        printf("///        ___________________________________________________        ///\n");

// ---------------------------------------------------------------------------------------

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

        if (resposta == 'S' || resposta == 's'){
            strcpy(con->status, "x");
            printf("///                                                                   ///\n");
            printf("///            Consumo excluído com sucesso!                          ///\n"); 
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

    } else {
        printf("///                                                                   ///\n");  
        printf("///          Não há registro de consumo para o dia e horário          ///\n");    
        printf("///          informado.                                               ///\n"); 
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

ChaveC* telaAlterarConsumo(void){
    
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
    printf("///          = = = = = = MÓDULO ALTERAR CONSUMO = = = = = =           ///\n");
    printf("///                                                                   ///\n");

    ChaveC* key;
    key = (ChaveC*) malloc(sizeof(ChaveC));

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Data Consumo (dd/mm/aaaa): ");
        scanf("%[^\n]", key->dataConsumo);
        getchar();
    
        validaData = testaData(key->dataConsumo);
        validaDig = testeDigitosNumericosData(key->dataConsumo);
        validaNull = verificaNulo(key->dataConsumo);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%[^\n]", key->horaConsumo);
        getchar();
    
        validaHora = testaHora(key->horaConsumo);
        validaDig = testeDigitosNumericosHora(key->horaConsumo);
        validaNull = verificaNulo(key->horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return key;
}

void alterarTudoC(Consumo* con_lido){

    int validaCod;
    int validaDig;
    int validaNull;
    int validaData;
    int validaOp;
    char decisao;

    FILE* file;
    Consumo* con;
    con = (Consumo*) malloc(sizeof(Consumo));

    Consumo* con_pre;    
    con_pre = (Consumo*) malloc(sizeof(Consumo));

    file = fopen("consumos.dat", "r+b");

    if(con_lido == NULL){
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
            printf("///            - Quant. Itens do consumo: ");
            scanf("%[^\n]", con_pre->quantItens);
            getchar();
        
            validaDig = testeDigitosNumericos(con_pre->quantItens);
            validaNull = verificaNulo(con_pre->quantItens);

            if(validaDig || validaNull){
                printf("///            Quantidade inválida, tente novamente !\n");
            }

        }while(validaDig || validaNull);

        int quant = atoi(con_pre->quantItens);

        for(int i = 0; i < quant; i++){

            printf("///\n");
            printf("///            Item %d \n", i+1);
            printf("///\n");

// ----------------------- Validando o código de barras ----------------------------------

            do{
                printf("///            - Código de Barras: ");
                scanf("%[^\n]", con_pre->itens[i].codBarras);
                getchar();
            
                validaCod = validaCodBarras(con_pre->itens[i].codBarras);
                validaNull = verificaNulo(con_pre->itens[i].codBarras);

                if(!validaCod || validaNull){
                    printf("///            Código inválido, tente novamente !\n");
                }

            }while(!validaCod || validaNull);

// ----------------------- Validando a descrição do produto ------------------------------

            do{
                printf("///            - Descrição do Item: ");
                scanf("%[^\n]", con_pre->itens[i].nomeItem);
                getchar();

                validaDig = testeDigitos(con_pre->itens[i].nomeItem);
                validaNull = verificaNulo(con_pre->itens[i].nomeItem);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }
            
            }while (validaDig || validaNull);

// ----------------------- Validando a data de validade ----------------------------------

            do{
                printf("///            - Data Val. (dd/mm/aaaa): ");
                scanf("%[^\n]", con_pre->itens[i].dataValidade);
                getchar();
            
                validaData = testaData(con_pre->itens[i].dataValidade);
                validaDig = testeDigitosNumericosData(con_pre->itens[i].dataValidade);
                validaNull = verificaNulo(con_pre->itens[i].dataValidade);

                if (!validaData || validaDig || validaNull) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData || validaDig || validaNull);

// ----------------------------- Validando a quantidade ----------------------------------
        
            do{
                printf("///            - Quantidade: ");
                scanf("%[^\n]", con_pre->itens[i].quant);
                getchar();
                
                validaDig = testeDigitosNumericos(con_pre->itens[i].quant);
                validaNull = verificaNulo(con_pre->itens[i].quant);

                if(validaDig || validaNull){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);
        }

// ---------------------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------------------

        if (decisao == 'S' || decisao == 's'){

            while(fread(con, sizeof(Consumo), 1, file)) {
                if(!strcmp(con->dataConsumo, con_lido->dataConsumo) && !strcmp(con->horaConsumo, con_lido->horaConsumo)){
                    for(int i = 0; i < quant; i++){
                        strcpy(con->quantItens, con_pre->quantItens);
                        strcpy(con->itens[i].codBarras, con_pre->itens[i].codBarras);
                        strcpy(con->itens[i].nomeItem, con_pre->itens[i].nomeItem);
                        strcpy(con->itens[i].dataValidade, con_pre->itens[i].dataValidade);
                        strcpy(con->itens[i].quant, con_pre->itens[i].quant);
                    }
                    fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                    fwrite(con, sizeof(Consumo), 1, file);
                }
            } 

            printf("///                                                                   ///\n");
            printf("///            Item alterado com sucesso!                             ///\n"); 
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
    }
}

void alterarItemC(Consumo* con_lido){

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];

    int validaCod;
    int validaDig;
    int validaNull;
    int validaData;
    int validaOp;
    char respostaLetras;

    FILE* file;
    Consumo* con;

    con = (Consumo*) malloc(sizeof(Consumo));
    file = fopen("consumos.dat", "r+b");

    if(con_lido == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///          Não foram encontradas consumos com a DATA e HORA         ///\n");  
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

        int q = atoi(con_lido->quantItens);

        for(int i = 0; i < q; i++){

            if (!strcmp(codBarras, con_lido->itens[i].codBarras) && !strcmp(dataValidade, con_lido->itens[i].dataValidade)){
                int itemAc = i;
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///            ITEM ENCONTRADO !                                      ///\n");
                printf("///                                                                   ///\n");
                printf("///              Código de Barras: %s \n", con_lido->itens[i].codBarras);
                printf("///             Descrição do Item: %s \n", con_lido->itens[i].nomeItem);
                int quantC = converteCharParaInt(con_lido->itens[i].quant);
                printf("///                    Quantidade: %d \n", quantC);
                printf("///              Data de Validade: %s \n", con_lido->itens[i].dataValidade);
                printf("///        ___________________________________________________        ///\n");

                printf("///                                                                   ///\n");
                printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
                printf("///                                                                   ///\n");
                printf("///            - Digite 'a' para alterar a descrição                  ///\n");
                printf("///            - Digite 'b' para alterar a validade                   ///\n");
                printf("///            - Digite 'c' para alterar o quantidade                 ///\n");
                printf("///        ___________________________________________________        ///\n");
                printf("///                                                                   ///\n");
// ---------------------------------------------------------------------------------------

                do{
                    printf("///            - Informe a sua opção: ");
                    scanf("%[^\n]", &respostaLetras);
                    getchar();

                    validaDig = testeDigito(respostaLetras);
                    validaOp = validaOpcaoLetrasAC(respostaLetras);
                    

                    if(!validaOp || validaDig){
                        printf("///            Opcão inválida, tente novamente!\n");
                    }

                }while(!validaOp || validaDig);

// ----------------------- Validando a descrição do Consumo -------------------------------

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

// ---------------------------------------------------------------------------------------

                    while(fread(con, sizeof(Consumo), 1, file)){
                        strcpy(con->itens[itemAc].nomeItem, nomeItem);        
                        fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                        fwrite(con, sizeof(Consumo), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A descrição do item foi alterada!                      ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();
                    break;

                }else if(respostaLetras == 'B' || respostaLetras == 'b'){

// ----------------------- Validando a data de validade ----------------------------------

                    printf("///                                                                   ///\n");

                    do{
                        printf("///            - b) Nova Data Val. (dd/mm/aaaa): ");
                        scanf("%[^\n]", dataValidade);
                        getchar();
                    
                        validaData = testaData(dataValidade);
                        validaDig = testeDigitosNumericosData(dataValidade);
                        validaNull = verificaNulo(dataValidade);

                        if (!validaData || validaNull) {
                            printf("///            Data inválida, tente novamente !\n");
                        }

                    }while(!validaData || validaNull);

// ---------------------------------------------------------------------------------------

                    while(fread(con, sizeof(Consumo), 1, file)){
                        strcpy(con->itens[itemAc].dataValidade, dataValidade);        
                        fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                        fwrite(con, sizeof(Consumo), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A data de validade do item foi alterada!               ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();
                    break;


                }else if(respostaLetras == 'C' || respostaLetras == 'c'){   

// ----------------------------- Validando a quantidade ----------------------------------

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

                    quantC = converteCharParaInt(quant);

// ---------------------------------------------------------------------------------------

                    while(fread(con, sizeof(Consumo), 1, file)){
                        strcpy(con->itens[itemAc].quant, quant);        
                        fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                        fwrite(con, sizeof(Consumo), 1, file);
                    }
                    printf("///                                                                   ///\n");
                    printf("///            A quantidade do item foi alterada!                     ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();
                    break;
                }
            }
        }
        printf("///                                                                   ///\n");
        printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

/* A função telaAlterarConsumo realiza a alteração de um consumo. */

void alterarConsumo(void){
    ChaveC* key;
    Consumo* con;
    char resposta;
    int validaDig;
    int validaOp;

    key = telaAlterarConsumo();
    con = pegarConsumo(key);

    if(con == NULL){
        exibirConsumo(con);
    }else{
        exibirConsumo(con);
        do{
            printf("///          - Deseja alterar todos os items do consumo (S/N) ");
            scanf("%[^\n]", &resposta);
            getchar();

            validaDig = testeDigito(resposta);
            validaOp = validaOpcao(resposta);
            
            if(!validaOp || validaDig){
                printf("///            Opcão inválida, tente novamente!\n");
            }
        }while(!validaOp || validaDig);

        if (resposta == 'S' || resposta == 's'){
            alterarTudoC(con);
            free(key);
            free(con);

        } else if(resposta == 'N' || resposta == 'n'){
            alterarItemC(con);
            free(key);
            free(con);
        }
    }
}

/* A função telaListarConsumos realiza a listagem de todos os consumos. */

void telaListarConsumos(void){

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
    printf("///            MÓDULO LISTAR CONSUMOS:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele por dia e horário, e suas informações          ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    /* No módulo listar consumos, serão exibidos todos os items consumidos, separados por 
    data e horário de cadastro. 
    */
}