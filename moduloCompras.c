#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "moduloTestes.h"


/* A função menuCompras irá direcionar o usuário para as funções cadastrar, pesquisar,
   excluir, alterar e listas, referentes ao módulo compras. */


char menuCompras(void){
    char opcao;
    int teste = 0;

    system("clear");
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
    printf("Informe a sua opção : ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &opcao);
    getchar();
    teste = testeDigito(opcao);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira novamente um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &opcao);
        getchar();
        teste = testeDigito(opcao);
    }
	return opcao;


}

/* A função telaCadastrarCompra realiza o cadastro de uma compra. */

void telaCadastrarCompra(void){

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];
    char valorItem[10];
    int teste = 0;
    float valorCompra;
    
/// Pegando a data do sistema -----------------------------------------------------

    time_t timer;
    struct tm *horarioLocal;

    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    int dia = horarioLocal->tm_mday;
    int mes = horarioLocal->tm_mon + 1;
    int ano = horarioLocal->tm_year + 1900;

    int hora = horarioLocal->tm_hour;
    int min  = horarioLocal->tm_min;
    int sec  = horarioLocal->tm_sec;

    int vetor[6]= {dia,mes,ano,hora,min,sec};

/// --------------------------------------------------------------------------------

    system("clear");
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
    printf("///            - Código de Barras: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codBarras);
    getchar();
    teste = testeDigitos(codBarras);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codBarras);
        getchar();
        teste = testeDigitos(codBarras);
    }
    teste = 0;
    printf("///            - Descrição do Item: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", nomeItem);
    getchar();
    teste = testeDigitos(nomeItem);
    while(teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", nomeItem);
        getchar();
        teste = testeDigitos(nomeItem);
    }
    teste = 0;
    printf("///            - Data Val. (dd/mm/aaaa): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
    getchar();
    teste = testeDigitos(dataValidade);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
        getchar();
        teste = testeDigitos(dataValidade);
    }
    teste = 0;
    printf("///            - Quantidade: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", quant);
    getchar();
    teste = testeDigitos(quant);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");   
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", quant);
        getchar();
        teste = testeDigitos(quant);
    }
    teste = 0;
    int quantidade = converteCharParaInt(quant);


    printf("///            - Valor do Item: R$ "); 
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9.]", valorItem);
    getchar();
    teste = testeDigitos(valorItem);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");   
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9.]", valorItem);
        getchar();
        teste = testeDigitos(valorItem);
    }
    double valor = converteCharParaDouble(valorItem);
    teste = 0;
    
    valorCompra += quantidade * valor;
    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 Compra cadastrada com sucesso !                   ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///              Código de Barras: %s \n", codBarras);
    printf("///             Descrição do Item: %s \n", nomeItem);
    printf("///              Data de Validade: %s \n", dataValidade);
    printf("///                    Quantidade: %d \n", quantidade);
    printf("///                 Valor do Item: R$ %.2f \n", valor);
    printf("///               Valor da compra: R$ %.2f \n", valorCompra);
    printf("///                          Data: %d/%d/%d \n",vetor[0],vetor[1],vetor[2]);
    printf("///                       Horário: %d:%d:%d \n",vetor[3],vetor[4],vetor[5]);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                 >>> Tecle <ENTER> para continuar...               ///\n");
    getchar();

}

/* A função telaPesquisarCompra realiza a busca de uma compra. */

void telaPesquisarCompra(void){

    char data[11];
    char horario[9];
    int teste = 0;

    system("clear");
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
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", data);
    getchar();
    teste = testeDigitos(data);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", data);
        getchar();
        teste = testeDigitos(data);
    }
    teste = 0;
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9:]", horario);
    getchar();
    teste = testeDigitos(horario);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9:]", horario);
        getchar();
        teste = testeDigitos(horario);
    }
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALORES DE ENTRADA:                        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
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
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

