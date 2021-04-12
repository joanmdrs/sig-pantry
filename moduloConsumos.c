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

/* A função telaCadastrarConsumo realiza o cadastro de um consumo. */

Consumo* telaCadastrarConsumo(void){

    int validaCod;
    int validaDig;
    int validaData;
    int validaHora;
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

	}while(!validaCod || validaDig || validaNull);

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

        quantC = converteCharParaInt(con->itens[i].quant);

    }

// ------------------------- Validando a data do consumo ----------------------------------

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
    printf("///                                                                   ///\n");
    printf("///          Lista de Itens:                                          ///\n");
    printf("///                                                                   ///\n");
    
    for (int i = 0; i < q; i++){
        printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
        printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
        printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);
        printf("///                    Quantidade: %d \n", quantC);

    }

    printf("///                          Data: %s \n", con->dataConsumo);
    printf("///                       Horário: %s \n", con->horaConsumo);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 >>> Tecle <ENTER> para continuar...               ///\n");
    getchar();

    return con;

}
/* A função telaPesquisarConsumo realiza a busca de um consumo. */

void telaPesquisarConsumo(Consumo* con){

    char dataConsumo[11];
    char horaConsumo[9];

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

    if((!strcmp(dataConsumo, con->dataConsumo)) && (!strcmp(horaConsumo, con->horaConsumo))){
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            CONSUMO LOCALIZADO!                                    ///\n");
        printf("///                                                                   ///\n");
        printf("///            Lista de Itens:                                        ///\n");
        printf("///                                                                   ///\n");

        int q = atoi(con->quantItens);

        for (int i = 0; i < q; i++){
            printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
            printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
            int quantC = converteCharParaInt(con->itens[i].quant);
            printf("///                    Quantidade: %d \n", quantC);
            printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);
            printf("///                         Local: %s \n", con->itens[i].local);
            printf("///                        Status: %s \n", con->itens[i].status);
        }

        printf("///            - Data do consumo: %s \n", con->dataConsumo);
        printf("///            - Horário da consumo: %s \n", con->horaConsumo);
        printf("///        ___________________________________________________        ///\n");
    } else {
        printf("///                                                                   ///\n");  
        printf("///          Não há registro de consumo para o dia e horário          ///\n");    
        printf("///          informado.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");
    }
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

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
            printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
            printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
            int quantC = converteCharParaInt(con->itens[i].quant);
            printf("///                    Quantidade: %d \n", quantC);
            printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);
            printf("///                         Local: %s \n", con->itens[i].local);
            printf("///                        Status: %s \n", con->itens[i].status);
        }

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

/* A função telaAlterarConsumo realiza a alteração de um consumo. */

void telaAlterarConsumo(Consumo* con){

    char dataConsumo[11];
    char horaConsumo[9];
    char resposta;
    char decisao;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];

    int validaCod;
    int validaOp;
    int validaDig;
    int validaData;
    int validaHora;
    int validaNull;
    int quantC;

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
            printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
            printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
            int quantC = converteCharParaInt(con->itens[i].quant);
            printf("///                    Quantidade: %d \n", quantC);
            printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);
            printf("///                         Local: %s \n", con->itens[i].local);
            printf("///                        Status: %s \n", con->itens[i].status);
        }

        printf("///            - Data do consumo: %s \n", con->dataConsumo);
        printf("///            - Horário da consumo: %s \n", con->horaConsumo);
        printf("///        ___________________________________________________        ///\n");
    } else {
        printf("///                                                                   ///\n");  
        printf("///          Não há registro de consumo para o dia e horário          ///\n");    
        printf("///          informado.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");
    }
