#include <stdio.h>
#include <stdlib.h>
#include "moduloValidacoes.h"

/* A função menuConsumo irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listar, referentes ao módulo consumo. */

char menuConsumo(void){
    char opcao;
    int q = 5;
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
        scanf("%c", &opcao);
        getchar();

        validaOp = testeDigito(opcao);
        validaOpM = validaOpcaoMenu(opcao, q); 

        if(!validaOp || !validaOpM){
            printf("Opção inválida, tente novamente!\n");

        }

    }while(!validaOp || !validaOpM);

	return opcao;

}

/* A função telaCadastrarConsumo realiza o cadastro de um consumo. */

void telaCadastrarConsumo(void){
    
    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];
    char dataConsumo[11];
    char horaConsumo[6];

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
    int validaDig;
    int validaData;
    int validaHora;
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

// ----------------------- Validando o código de barras ----------------------------------

    do{
        printf("///            - Código de Barras: ");
        scanf("%s", codBarras);
        getchar();
    
		validaCod = validaCodBarras(codBarras);
        validaDig = testeDigitosNumericos(codBarras);

		if(!validaCod || validaDig){
			printf("///            Código inválido, tente novamente !\n");
		}

	}while(!validaCod || validaDig);

// ----------------------- Validando a descrição do produto ------------------------------

    do{
        printf("///            - Descrição do Item: ");
        scanf("%s", nomeItem);
        getchar();

        validaDig = testeDigitos(nomeItem);

        if(validaDig){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig);

// ----------------------- Validando a data de validade ----------------------------------

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%s", dataValidade);
        getchar();

        dia[0] = dataValidade[0];
		dia[1] = dataValidade[1];
		diaC = converteCharParaInt(dia);

		mes[0] = dataValidade[3];
		mes[1] = dataValidade[4];
		mesC = converteCharParaInt(mes);

		ano[0] = dataValidade[6];
		ano[1] = dataValidade[7];
		ano[2] = dataValidade[8];
		ano[3] = dataValidade[9];
		anoC = converteCharParaInt(ano);
    
        validaData = testaData(diaC, mesC, anoC, dataValidade);
        validaDig = testeDigitosNumericosData(dataValidade);

        if (!validaData || validaDig) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig);

// ----------------------------- Validando a quantidade ----------------------------------
      
    do{
        printf("///            - Quantidade: ");
        scanf("%s", quant);
        getchar();
        
        validaDig = testeDigitosNumericos(quant);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig);

    quantC = converteCharParaInt(quant);

// ------------------------- Validando a data do consumo ----------------------------------

    do{
        printf("///            - Data Consumo (dd/mm/aaaa): ");
        scanf("%s", dataConsumo);
        getchar();

        dia[0] = dataConsumo[0];
		dia[1] = dataConsumo[1];
		diaC = converteCharParaInt(dia);

		mes[0] = dataConsumo[3];
		mes[1] = dataConsumo[4];
		mesC = converteCharParaInt(mes);

		ano[0] = dataConsumo[6];
		ano[1] = dataConsumo[7];
		ano[2] = dataConsumo[8];
		ano[3] = dataConsumo[9];
		anoC = converteCharParaInt(ano);
    
        validaData = testaData(diaC, mesC, anoC, dataConsumo);
        validaDig = testeDigitosNumericosData(dataConsumo);

        if (!validaData || validaDig) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig);

// ------------------------- Validando a hora do consumo ----------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%s", horaConsumo);
        getchar();

        hora[0] = horaConsumo[0];
        hora[1] = horaConsumo[1];
		horaC = converteCharParaInt(hora);

		minutos[0] = horaConsumo[3];
        minutos[1] = horaConsumo[4];
        minutosC = converteCharParaInt(minutos);
    
        validaHora = testaHora(horaC, minutosC, horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);

        if (!validaHora || validaDig) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig);
    
// ---------------------------------------------------------------------------------------

    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Consumo cadastrado com sucesso !                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///              Código de Barras: %s \n", codBarras);
    printf("///             Descrição do Item: %s \n", nomeItem);
    printf("///              Data de Validade: %s \n", dataValidade);
    printf("///                    Quantidade: %d \n", quantC);
    printf("///                          Data: %s \n", dataConsumo);
    printf("///                       Horário: %s \n", horaConsumo);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 >>> Tecle <ENTER> para continuar...               ///\n");
    getchar();
}

/* A função telaPesquisarConsumo realiza a busca de um consumo. */