/* A função telaExcluirCompra realiza a exclusão de uma compra. */

void telaExcluirCompra(void){

    char resposta;
    char data[11];
    char horario[9];
    int teste = 0;

    system("clear");
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
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", data);
    getchar();
    teste = testeDigitos(data);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", data);
        getchar();
        teste = testeDigitos(data);
    }
    teste = 0;
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9:]", horario);
    getchar();
    teste = testeDigitos(horario);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9:]", horario);
        getchar();
        teste = testeDigitos(horario);
    }
    teste = 0;
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                        VALORES DE ENTRADA:                        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
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
    printf("///            - Confirmar operação (S/N): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &resposta);
    getchar();
    teste = testeDigito(resposta);
    while(teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &resposta);
        getchar();
        teste = testeDigito(resposta);
    }
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

    }else{
        printf("///                                                                   ///\n");
        printf("///            Você informou um valor inválido!                       ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}

/* A função telaAlterarCompra realiza a alteração de uma compra. */

void telaAlterarCompra(void){

    char data[11];
    char horario[9];
    char resposta;
    char decisao;
    char respostaLetras;

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];
    char valorItem[10];
    float valorCompra;

    int teste = 0;

    system("clear");
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
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", data);
    getchar();
    teste = testeDigitos(data);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", data);
        getchar();
        teste = testeDigitos(data);
    }
    teste = 0;
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9:]", horario);
    getchar();
    teste = testeDigitos(horario);
    while(!teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9:]", horario);
        getchar();
        teste = testeDigitos(horario);
    }
    teste = 0;
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///                      VALORES DE ENTRADA:                          ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("/// _________________________________________________________________ ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n"); ///Possível resultado
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário.                                 ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");   
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n"); ///Outro possível resultado   
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          - Deseja alterar todos os items da compra (S/N) ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &resposta);
    getchar();
    teste = testeDigito(resposta);
    while(teste){
        printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &resposta);
        getchar();
        teste = testeDigito(resposta);
    }
    teste = 0;
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
        printf("///            - Código de Barras: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codBarras);
        getchar();
        teste = testeDigitos(codBarras);
        while(!teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codBarras);
            getchar();
            teste = testeDigitos(codBarras);
        }
        teste = 0;
        printf("///            - Descrição do Item: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", nomeItem);
        getchar();
        teste = testeDigitos(nomeItem);
        while(teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", nomeItem);
            getchar();
            teste = testeDigitos(nomeItem);
        }
        teste = 0;
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
        getchar();
        teste = testeDigitos(dataValidade);
        while(!teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
            getchar();
            teste = testeDigitos(dataValidade);
        }
        teste = 0;
        printf("///            - Quantidade: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", quant);
        getchar();
        teste = testeDigitos(quant);
        while(!teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");   
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", quant);
            getchar();
            teste = testeDigitos(quant);
        }
        teste = 0;
        int quantidade = converteCharParaInt(quant);


        printf("///            - Valor do Item: R$ "); 
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9.]", valorItem);
        getchar();
        teste = testeDigitos(valorItem);
        while(!teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");   
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9.]", valorItem);
            getchar();
            teste = testeDigitos(valorItem);
        }
        double valor = converteCharParaDouble(valorItem);
        teste = 0;
        
        valorCompra += quantidade * valor;
        
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///                       VALORES DE ENTRADA:                         ///\n");
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///              Código de Barras: %s \n", codBarras);
        printf("///             Descrição do Item: %s \n", nomeItem);
        printf("///              Data de Validade: %s \n", dataValidade);
        printf("///                    Quantidade: %d \n", quantidade);
        printf("///                 Valor do Item: R$ %.2f \n", valor);
        printf("///               Valor da compra: R$ %.2f \n", valorCompra);
        printf("/// _________________________________________________________________ ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Confirmar operação (S/N) ? ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &decisao);
        getchar();
        teste = testeDigito(decisao);
        while(teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &decisao);
            getchar();
            teste = testeDigito(decisao);
        }
        teste = 0;

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

        }else{
            printf("///                                                                   ///\n");
            printf("///            Você informou um valor inválido!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }

    }else if(resposta == 'N' || resposta == 'n'){
        printf("///                                                                   ///\n");
        printf("///           INFORME O ITEM A ALTERAR:                               ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Código de Barras: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codBarras);
        getchar();
        teste = testeDigitos(codBarras);
        while(!teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codBarras);
            getchar();
            teste = testeDigitos(codBarras);
        }
        teste = 0;
        printf("///            - Data de Validade (dd/mm/aaaa): ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
        getchar();
        teste = testeDigitos(dataValidade);
        while(!teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
            getchar();
            teste = testeDigitos(dataValidade);
        }
        teste = 0;
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
        printf("///            - Digite 'c' para alterar o quantidade                 ///\n");
        printf("///            - Digite 'd' para alterar o valor                      ///\n");
        printf("///        ___________________________________________________        ///\n");
        printf("///                                                                   ///\n");
        printf("///            - Informe a sua opção: "); 
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &respostaLetras);
        getchar();
        teste = testeDigito(respostaLetras);
        while(teste){
            printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", &respostaLetras);
            getchar();
            teste = testeDigito(respostaLetras);
        }
        teste = 0;

        if (respostaLetras == 'A' || respostaLetras == 'a'){
            printf("///                                                                   ///\n");
            printf("///            - a) Nova Descrição: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
            getchar();
            teste = testeDigitos(nomeItem);
            while(teste){
                printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
                scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", nomeItem);
                getchar();
                teste = testeDigitos(nomeItem);
            }
            teste = 0;
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
        }else if(resposta == 'B' || respostaLetras == 'b'){
            printf("///                                                                   ///\n");
            printf("///            - b) Nova Data Val. (dd/mm/aaaa): ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
            getchar();
            teste = testeDigitos(dataValidade);
            while(!teste){
                printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");
                scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9/]", dataValidade);
                getchar();
                teste = testeDigitos(dataValidade);
            }
            teste = 0;
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

        }else if(respostaLetras == 'C' || respostaLetras == 'c'){   
            printf("///                                                                   ///\n");
            printf("///            - c) Nova Quantidade: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", quant);
            getchar();
            teste = testeDigitos(quant);
            while(!teste){
                printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");   
                scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", quant);
                getchar();
                teste = testeDigitos(quant);
            }
            teste = 0;
            int quantidade = converteCharParaInt(quant);
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///                        VALOR DE ENTRADA:                          ///\n");
            printf("///                                                                   ///\n");
            printf("///                    Quantidade: %d \n", quantidade);       
            printf("/// _________________________________________________________________ ///\n");
            printf("///                                                                   ///\n");
            printf("///            A quantidade da compra foi alterada!                   ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }else if(respostaLetras == 'D' || respostaLetras == 'd'){
            printf("///                                                                   ///\n");
            printf("///            - d) Novo Valor: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9.]", valorItem);
            getchar();
            teste = testeDigitos(valorItem);
            while(!teste){
                printf("Você inseriu um valor incorreto, por favor, insira um valor correto: ");   
                scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9.]", valorItem);
                getchar();
                teste = testeDigitos(valorItem);
            }
            double valor = converteCharParaDouble(valorItem);
            teste = 0;
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
        }else{
            printf("///                                                                   ///\n");
            printf("///            Você informou um valor inválido!                       ///\n");
            printf("///                                                                   ///\n");
            printf("/////////////////////////////////////////////////////////////////////////\n\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

        }

    }else{
        printf("///                                                                   ///\n");
        printf("///            Você informou um valor inválido!                       ///\n");
        printf("///                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

/* A função telaListarCompras realiza a listagem de todas as compras. */

void telaListarCompras(void){
    system("clear");
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