// ---------------------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALOR DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %c \n", resposta);
    printf("/// _________________________________________________________________ ///\n");

    if (resposta == 'S' || resposta == 's'){
        printf("///                                                                   ///\n");
        printf("///           NOVA LISTA DE ITENS:                                    ///\n");
        printf("///                                                                   ///\n");

        int q = atoi(con->quantItens);

        for(int i = 0; i < q; i++){

            printf("///\n");
            printf("///            Item %d \n", i+1);
            printf("///\n");

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

// ----------------------- Validando a descrição do produto ------------------------------

            do{
                printf("///            - Descrição do Item: ");
                scanf("%[^\n]", nomeItem);
                getchar();

                validaDig = testeDigitos(nomeItem);
                validaNull = verificaNulo(nomeItem);

                if(validaDig || validaNull){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }
            
            }while (validaDig || validaNull);

// ----------------------- Validando a data de validade ----------------------------------

            do{
                printf("///            - Data Val. (dd/mm/aaaa): ");
                scanf("%[^\n]", dataValidade);
                getchar();
            
                validaData = testaData(dataValidade);
                validaDig = testeDigitosNumericosData(dataValidade);
                validaNull = verificaNulo(dataValidade);

                if (!validaData || validaDig || validaNull) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData || validaDig || validaNull);

// ----------------------------- Validando a quantidade ----------------------------------
        
            do{
                printf("///            - Quantidade: ");
                scanf("%[^\n]", quant);
                getchar();
                
                validaDig = testeDigitosNumericos(quant);
                validaNull = verificaNulo(quant);

                if(validaDig || validaNull){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig || validaNull);

            quantC = converteCharParaInt(quant);

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                       VALORES DE ENTRADA:                         ///\n");
            printf("///                                                                   ///\n");
            printf("///            Item %d \n", i+1);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///              Código de Barras: %s \n", codBarras);
            printf("///             Descrição do Item: %s \n", nomeItem);
            printf("///              Data de Validade: %s \n", dataValidade);
            printf("///                    Quantidade: %d \n", quantC);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");

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

                strcpy(con->itens[i].codBarras, codBarras);
                strcpy(con->itens[i].nomeItem, nomeItem);
                strcpy(con->itens[i].dataValidade, dataValidade);
                strcpy(con->itens[i].quant, quant);

                printf("///                                                                   ///\n");
                printf("///            Consumo alterado com sucesso!                          ///\n"); 
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

    }else if(resposta == 'N' || resposta == 'n'){

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
        int q = atoi(con->quantItens);
        for(int i = 0; i < q; i++){

            if (!strcmp(codBarras,con->itens[i].codBarras) && !strcmp(dataValidade,con->itens[i].dataValidade) && strcmp("x",con->status)){
                printf("/// _________________________________________________________________ ///\n");
                printf("///                                                                   ///\n");
                printf("///            ITEM ENCONTRADO !                                      ///\n");
                printf("///                                                                   ///\n");
                printf("///              Código de Barras: %s \n", con->itens[i].codBarras);
                printf("///             Descrição do Item: %s \n", con->itens[i].nomeItem);
                int quantC = converteCharParaInt(con->itens[i].quant);
                printf("///                    Quantidade: %d \n", quantC);
                printf("///              Data de Validade: %s \n", con->itens[i].dataValidade);
                printf("///                         Local: %s \n", con->itens[i].local);
                printf("///                        Status: %s \n", con->itens[i].status);
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

// ----------------------- Validando a descrição da compra -------------------------------

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

                    printf("/// _________________________________________________________________ ///\n");
                    printf("///                                                                   ///\n");
                    printf("///                        VALOR DE ENTRADA:                          ///\n");
                    printf("///                                                                   ///\n");
                    printf("///                          Nome: %s \n", nomeItem);
                    printf("/// _________________________________________________________________ ///\n");
                    strcpy(con->itens[i].nomeItem, nomeItem);
                    printf("///                                                                   ///\n");
                    printf("///            O nome da compra foi alterado!                         ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

// ----------------------- Validando a data de validade ----------------------------------

                }else if(resposta == 'B' || respostaLetras == 'b'){
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

                    printf("/// _________________________________________________________________ ///\n");
                    printf("///                                                                   ///\n");
                    printf("///                        VALOR DE ENTRADA:                          ///\n");
                    printf("///                                                                   ///\n");
                    printf("///              Data de Validade: %s \n", dataValidade);
                    printf("/// _________________________________________________________________ ///\n");
                    strcpy(con->itens[i].dataValidade, dataValidade);
                    printf("///                                                                   ///\n");
                    printf("///            A data de validade da compra foi alterada!             ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

// ----------------------------- Validando a quantidade ----------------------------------

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

                    quantC = converteCharParaInt(quant);

// ---------------------------------------------------------------------------------------

                    printf("/// _________________________________________________________________ ///\n");
                    printf("///                                                                   ///\n");
                    printf("///                        VALOR DE ENTRADA:                          ///\n");
                    printf("///                                                                   ///\n");
                    printf("///                    Quantidade: %d \n", quantC);       
                    printf("/// _________________________________________________________________ ///\n");
                    strcpy(con->itens[i].quant, quant);
                    printf("///                                                                   ///\n");
                    printf("///            A quantidade da compra foi alterada!                   ///\n");
                    printf("///                                                                   ///\n");
                    printf("/////////////////////////////////////////////////////////////////////////\n\n");
                    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
                    getchar();

                }

            } else{
                printf("///                                                                   ///\n");
                printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
                printf("///                                                                   ///\n");
                printf("/////////////////////////////////////////////////////////////////////////\n\n");
                printf("\t\t>>> Tecle <ENTER> para continuar...\n");

            }
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