void telaPesquisarConsumo(void){

    char dataConsumo[11];
    char horaConsumo[9];
    
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

    int validaDig;
    int validaData;
    int validaHora;

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
        scanf("%s", dataConsumo);
        getchar();

        dia[0] = dataConsumo[0];
		dia[1] = dataConsumo[1];
		diaC = converteCharParaInt(dia);

		mes[0] = dataConsumo[3];
		mes[1] = dataConsumo[4];
		mesC = converteCharParaInt(mes);

		ano[0] = dataConsumo[6];
		ano[1] = dataConsumo[7];
		ano[2] = dataConsumo[8];
		ano[3] = dataConsumo[9];
		anoC = converteCharParaInt(ano);
    
        validaData = testaData(diaC, mesC, anoC, dataConsumo);
        validaDig = testeDigitosNumericosData(dataConsumo);

        if (!validaData || validaDig) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig);

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%s", horaConsumo);
        getchar();

        hora[0] = horaConsumo[0];
        hora[1] = horaConsumo[1];
		horaC = converteCharParaInt(hora);

		minutos[0] = horaConsumo[3];
        minutos[1] = horaConsumo[4];
        minutosC = converteCharParaInt(minutos);
    
        validaHora = testaHora(horaC, minutosC, horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);

        if (!validaHora || validaDig) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALORES DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data do consumo: %s \n", dataConsumo);
    printf("///             Horário do consumo: %s \n", horaConsumo);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele dia e horário e suas quantidades               ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário da consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

/* A função telaExcluirConsumo realiza a exclusão de um consumo. */

void telaExcluirConsumo(void){

    char resposta;
    char dataConsumo[11];
    char horaConsumo[9];

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
        scanf("%s", dataConsumo);
        getchar();

        dia[0] = dataConsumo[0];
		dia[1] = dataConsumo[1];
		diaC = converteCharParaInt(dia);

		mes[0] = dataConsumo[3];
		mes[1] = dataConsumo[4];
		mesC = converteCharParaInt(mes);

		ano[0] = dataConsumo[6];
		ano[1] = dataConsumo[7];
		ano[2] = dataConsumo[8];
		ano[3] = dataConsumo[9];
		anoC = converteCharParaInt(ano);
    
        validaData = testaData(diaC, mesC, anoC, dataConsumo);
        validaDig = testeDigitosNumericosData(dataConsumo);

        if (!validaData || validaDig) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig);

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%s", horaConsumo);
        getchar();

        hora[0] = horaConsumo[0];
        hora[1] = horaConsumo[1];
		horaC = converteCharParaInt(hora);

		minutos[0] = horaConsumo[3];
        minutos[1] = horaConsumo[4];
        minutosC = converteCharParaInt(minutos);
    
        validaHora = testaHora(horaC, minutosC, horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);

        if (!validaHora || validaDig) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                       VALORES DE ENTRADA:                         ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data do consumo: %s \n", dataConsumo);
    printf("///             Horário do consumo: %s \n", horaConsumo);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Itens: Aqui vai mostrar todos os itens consumidos    ///\n");
    printf("///              naquele dia e horário, e suas quantidades.           ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%c", &resposta);
        getchar();

        validaDig = testeDigito(resposta);
        validaOp = validaOpcao(resposta);
        

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }

    }while(!validaOp || validaDig);

// ---------------------------------------------------------------------------------------

    if (resposta == 'S' || resposta == 's'){
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

}

/* A função telaAlterarConsumo realiza a alteração de um consumo. */

void telaAlterarConsumo(void){

    char dataConsumo[11];
    char horaConsumo[9];
    char resposta;
    char decisao;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];

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
        scanf("%s", dataConsumo);
        getchar();

        dia[0] = dataConsumo[0];
		dia[1] = dataConsumo[1];
		diaC = converteCharParaInt(dia);

		mes[0] = dataConsumo[3];
		mes[1] = dataConsumo[4];
		mesC = converteCharParaInt(mes);

		ano[0] = dataConsumo[6];
		ano[1] = dataConsumo[7];
		ano[2] = dataConsumo[8];
		ano[3] = dataConsumo[9];
		anoC = converteCharParaInt(ano);
    
        validaData = testaData(diaC, mesC, anoC, dataConsumo);
        validaDig = testeDigitosNumericosData(dataConsumo);

        if (!validaData || validaDig) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig);

// ---------------------------------------------------------------------------------------

    do{
        printf("///            - Horário Consumo (hh:mm): ");
        scanf("%s", horaConsumo);
        getchar();

        hora[0] = horaConsumo[0];
        hora[1] = horaConsumo[1];
		horaC = converteCharParaInt(hora);

		minutos[0] = horaConsumo[3];
        minutos[1] = horaConsumo[4];
        minutosC = converteCharParaInt(minutos);
    
        validaHora = testaHora(horaC, minutosC, horaConsumo);
        validaDig = testeDigitosNumericosHora(horaConsumo);

        if (!validaHora || validaDig) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig);

// ---------------------------------------------------------------------------------------

    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                      VALORES DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data do consumo: %s \n", dataConsumo);
    printf("///             Horário do consumo: %s \n", horaConsumo);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n"); ///Possível resultado
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele dia e horário.                                 ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo                                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n"); ///Outro possível resultado   
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

