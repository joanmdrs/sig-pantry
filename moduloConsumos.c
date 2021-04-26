#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"

typedef struct consumo Consumo;

struct consumo {
    long int codConsumo;
    char dataConsumo[11];
    char horaConsumo[9];
    int quant;
    double valor;
    char status;
};

void gravarConsumo(Consumo* con){
    FILE* file;
    file = fopen("consumos.dat", "ab");
    fwrite(con, sizeof(Consumo), 1, file);
    fclose(file);
}


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

void exibirConsumo(Consumo* con){

    if(con == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///           Não existem consumos cadastrados com o CÓDIGO           ///\n");  
        printf("///           informado.                                              ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///             Código do consumo: %ld \n",con->codConsumo);
        printf("///             Data do consumo: %s \n", con->dataConsumo);
        printf("///             Horário do consumo: %s \n", con->horaConsumo);
        printf("///             Q. produtos: %d \n", con->quant);
        printf("///             Valor total: R$ %.2f \n", con->valor);
        printf("///             Status: %c \n", con->status);
        printf("///        ___________________________________________________        ///\n");

    }

    printf("///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

// SEÇÃO RELACIONADA AO CADASTRO _______________________________________________________________________________

void cadastrarConsumo(void){
    int validaCod;
    int validaDig;
    int validaData;
    int validaHora;
    int validaNull;
    double valorConsumo = 0.0;
    int achou = 0;

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
    printf("///          = = = = =  MÓDULO CADASTRAR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    FILE* fp;
    FILE* fc;
    fc = fopen("consumos.dat", "rb");

    Consumo* con;
    Consumo* cons;
    con = (Consumo*) malloc(sizeof(Consumo));
    cons = (Consumo*) malloc(sizeof(Consumo));

    Produto* proe;

// ------------------------- Gerando o código do consumo ----------------------------------

    con->codConsumo = geraNF();

    while(fread(cons, sizeof(Consumo), 1, fc)) {
        if ((cons->codConsumo == con->codConsumo)) {
            con->codConsumo = geraNF();
        }
    }
    fclose(fc);
    printf("///            - Código do consumo: %ld \n", con->codConsumo);

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
    
// ------------------------- Validando a hora da compra ----------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm:ss): ");
        scanf("%[^\n]", con->horaConsumo);
        getchar();
    
        validaHora = testaHora(con->horaConsumo);
        validaDig = testeDigitosNumericosHora(con->horaConsumo);
        validaNull = verificaNulo(con->horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

// ----------------------------- Definindo o status ----------------------------------

    con->status = 'Y';

// ----------------------------- Validando a quantidade ----------------------------------

    char quant[4];
    do{
        printf("///            - Quant. Consumidos: ");
        scanf("%[^\n]", quant);
        getchar();
    
        validaDig = testeDigitosNumericos(quant);
        validaNull = verificaNulo(quant);

        if(validaDig || validaNull){
            printf("///            Quantidade inválida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    int q = atoi(quant);
    con->quant = q;

    for(int i = 0; i < q; i++){

        fp = fopen("produtos.dat", "r+b");
        proe = (Produto*) malloc(sizeof(Produto));
        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

// ----------------------- Validando o código de barras ----------------------------------
        char codBarras[14];
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

// ----------------------- Validando a data de validade ----------------------------------

        char dataValidade[11];
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
        
        int q = converteCharParaInt(quantidade);


        while(fread(proe, sizeof(Produto), 1, fp)) {
            if (!strcmp(proe->codBarras, codBarras) && !strcmp(proe->dataValidade, dataValidade) && strcmp(proe->status, "x")) {
                if (proe->quant > q || proe->quant == q ){
                    proe->quant = proe->quant - q;
                    printf("%d \n", proe->quant);
                    fseek(fp, -1*sizeof(Produto), SEEK_CUR);
                    fwrite(proe, sizeof(Produto), 1, fp);
                    achou = 1;
                    break;
                }
    
            }
        }
        fclose(fp);
        free(proe);

        if(achou == 0){
            
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("///           Este produto não existe na despensa ou a                ///\n");  
            printf("///           quantidade consumida é superior à quant-                ///\n");   
            printf("///           idade registrada no banco de dados.                     ///\n");                                                            
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n"); 
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            
            break;

        }else {
// ----------------------------- Validando o preço ----------------------------------

            char preco[10];
            do{
                printf("///            - Preço do Item: R$ ");
                scanf("%s", preco);
                getchar();
                
                validaDig = testeDigitosNumericosValorFlutuante(preco);

                if(validaDig){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig);

// ----------------------------- Calculando o valor do consumo ----------------------------------

            double valor = converteCharParaDouble(preco);
            valorConsumo = valorConsumo + (q * valor);

        }

    }
    if (achou == 1){
        con->valor = valorConsumo;
        gravarConsumo(con);
        free(con);
    }
}

void listarConsumos(void){

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
    printf("///          = = = = = = MÓDULO LISTAR CONSUMOS: = = = = = =          ///\n");
    printf("///                                                                   ///\n");

    FILE* fp;
    Consumo* con;
    con = (Consumo*) malloc(sizeof(Consumo));
    fp = fopen("consumos.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(fread(con, sizeof(Consumo), 1, fp)) {
        exibirConsumo(con);
        
    }
    fclose(fp);
}


