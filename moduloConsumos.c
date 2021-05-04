#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"
#include "moduloProdutos.h"
#include "moduloUtil.h"

typedef struct consumo Consumo;

struct consumo {
    long int codConsumo;
    char dataConsumo[11];
    char horaConsumo[9];
    int quant;
    double valor;
    char status;
    struct consumo *prox;
};

typedef struct itemC ItemC;

struct itemC {
    long int codConsumo;
    char descricao[51];
    int quant;
    double valor;
};

void gravarConsumo(Consumo* con){
    FILE* file;
    file = fopen("consumos.dat", "ab");
    fwrite(con, sizeof(Consumo), 1, file);
    fclose(file);
}

void gravarItemC(ItemC* item){
    FILE* file;
    file = fopen("itensCon.dat", "ab");
    fwrite(item, sizeof(ItemC), 1, file);
    fclose(file);
}

long int geraCodConsumo(void){

    FILE* fc;
    fc = fopen("consumos.dat", "rb");

    Consumo* con;
    con = (Consumo*) malloc(sizeof(Consumo));

    long int codConsumo;

    codConsumo = geraNF();

    while(fread(con, sizeof(Consumo), 1, fc)) {
        if ((con->codConsumo == codConsumo)) {
            codConsumo = geraNF();
        }
    }
    fclose(fc);
    free(con);

    return codConsumo;
}

long int preencheCodConsumo(){
    int validaDig;
    int validaNull;
    char codConsumo[9];
    long int codigo;

    do{
        printf("///            - Codigo do consumo: ");
        scanf("%[^\n]", codConsumo);
        getchar();

        validaDig = testeDigitosNumericos(codConsumo);
        validaNull = verificaNulo(codConsumo);
        if(validaDig || validaNull){
			printf("///            Codigo invalido, tente novamente !\n");
		}

	}while(validaDig || validaNull);
    codigo = converteCharParaInt(codConsumo);
    return codigo;
}

