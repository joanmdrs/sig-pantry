#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"

typedef struct compra Compra;

struct compra {
    long int codCompra;
    char dataCompra[11];
    char horaCompra[9];
    int quant;
    double valor;
    char status;
    
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
        printf("///            Não existem compras cadastradas com o CÓDIGO           ///\n");  
        printf("///            informado.                                             ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///             Código da compra: %ld \n",com->codCompra);
        printf("///             Data da compra: %s \n", com->dataCompra);
        printf("///             Horário da compra: %s \n", com->horaCompra);
        printf("///             Q. produtos: %d \n", com->quant);
        printf("///             Valor total: R$ %.2f \n", com->valor);
        printf("///             Status: %c \n", com->status);
        printf("///        ___________________________________________________        ///\n");

    }

    printf("///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

/*void exibirItens(Compra* com){

    if(com == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            Não existem compras cadastradas com o CÓDIGO           ///\n");  
        printf("///            informado.                                             ///\n");    
        printf("///        ___________________________________________________        ///\n");

    } else {
        printf("///                                                                   ///\n");
        printf("///             Código Item: %s \n", com->codItem);
        printf("///             Data Validade: %s \n", com->dataValidade);
        printf("///             Descrição: %s \n", com->nomeItem);
        printf("///             Quantidade: %d \n", com->quant);
        printf("///             Valor Item: R$ %.2f \n", com->valorItem);
        printf("///        ___________________________________________________        ///\n");

    }
    printf("///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
*/

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

// SEÇÃO RELACIONADA AO CADASTRO _______________________________________________________________________________

void cadastrarCompra(void){

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
    printf("///        * * *     SIG-PANTRY - Controle de Despensa   * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           = = = = =  MÓDULO CADASTRAR COMPRA: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    FILE* fp;
    FILE* fc;
    fc = fopen("compras.dat", "rb");

    Compra* com;
    Compra* comp;
    com = (Compra*) malloc(sizeof(Compra));
    comp = (Compra*) malloc(sizeof(Compra));
    double valorCompra = 0.0;

    Produto* pro;
    Produto* proe;

// ------------------------- Gerando o código da compra ----------------------------------

    com->codCompra = geraNF();

    while(fread(comp, sizeof(Compra), 1, fc)) {
        if ((comp->codCompra == com->codCompra)) {
            com->codCompra = geraNF();
        }
    }
    fclose(fc);
    printf("///            - Código da compra: %ld \n", com->codCompra);


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
        printf("///            - Horário Compra (hh:mm:ss): ");
        scanf("%[^\n]", com->horaCompra);
        getchar();
    
        validaHora = testaHora(com->horaCompra);
        validaDig = testeDigitosNumericosHora(com->horaCompra);
        validaNull = verificaNulo(com->horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

// ----------------------------- Definindo o status ----------------------------------

    com->status = 'Y';

// ----------------------------- Validando a quantidade ----------------------------------

    char quant[4];
    do{
        printf("///            - Quant. Itens da compra: ");
        scanf("%[^\n]", quant);
        getchar();
    
        validaDig = testeDigitosNumericos(quant);
        validaNull = verificaNulo(quant);

        if(validaDig || validaNull){
            printf("///            Quantidade inválida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    int q = atoi(quant);
    com->quant = q;

    for(int i = 0; i < q; i++){

        fp = fopen("produtos.dat", "r+b");
        pro = (Produto*) malloc(sizeof(Produto));
        proe = (Produto*) malloc(sizeof(Produto));
        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

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

// ----------------------------- Validando o local ----------------------------------

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

        pro->quant = atoi(quantidade);
        
        int q = atoi(quantidade);
        int achou = 0;
        while(fread(proe, sizeof(Produto), 1, fp)) {
            if (!strcmp(proe->codBarras, pro->codBarras) && !strcmp(proe->dataValidade, pro->dataValidade) && strcmp(proe->status, "x")) {
                proe->quant = proe->quant + q;
                fseek(fp, -1*sizeof(Produto), SEEK_CUR);
                fwrite(proe, sizeof(Produto), 1, fp);
                achou = 1;
                free(pro);
                break;
            }
        }
        fclose(fp);
        free(proe);

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

// ----------------------------- Calculando o valor da compra ----------------------------------

        double valor = converteCharParaDouble(preco);
        valorCompra = valorCompra + (q * valor);

// ----------------------------------------------------------------------------------

        if(achou == 0){
            strcpy(pro->status, "Y");
            gravarProduto(pro);
            free(pro);
        }
    } 

    com->valor = valorCompra;
    gravarCompra(com);
    free(com);
    
}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

long int telaPesquisarCompra(void){

    int validaDig;
    int validaNull;
    char codCompra[9];
    long int codigo;

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
    
    Compra* com;
    long int codigo;
    codigo = telaPesquisarCompra();
    com = pegarCompra(codigo);
    exibirCompra(com);
    free(com);

}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

long int telaExcluirCompra(void){

    int validaDig;
    int validaNull;
    char codCompra[9];
    long int codigo;

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

void excluirCompraLog(Compra* com){
    char resposta;
    int validaDig;
    int validaOp;
    FILE* file;
    Compra* comp;
    comp = (Compra*) malloc(sizeof(Compra));
    file = fopen("compras.dat", "r+b");

    if(com == NULL){
        exibirCompra(com);

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
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        } else if (resposta == 'N' || resposta == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operação cancelada!                                    ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
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
    
    if(com != NULL){
        excluirCompraLog(com);
    }
    free(com);
}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

long int telaAlterarCompra(void){

    int validaDig;
    int validaNull;
    char codCompra[9];
    long int codigo;

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

char* telaPreencheData(void){

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
    return dataCompra;
}

char* telaPreencheHora(void){
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

double telaPreencheValor(void){
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
            printf("///            Opcão inválida, tente novamente!\n");
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
        dataCompra = telaPreencheData();

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
        horaCompra = telaPreencheHora();
        
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
        valorCompra = telaPreencheValor();

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
    
    if(com != NULL){
        regravarCompra(com);
    }
    free(com);
}


void listarCompras(void){

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
        exibirCompra(com);
        
    }
    fclose(fp);
}