// ---------------------------------------------------------------------------------------

    do{
        printf("///          - Deseja alterar todos os items da consumo (S/N) ");
        scanf("%c", &resposta);
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
            scanf("%s", codBarras);
            getchar();
        
            validaCod = validaCodBarras(codBarras);

            if(!validaCod){
                printf("///            Código inválido, tente novamente !\n");
            }

        }while(!validaCod);

// ----------------------- Validando a descrição do produto ------------------------------

        do{
            printf("///            - Descrição do Item: ");
            scanf("%s", nomeItem);
            getchar();

            validaDig = testeDigitos(nomeItem);

            if(validaDig){
                printf("///            Caracteres inválidos, tente novamente !\n");
            }
        
        }while (validaDig);

// ----------------------- Validando a data de validade ----------------------------------

        do{
            printf("///            - Data Val. (dd/mm/aaaa): ");
            scanf("%s", dataValidade);
            getchar();

            dia[0] = dataValidade[0];
            dia[1] = dataValidade[1];
            diaC = converteCharParaInt(dia);

            mes[0] = dataValidade[3];
            mes[1] = dataValidade[4];
            mesC = converteCharParaInt(mes);

            ano[0] = dataValidade[6];
            ano[1] = dataValidade[7];
            ano[2] = dataValidade[8];
            ano[3] = dataValidade[9];
            anoC = converteCharParaInt(ano);
        
            validaData = testaData(diaC, mesC, anoC, dataValidade);
            validaDig = testeDigitosNumericosData(dataValidade);

            if (!validaData || validaDig) {
                printf("///            Data inválida, tente novamente !\n");
            }

        }while(!validaData || validaDig);

// ----------------------------- Validando a quantidade ----------------------------------
      
        do{
            printf("///            - Quantidade: ");
            scanf("%s", quant);
            getchar();
            
            validaDig = testeDigitosNumericos(quant);

            if(validaDig){
                printf("///            Dígitos inválidos, tente novamente !\n");
            }

        }while (validaDig);

        quantC = converteCharParaInt(quant);


        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
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
            scanf("%c", &decisao);
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
            printf("///            Consumo alterado com sucesso!                           ///\n"); 
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
            scanf("%s", codBarras);
            getchar();
        
            validaCod = validaCodBarras(codBarras);

            if(!validaCod){
                printf("///            Código inválido, tente novamente !\n");
            }

        }while(!validaCod);

// ----------------------- Validando a data de validade ----------------------------------

        do{
            printf("///            - Data de Validade (dd/mm/aaaa): ");
            scanf("%s", dataValidade);
            getchar();

            dia[0] = dataValidade[0];
            dia[1] = dataValidade[1];
            diaC = converteCharParaInt(dia);

            mes[0] = dataValidade[3];
            mes[1] = dataValidade[4];
            mesC = converteCharParaInt(mes);

            ano[0] = dataValidade[6];
            ano[1] = dataValidade[7];
            ano[2] = dataValidade[8];
            ano[3] = dataValidade[9];
            anoC = converteCharParaInt(ano);
        
            validaData = testaData(diaC, mesC, anoC, dataValidade);
            validaDig = testeDigitosNumericosData(dataValidade);

            if (!validaData || validaDig) {
                printf("///            Data inválida, tente novamente !\n");
            }

        }while(!validaData || validaDig);

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
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            ITEM NÃO ENCONTRADO !                                  ///\n");
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
            scanf("%c", &respostaLetras);
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
                scanf("%s", nomeItem);
                getchar();

                validaDig = testeDigitos(nomeItem);

                if(validaDig){
                    printf("///            Caracteres inválidos, tente novamente !\n");
                }

            }while (validaDig);

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
                scanf("%s", dataValidade);
                getchar();

                dia[0] = dataValidade[0];
                dia[1] = dataValidade[1];
                diaC = converteCharParaInt(dia);

                mes[0] = dataValidade[3];
                mes[1] = dataValidade[4];
                mesC = converteCharParaInt(mes);

                ano[0] = dataValidade[6];
                ano[1] = dataValidade[7];
                ano[2] = dataValidade[8];
                ano[3] = dataValidade[9];
                anoC = converteCharParaInt(ano);
            
                validaData = testaData(diaC, mesC, anoC, dataValidade);
                validaDig = testeDigitosNumericosData(dataValidade);

                if (!validaData ) {
                    printf("///            Data inválida, tente novamente !\n");
                }

            }while(!validaData);

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
                scanf("%s", quant);
                getchar();
                
                validaDig = testeDigitosNumericos(quant);

                if(validaDig){
                    printf("///            Dígitos inválidos, tente novamente !\n");
                }

            }while (validaDig);

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