char* preencheDataConsumo(void){
    
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
            printf("///            Data invalida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);
    char* dataAux;
    dataAux = dataInvertida(dataConsumo);
    free(dataConsumo);
    return dataAux;
}

char* preencheHoraConsumo(void){

    int validaHora;
    int validaDig;
    int validaNull;

    char* horaConsumo;
    horaConsumo = (char*) malloc(9*sizeof(char));

    do{
        printf("///            - Horario Consumo (hh:mm:ss): ");
        scanf("%[^\n]", horaConsumo);
        getchar();
    
        validaHora = testaHora(horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);
        validaNull = verificaNulo(horaConsumo);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora invalida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return horaConsumo;
}

char* preencheQuantConsumo(void){
    int validaDig;
    int validaNull;
    
    char* quantC;
    quantC = (char*) malloc(20*sizeof(char));

    do{
        printf("///            - Quant. Itens Consumidos: ");
        scanf("%[^\n]", quantC);
        getchar();
    
        validaDig = testeDigitosNumericos(quantC);
        validaNull = verificaNulo(quantC);  

        if(validaDig || validaNull){
            printf("///            Quantidade invalida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    return quantC;
}

double preencheValorConsumo(void){
    int validaDig;
    char valor[10];
    double valorConsumo = 0.0;

    do{
        printf("///            - Valor do consumo R$ ");
        scanf("%s", valor);
        getchar();
        
        validaDig = testeDigitosNumericosValorFlutuante(valor);

        if(validaDig){
            printf("///            Digitos invalidos, tente novamente !\n");
        }

    }while (validaDig);

    valorConsumo = converteCharParaDouble(valor);
    return valorConsumo;
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
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
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
        printf("Informe a sua opcao : ");
        scanf("%[^\n]", &opcao);
        getchar();

        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, 5); 

        if(!validaOp || !validaOpM){
            printf("Opcao invalida, tente novamente!\n");
        }

    }while(!validaOp || !validaOpM);
	return opcao;
}

void mostraConsumos(Consumo* con){
    printf("            %ld\t", con->codConsumo);
    
    char* data = dataReinvertida(con->dataConsumo);
    strcpy(con->dataConsumo, data); 
    free(data);
    
    printf("%s\t", con->dataConsumo);
    printf("%s\t", con->horaConsumo);
    printf("%d\t", con->quant);
    printf("R$%.2f\t\t",con->valor);
    printf("%c\n", con->status);
}

void exibirConsumo(Consumo* con){

    if(con == NULL){
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///           Nao existem consumos cadastrados com o CODIGO           ///\n");  
        printf("///           informado.                                              ///\n");    
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        exibeTecleEnter();

    } else {
        printf("///        ___________________________________________________        \n");
        printf("///                                                                   \n");
        printf("///              Codigo do consumo: %ld \n",con->codConsumo);
    
        char* data = dataReinvertida(con->dataConsumo);
        strcpy(con->dataConsumo, data); 
        free(data);

        printf("///                Data do consumo: %s \n", con->dataConsumo);
        printf("///             Horario do consumo: %s \n", con->horaConsumo);
        printf("///                  Qtd. produtos: %d \n", con->quant);
        printf("///                    Valor total: R$ %.2f \n", con->valor);
        printf("///        ___________________________________________________        \n");
        printf("///                                                                   \n");
    }

}

void exibirItemC(ItemC* item){
    printf("///%23s\t", item->descricao);
    printf("%d\t", item->quant);
    printf("R$ %.2f\n", item->valor);
}

// SEÇÃO RELACIONADA AO CADASTRO _______________________________________________________________________________

void cadastrarConsumo(void){

    double valorConsumo = 0.0;
    int certeza = 0;
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
    printf("///          = = = = =  MODULO CADASTRAR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    FILE* fp;

    Consumo* con;
    con = (Consumo*) malloc(sizeof(Consumo));

    Produto* pro;
    Produto* proe;
    ItemC* item;

// ------------------------- Gerando o código do consumo ----------------------------------

    long int codConsumo = geraCodConsumo();

    printf("///            - Codigo do consumo: %ld \n", codConsumo);

    con->codConsumo = codConsumo;

    char* dataConsumo = preencheDataConsumo();
    strcpy(con->dataConsumo, dataConsumo);
    free(dataConsumo);

    char* horaConsumo = preencheHoraConsumo();
    strcpy(con->horaConsumo, horaConsumo);
    free(horaConsumo);

    char* quant;
    quant = preencheQuantConsumo();
    int q;
    q = converteCharParaInt(quant);

    con->status = 'Y';

    con->prox = NULL;

    for(int i = 0; i < q; i++){

        fp = fopen("produtos.dat", "r+b");
        pro = (Produto*) malloc(sizeof(Produto));
        proe = (Produto*) malloc(sizeof(Produto));
        item = (ItemC*) malloc(sizeof(ItemC));

        printf("///\n");
        printf("///            Item %d \n", i+1);
        printf("///\n");

        item->codConsumo = con->codConsumo;

        char* codBarras = preencheCodBarras();
        strcpy(pro->codBarras, codBarras);
        free(codBarras);

        char* dataValidade = preencheDataValidade();
        strcpy(pro->dataValidade, dataValidade);
        free(dataValidade);

        char* quantP;
        quantP = preencheQuantPro();
        int quantidadeP;
        quantidadeP = converteCharParaInt(quantP);
        pro->quant = quantidadeP;
        item->quant = quantidadeP;

        int achou = 0;

        while(fread(proe, sizeof(Produto), 1, fp)) {
            if (!strcmp(proe->codBarras, pro->codBarras) && !strcmp(proe->dataValidade, pro->dataValidade) && strcmp(proe->status, "x")) {
                if (proe->quant > q || proe->quant == quantidadeP ){
                    proe->quant = proe->quant - quantidadeP;
                    strcpy(item->descricao, proe->nomeItem);
                    fseek(fp, -1*sizeof(Produto), SEEK_CUR);
                    fwrite(proe, sizeof(Produto), 1, fp);
                    achou = 1;
                    certeza += 1;
                    free(pro);
                    break;
                }
            }
        }
        fclose(fp);
        free(proe);

        if(achou == 0){
            
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n");
            printf("///           Este produto nao existe na despensa ou a                ///\n");  
            printf("///           quantidade consumida e superior a quant-                ///\n");   
            printf("///           idade registrada no banco de dados.                     ///\n");                                                            
            printf("///        ___________________________________________________        ///\n");
            printf("///                                                                   ///\n"); 
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            break;

        }else if(achou == 1){
            double preco = preenchePrecoItem();
            item->valor = preco;
            valorConsumo = valorConsumo + (quantidadeP * preco);
            gravarItemC(item);
            free(item);
        } 
    }

    if(certeza > 0){
        con->quant = certeza;
        con->valor = valorConsumo;
        gravarConsumo(con);
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///                  Consumo cadastrado com sucesso !                 ///\n");
        exibirConsumo(con);
        exibeTecleEnter();
        free(con);
    }

}

// SEÇÃO RELACIONADA À PESQUISA ________________________________________________________________________________

long int telaPesquisarConsumo(void){

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
    printf("///           = = = = =  MODULO PESQUISAR CONSUMO: = = = = =          ///\n");
    printf("///                                                                   ///\n");
 
    long int codigo;
    codigo = preencheCodConsumo();
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
    FILE* fi;
    ItemC* item;
    item = (ItemC*) malloc(sizeof(ItemC));
    Consumo* con;
    long int codigo;
    codigo = telaPesquisarConsumo();
    con = pegarConsumo(codigo);
    exibirConsumo(con);
    fi = fopen("itensCon.dat", "rb");
    if(con != NULL){ 
        printf("///        = = = = = = = = = LISTA DE ITENS = = = = = = = = =          \n");
        printf("///\n");
        printf("///                Produto:    Qtd.:    Preco:\n");
        printf("///\n");
        while(fread(item, sizeof(ItemC), 1, fi)){
            if(con->codConsumo == item->codConsumo){
                exibirItemC(item);
            }
        }
        printf("///\n");
        exibeTecleEnter();
    }
    fclose(fi);
    free(item);
    free(con);

}

// SEÇÃO RELACIONADA À EXCLUSÃO ________________________________________________________________________________

long int telaExcluirConsumo(void){

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
    printf("///            = = = = =  MODULO EXCLUIR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    long int codigo;
    codigo = preencheCodConsumo();
    return codigo;
}

void excluirConsumoLog(Consumo* con){
    char confirma;
    FILE* file;
    Consumo* conp;
    conp = (Consumo*) malloc(sizeof(Consumo));
    file = fopen("consumos.dat", "r+b");

    if(con == NULL){
        exibirConsumo(con);

    } else{
        confirma = confirmaExclusao();

        if (confirma == 'S' || confirma == 's'){
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
            printf("///            Consumo excluido com sucesso!                          ///\n"); 
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        } else if (confirma == 'N' || confirma == 'n'){
            printf("///                                                                   ///\n");
            printf("///            Operacao cancelada!                                    ///\n"); 
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
    //exibeTecleEnter();
    
    if(con != NULL){
        excluirConsumoLog(con);
    }
    free(con);
}

// SEÇÃO RELACIONADA À ALTERAÇÃO ________________________________________________________________________________

long int telaAlterarConsumo(void){

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
    printf("///            = = = = =  MODULO ALTERAR CONSUMO: = = = = =           ///\n");
    printf("///                                                                   ///\n");

    long int codigo;
    codigo = preencheCodConsumo();
    return codigo;
}

char telaEscolhaConsumo(void){
    int validaDig;
    int validaOp;
    char opcao;

    do{
        printf("///            - Informe a sua opcao: ");
        scanf("%[^\n]", &opcao);
        getchar();

        validaDig = testeDigito(opcao);
        validaOp = validaOpcaoLetrasAC(opcao);
        
        if(!validaOp || validaDig){
            printf("///            Opcao invalida, tente novamente!\n");
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
        dataConsumo = preencheDataConsumo();

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
        horaConsumo = preencheHoraConsumo();
        
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
        valorConsumo = preencheValorConsumo();

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
    //exibeTecleEnter();
    
    if(con != NULL){
        regravarConsumo(con);
    }
    free(con);
}

void listarConsumos(void){

    limpaTela();
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                             ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * *     SIG-PANTRY - Controle de Despensa     * * * * * * * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        *****************************************************************************        ///\n");
    printf("///        _____________________________________________________________________________        ///\n");
    printf("///                                                                                             ///\n");
    printf("///         = = = = = = = = = = = = = MODULO - LISTAR CONSUMOS = = = = = = = = = = = = =        ///\n\n");
    printf("            Codigo:     Data:           Hora:         Qtd.:     Valor:        Status:            \n\n");

    FILE* fp;
    Consumo* con;
    con = (Consumo*) malloc(sizeof(Consumo));
    fp = fopen("consumos.dat", "rb");

    if (fp == NULL) {
        exibeErroArquivo();
    }else{
        while(fread(con, sizeof(Consumo), 1, fp)) {
            mostraConsumos(con);
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    free(con);
    fclose(fp);
}


