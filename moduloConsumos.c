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
    
// ------------------------- Validando a hora do consumo ----------------------------------

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

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

long int telaPesquisarConsumo(void){

    int validaDig;
    int validaNull;
    char codConsumo[9];
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
    printf("///           = = = = =  MÓDULO PESQUISAR CONSUMO: = = = = =          ///\n");
    printf("///                                                                   ///\n");
 
    do{
        printf("///            - Código do consumo: ");
        scanf("%[^\n]", codConsumo);
        getchar();

        validaDig = testeDigitosNumericos(codConsumo);
        validaNull = verificaNulo(codConsumo);
        if(validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(validaDig || validaNull);

    codigo = atoi(codConsumo);
    return codigo;
}

Consumo* pegarConsumo(long int codigo){

    FILE* file;
    Consumo* con;

    con = (Consumo*) malloc(sizeof(Consumo));
    file = fopen("consumos.dat", "rb");

    while(fread(con, sizeof(Consumo), 1, file)){
        if(con->codConsumo == codigo && con->status != 'x'){
            fclose(file);
            return con;
        }
    }

    fclose(file);
    return NULL;
}

void pesquisarConsumo(void){
    
    Consumo* con;
    long int codigo;
    codigo = telaPesquisarConsumo();
    con = pegarConsumo(codigo);
    exibirConsumo(con);
    free(con);

}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

long int telaExcluirConsumo(void){

    int validaDig;
    int validaNull;
    char codConsumo[9];
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
    printf("///            = = = = =  MÓDULO EXCLUIR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            - Código do consumo: ");
        scanf("%[^\n]", codConsumo);
        getchar();

        validaDig = testeDigitosNumericos(codConsumo);
        validaNull = verificaNulo(codConsumo);
        if(validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(validaDig || validaNull);

    codigo = atoi(codConsumo);
    return codigo;
}

void excluirConsumoLog(Consumo* con){
    char resposta;
    int validaDig;
    int validaOp;
    FILE* file;
    Consumo* conp;
    conp = (Consumo*) malloc(sizeof(Consumo));
    file = fopen("consumos.dat", "r+b");

    if(con == NULL){
        exibirConsumo(con);

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
            while(fread(conp, sizeof(Consumo), 1, file)){
                if(conp->codConsumo == con->codConsumo && conp->status != 'x'){
                    conp->status = 'x';
                    fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                    fwrite(conp, sizeof(Consumo), 1, file);   
                    break;
                }
            }
            fclose(file);
        
            printf("///                                                                   ///\n");
            printf("///            Consumo excluído com sucesso!                          ///\n"); 
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

void excluirConsumo(void){
    Consumo* con;
    long int codigo;
    codigo = telaExcluirConsumo();
    con = pegarConsumo(codigo);
    exibirConsumo(con);
    
    if(con != NULL){
        excluirConsumoLog(con);
    }
    free(con);
}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

long int telaAlterarConsumo(void){

    int validaDig;
    int validaNull;
    char codConsumo[9];
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
    printf("///            = = = = =  MÓDULO ALTERAR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    do{
        printf("///            - Código do consumo: ");
        scanf("%[^\n]", codConsumo);
        getchar();

        validaDig = testeDigitosNumericos(codConsumo);
        validaNull = verificaNulo(codConsumo);
        if(validaDig || validaNull){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(validaDig || validaNull);

    codigo = atoi(codConsumo);
    return codigo;
}

char* telaPreencheDataConsumo(void){

    int validaData;
    int validaDig;
    int validaNull;
    char* dataConsumo;
    dataConsumo = (char*) malloc(11*sizeof(char));

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
    return dataConsumo;
}

char* telaPreencheHoraConsumo(void){
    int validaHora;
    int validaDig;
    int validaNull;
    char* horaConsumo;
    horaConsumo = (char*) malloc(9*sizeof(char));

    do{
        printf("///            - Horário Consumo (hh:mm:ss): ");
        scanf("%[^\n]", horaConsumo);
        getchar();
    
        validaHora = testaHora(horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);
        validaNull = verificaNulo(horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);
    return horaConsumo;

}

double telaPreencheValorConsumo(void){
    int validaDig;
    char valor[10];
    double valorConsumo = 0.0;

    do{
        printf("///            - Valor do consumo R$ ");
        scanf("%s", valor);
        getchar();
        
        validaDig = testeDigitosNumericosValorFlutuante(valor);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig);

    valorConsumo = converteCharParaDouble(valor);
    return valorConsumo;
}

char telaEscolhaConsumo(void){
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

void regravarConsumo(Consumo* con){

    FILE* file;
    Consumo* conp;
    conp = (Consumo*) malloc(sizeof(Consumo));
    file = fopen("consumos.dat", "r+b");
    char opcao;
   
    printf("///                                                                   ///\n");
    printf("///           ESCOLHA O QUER ALTERAR:                                 ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Digite 'a' para alterar a data do consumo            ///\n");
    printf("///            - Digite 'b' para alterar a hora do consumo            ///\n");
    printf("///            - Digite 'c' para alterar o valor do consumo           ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    opcao = telaEscolhaConsumo();

    if(opcao == 'a'){
        char* dataConsumo;
        dataConsumo = telaPreencheDataConsumo();

        while(fread(conp, sizeof(Consumo), 1, file)){
            if(conp->codConsumo == con->codConsumo && conp->status != 'x'){
                strcpy(conp->dataConsumo, dataConsumo);
                fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                fwrite(conp, sizeof(Consumo), 1, file);
                break;
            }
        }
        fclose(file);
        free(dataConsumo);
        free(conp);
        printf("///                                                                   ///\n");
        printf("///            A data do consumo foi alterada!                        ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'b'){
        char* horaConsumo;
        horaConsumo = telaPreencheHoraConsumo();
        
        while(fread(conp, sizeof(Consumo), 1, file)){
            if(conp->codConsumo == con->codConsumo && conp->status != 'x'){
                strcpy(conp->horaConsumo, horaConsumo);
                fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                fwrite(conp, sizeof(Consumo), 1, file);
                break;
            }
        }
        fclose(file);
        free(horaConsumo);
        free(conp);
        printf("///                                                                   ///\n");
        printf("///            A hora do consumo foi alterada!                        ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }else if(opcao == 'c'){
        double valorConsumo = 0.0;
        valorConsumo = telaPreencheValorConsumo();

        while(fread(conp, sizeof(Consumo), 1, file)){
            if(conp->codConsumo == con->codConsumo && conp->status != 'x'){
                conp->valor = valorConsumo;
                fseek(file, -1*sizeof(Consumo), SEEK_CUR);
                fwrite(conp, sizeof(Consumo), 1, file);
                break;
            }
        }
        fclose(file);
        free(conp);
        printf("///                                                                   ///\n");
        printf("///            O valor do consumo foi alterado!                       ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();

    }
    fclose(file);
}

void alterarConsumo(void){
    Consumo* con;
    long int codigo;
    codigo = telaAlterarConsumo();
    con = pegarConsumo(codigo);
    exibirConsumo(con);
    
    if(con != NULL){
        regravarConsumo(con);
    }
    free(con);
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


