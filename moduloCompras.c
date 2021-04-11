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
};


/* A função menuCompras irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listas, referentes ao módulo compras. */

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

/* A função telaCadastrarCompra realiza o cadastro de uma compra. */

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

	}while(!validaCod || validaDig || validaNull);

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

// ---------------------------------------------------------------------------------------
    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Compra cadastrada com sucesso !                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          Lista de Itens:                                          ///\n");
    printf("///                                                                   ///\n");

    for (int i = 0; i < q; i++){
        printf("///          Código de Barras: %s \n", com->itens[i].codBarras);
        printf("///          Descrição do Item: %s \n", com->itens[i].nomeItem);
        printf("///          Data de Validade: %s \n", com->itens[i].dataValidade);
        printf("///          Local: %s \n", com->itens[i].local);
        printf("///          Status: %s \n", com->itens[i].status);
        printf("///          Quant.: %s \n", com->itens[i].quant);
        printf("///          Val. Item: R$ %.2f \n", com->valorItem[i]);
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");

    }
    
    printf("///          Data: %s \n", com->dataCompra);
    printf("///          Horário: %s \n", com->horaCompra);
    printf("///          Val. Compra: R$ %.2f \n", com->valorCompra);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 >>> Tecle <ENTER> para continuar...               ///\n");
    getchar();

    return com;

}

/* A função telaPesquisarCompra realiza a busca de uma compra. */

void telaPesquisarCompra(Compra* com){

    char dataCompra[11];
    char horaCompra[9];

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

// ------------------------- Validando a data da compra ----------------------------------

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

// ------------------------- Validando a hora da compra ----------------------------------

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", horaCompra);
        getchar();
    
        validaHora = testaHora(horaCompra);
        validaDig = testeDigitosNumericosHora(horaCompra);
        validaNull = verificaNulo(horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    if((!strcmp(dataCompra, com->dataCompra)) && (!strcmp(horaCompra, com->horaCompra))){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");  
        printf("///                        COMPRA LOCALIZADA!                         ///\n");
        printf("///                                                                   ///\n");
        printf("///            Lista de Itens:                                        ///\n");
        printf("///                                                                   ///\n");

        int q = atoi(com->quantItens);

        for (int i = 0; i < q; i++){
            printf("///\n");
            printf("///            Código de Barras: %s \n", com->itens[i].codBarras);
            printf("///            Descrição do Item: %s \n", com->itens[i].nomeItem);
            printf("///            Data de Validade: %s \n", com->itens[i].dataValidade);
            printf("///            Local: %s \n", com->itens[i].local);
            printf("///            Status: %s \n", com->itens[i].status);
            printf("///            Quant.: %s \n", com->itens[i].quant);
            printf("///            Val. Item: R$ %.2f \n", com->valorItem[i]);
            printf("///        ___________________________________________________        ///\n");

        }
        printf("///                                                                   ///\n");
        printf("///             Data da compra: %s \n", com->dataCompra);
        printf("///             Horário da compra: %s \n", com->horaCompra);
        printf("///             Valor da compra: R$ %.2f \n", com->valorCompra);
        printf("///        ___________________________________________________        ///\n");

    }else{
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");  
        printf("///          Não há registro de compras para o dia e horário          ///\n");    
        printf("///          informado.                                               ///\n");    
        printf("///        ___________________________________________________        ///\n");
    }
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

/* A função telaExcluirCompra realiza a exclusão de uma compra. */

void telaExcluirCompra(void){

    char resposta;
    char dataCompra[11];
    char horaCompra[9];

    char dia[3];
	int diaC;
	char mes[3];
	int mesC;
	char ano[5];
	int anoC;
    char hora[3];
    int horaC;
    char minutos[3];
    int minutosC;

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
    printf("///            = = = = =  MÓDULO EXCLUIR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");

// ------------------------- Validando a data da compra ----------------------------------

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

// ------------------------- Validando a hora da compra ----------------------------------

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", horaCompra);
        getchar();
    
        validaHora = testaHora(horaCompra);
        validaDig = testeDigitosNumericosHora(horaCompra);
        validaNull = verificaNulo(horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALORES DE ENTRADA:                        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", dataCompra);
    printf("///             Horário da compra: %s \n", horaCompra);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Itens: Aqui vai mostrar todos os itens comprados     ///\n");
    printf("///              naquele dia e horário e suas quantidades.            ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

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

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALOR DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %c \n", resposta);
    printf("/// _________________________________________________________________ ///\n");

    if (resposta == 'S' || resposta == 's'){
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
    
}

/* A função telaAlterarCompra realiza a alteração de uma compra. */

void telaAlterarCompra(void){

    char dataCompra[11];
    char horaCompra[9];
    char resposta;
    char decisao;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];
    char valorItem[10];
    float valorCompra;

    char dia[3];
	int diaC;
	char mes[3];
	int mesC;
	char ano[5];
	int anoC;
    char hora[3];
    int horaC;
    char minutos[3];
    int minutosC;

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
    printf("///            = = = = =  MÓDULO ALTERAR COMPRA: = = = = =            ///\n");
    printf("///                                                                   ///\n");
    
// ------------------------- Validando a data da compra ----------------------------------

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

// ------------------------- Validando a hora da compra ----------------------------------

    do{
        printf("///            - Horário Compra (hh:mm): ");
        scanf("%[^\n]", horaCompra);
        getchar();
    
        validaHora = testaHora(horaCompra);
        validaDig = testeDigitosNumericosHora(horaCompra);
        validaNull = verificaNulo(horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                      VALORES DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", dataCompra);
    printf("///             Horário da compra: %s \n", horaCompra);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário.                                 ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");   
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n");  
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    
// ---------------------------------------------------------------------------------------

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

// ----------------------------- Validando o valor do item -------------------------------
      
        do{
            printf("///            - Valor do Item: R$ ");
            scanf("%[^\n]", valorItem);
            getchar();
            
            validaDig = testeDigitosNumericosValorFlutuante(valorItem);
            validaNull = verificaNulo(valorItem);

            if(validaDig || validaNull){
                printf("///            Dígitos inválidos, tente novamente !\n");
            }

        }while (validaDig || validaNull);

        double valor = converteCharParaDouble(valorItem);

// ----------------------------- Calculando o valor da compra ----------------------------
    
        valorCompra += quantC * valor;

// ---------------------------------------------------------------------------------------
        
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///             Descrição do Item: %s \n", nomeItem);
        printf("///              Data de Validade: %s \n", dataValidade);
        printf("///                    Quantidade: %d \n", quantC);
        printf("///                 Valor do Item: R$ %.2f \n", valor);
        printf("///               Valor da compra: R$ %.2f \n", valorCompra);
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
            printf("///                                                                   ///\n");
            printf("///            Compra alterada com sucesso!                           ///\n"); 
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

        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                     VALORES DE ENTRADA:                           ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///              Data de Validade: %s \n", dataValidade); 
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM ENCONTRADO !                                      ///\n");
        printf("///                                                                   ///\n");
        printf("///             - Código de Barras:                                   ///\n");
        printf("///             - Descrição do Item:                                  ///\n");
        printf("///             - Data de Validade:                                   ///\n"); 
        printf("///             - Quantidade:                                         ///\n"); 
        printf("///             - Valor do Item:                                      ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///           ESCOLHA O CAMPO À ALTERAR:                              ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Digite 'a' para alterar a descrição                  ///\n");
        printf("///            - Digite 'b' para alterar a validade                   ///\n");
        printf("///            - Digite 'c' para alterar a quantidade                 ///\n");
        printf("///            - Digite 'd' para alterar o valor                      ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

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

                if (!validaData || validaDig || validaNull) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData || validaDig || validaNull);

// ---------------------------------------------------------------------------------------

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///              Data de Validade: %s \n", dataValidade);
            printf("/// _________________________________________________________________ ///\n");
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
            printf("///                                                                   ///\n");
            printf("///            A quantidade da compra foi alterada!                   ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

// ----------------------------- Validando o valor do item -------------------------------

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

            }while (validaDig|| validaNull);

            double valor = converteCharParaDouble(valorItem);

            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                      Valor: %.2f \n", valor);       
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            O valor foi alterado!                                  ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            
        }
    }
}

/* A função telaListarCompras realiza a listagem de todas as compras. */

void telaListarCompras(void){

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
    printf("///            MÓDULO LISTAR COMPRAS:                                 ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário, suas quantidades e valores      ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n"); 
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

