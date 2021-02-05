///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///           Projeto Sistema de Controle de Despensa Doméstica             ///
///              Developed by  @allangbr @joanmdrs - Jan, 2021              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char menuPrincipal(void);

char menuProdutos(void);
void telaCadastrarProduto(void);
void telaPesquisarProduto(void);
void telaExcluirProduto(void);
void telaAlterarProduto(void);
void telaListarProdutos(void);

char menuCompras(void);
void telaCadastrarCompra(void);
void telaPesquisarCompra(void);
void telaExcluirCompra(void);
void telaAlterarCompra(void);
void telaListarCompras(void);

char menuConsumo(void);
void telaCadastrarConsumo(void);
void telaPesquisarConsumo(void);
void telaExcluirConsumo(void);
void telaAlterarConsumo(void);
void telaListarConsumos(void);

void menuSobre(void);

int main(void) {
    char opcao1, opcao2, opcao3, opcao4;

    
    ///opcao1 = menuPrincipal();

    ///opcao2 = menuProdutos();
    ///telaCadastrarProduto();
    ///telaPesquisarProduto();
    ///telaExcluirProduto();
    ///telaAlterarProduto();
    ///telaListarProdutos();

    ///opcao3 = menuCompras();
    ///telaCadastrarCompra();
    ///telaPesquisarCompra();
    ///telaExcluirCompra();
    telaAlterarCompra();
    ///telaListarCompras();

    ///opcao4 = menuConsumo();
    ///telaCadastrarConsumo();
    ///telaPesquisarConsumo();
    ///telaExcluirConsumo();
    ///telaAlterarConsumo();
    ///telaListarConsumos();

    ///menuSobre();
    
    return 0;

}

char menuPrincipal(void){
    char opcao;

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
    printf("///            MENU:                                                  ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Módulo Produtos                                    ///\n");
    printf("///            2 - Módulo Compras                                     ///\n");
    printf("///            3 - Módulo Consumo                                     ///\n");
    printf("///            4 - Sobre o Sistema                                    ///\n");
    printf("///            0 - Encerrar Programa                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("Informe a sua opção : ");
    scanf("%c", &opcao);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return opcao;

}

char menuProdutos(void){
    char opcao;

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
    printf("///            PRODUTOS:                                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            1 - Cadastrar produto                                  ///\n");
    printf("///            2 - Pesquisar produto                                  ///\n");
    printf("///            3 - Excluir produto                                    ///\n");
    printf("///            4 - Alterar produto                                    ///\n");
    printf("///            5 - Listar produtos                                    ///\n");
    printf("///            0 - Voltar                                             ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("Informe a sua opção : ");
    scanf("%c", &opcao);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return opcao;


}

void telaCadastrarProduto(void){

    char codBarras[14];
    char descricao[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char resposta;
    int quant;

    system("clear");
    printf("\n");
    printf(" ***************************************************\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" * * *     SIGPENTRY - Controle de Despensa    * * *\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" ***************************************************\n");
    printf("                                                    \n");
    printf("   = = = = =  MÓDULO CADASTRAR PRODUTO: = = = = =   \n");
    printf("                                                    \n");
    printf("     Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("     Descrição: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", descricao);
    getchar();
    printf("     Data Val. (dd/mm/aaaa): ");
    scanf("%[0-9/]", dataValidade);
    getchar();
    printf("     Local: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", local);
    getchar();
    printf("     Status: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", status);
    getchar();
    printf("     Quantidade: ");
    scanf("%d", &quant);
    getchar();
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("        Produto(s) cadastrado(s) com sucesso !      \n");
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("        Código de Barras: %s \n", codBarras);
    printf("               Descrição: %s \n", descricao);
    printf("        Data de Validade: %s \n", dataValidade);
    printf("                   Local: %s \n", local);
    printf("                  Status: %s \n", status);
    printf("              Quantidade: %d \n", quant);
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("         >>> Tecle <ENTER> para continuar...        \n");
    getchar();

}

void telaPesquisarProduto(void){
    char codBarras[14];
    
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
    printf("///            MÓDULO PESQUISAR PRODUTO:                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            PRODUTO LOCALIZADO!                                    ///\n"); ///se encontrar
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///            Não existem produtos cadastrados com o código          ///\n"); ///se não encontrar   
    printf("///            de barras informado.                                   ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaExcluirProduto(void){
    char codBarras[14];
    char resposta[1];

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
    printf("///            MÓDULO EXCLUIR PRODUTO:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            PRODUTO LOCALIZADO!                                    ///\n"); ///se encontrar
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///            Não existem produtos cadastrados com o código          ///\n"); ///se não encontrar   
    printf("///            de barras informado.                                   ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/n) ? ");
    scanf("%c", resposta);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            Produto excluído com sucesso!                          ///\n"); /// se a opção for sim
    printf("///            Operação cancelada!                                    ///\n"); /// se a opção for não
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAlterarProduto(void){
    char codBarras[14];
    char nome[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char resposta[1];
    char respostaLetras[1];

    int quant;

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
    printf("///            MÓDULO ALTERAR PRODUTO:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            PRODUTO LOCALIZADO!                                    ///\n"); ///se encontrar
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///            Não existem produtos cadastrados com o código          ///\n");  ///se não encontrar  
    printf("///            de barras informado.                                   ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Deseja alterar todos os valores (S/n)? ");
    scanf("%c", resposta);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            - Novo Nome: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            - Nova Data de Validade (dd/mm/aaaa): ");
    scanf("%[0-9/]", dataValidade);
    getchar();
    printf("///            - Novo Local: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", local);
    getchar();
    printf("///            - Novo Status: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", status);
    getchar();
    printf("///            - Nova Quantidade: ");
    scanf("%d", &quant);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            - Digite 'a' para alterar o nome                       ///\n"); ///Se não
    printf("///            - Digite 'b' para alterar a validade                   ///\n");
    printf("///            - Digite 'c' para alterar o local                      ///\n");
    printf("///            - Digite 'd' para alterar o status                     ///\n");
    printf("///            - Digite 'e' para alterar a quantidade: ");
    scanf("%[A-E a-e]", respostaLetras);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            - a) Novo Nome: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            - b) Nova Data de Validade (dd/mm/aaaa): ");
    scanf("%[0-9/]", dataValidade);
    getchar();
    printf("///            - c) Novo Local: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", local);
    getchar();
    printf("///            - d) Novo Status: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", status);
    getchar();
    printf("///            - e) Nova Quantidade: ");
    scanf("%d", &quant);
    getchar();         
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/n) ? ");
    scanf("%c", resposta);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            Produto alterado com sucesso!                          ///\n"); ///Se a resposta for sim
    printf("///            Operação cancelada!                                    ///\n"); ///Se a resposta for não
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaListarProdutos(void){
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
    printf("///            MÓDULO LISTAR PRODUTOS:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Codigo de Barras:                                    ///\n");
    printf("///            - Nome:                                                ///\n");
    printf("///            - Data de Validade:                                    ///\n");
    printf("///            - Local:                                               ///\n");
    printf("///            - Status:                                              ///\n");
    printf("///            - Quantidade:                                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    /* No módulo listar produtos, serão exibidos todos os items existentes na despensa, 
       com todos os seus respectivos campos, um abaixo do outro.
    */


}

char menuCompras(void){
    char opcao;

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
    scanf("%c", &opcao);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return opcao;


}

void telaCadastrarCompra(void){

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    int quant;
    float valorItem;
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
    printf(" ***************************************************\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" * * *     SIGPENTRY - Controle de Despensa    * * *\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" ***************************************************\n");
    printf("                                                    \n");
    printf("   = = = = = = MÓDULO CADASTRAR COMPRA: = = = = = = \n");
    printf("                                                    \n");
    printf("     Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("     Descrição do Item: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeItem);
    getchar();
    printf("     Data Val. (dd/mm/aaaa): ");
    scanf("%[0-9/]", dataValidade);
    getchar();
    printf("     Quantidade: ");
    scanf("%d", &quant);
    getchar();
    printf("     Valor do Item: R$ "); 
    scanf("%f", &valorItem);
    getchar();
    
    valorCompra += quant * valorItem;
    
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("        Compra cadastrada com sucesso !             \n");
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("        Código de Barras: %s \n", codBarras);
    printf("       Descrição do Item: %s \n", nomeItem);
    printf("        Data de Validade: %s \n", dataValidade);
    printf("              Quantidade: %d \n", quant);
    printf("           Valor do Item: R$ %.2f \n", valorItem);
    printf("         Valor da compra: R$ %.2f \n", valorCompra);
    printf("                    Data: %d/%d/%d \n",vetor[0],vetor[1],vetor[2]);
    printf("                 Horário: %d:%d:%d \n",vetor[3],vetor[4],vetor[5]);
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("         >>> Tecle <ENTER> para continuar...        \n");
    getchar();

}

void telaPesquisarCompra(void){

    char data[11];
    char horario[9];

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
    printf("///            MÓDULO PESQUISAR COMPRA:                               ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%s", &data);
    getchar();
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[0-9:]", &horario);
    getchar();
    printf("\n///            EXIBINDO VALORES DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário, suas quantidades e valores      ///\n");
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

void telaExcluirCompra(void){

    char data[11];
    char horario[9];
    char resposta[2];

    system("cls");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            MÓDULO EXCLUIR COMPRA:                                 ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%s", &data);
    getchar();
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[0-9:]", &horario);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            EXIBINDO VALORES DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("///        ___________________________________________________        ///\n");
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
    scanf("%[NS]",resposta);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            EXIBINDO VALOR DE ENTRADA:                             ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %s \n", resposta);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            Compra excluída com sucesso!                           ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/n): N                          ///\n");
    printf("///                                                                   ///\n");
    printf("///            Operação cancelada!                                    ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAlterarCompra(void){

    char data[11];
    char horario[9];
    char resposta[1];
    char decisao[1];

    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    int quant;
    float valorItem;
    float valorCompra;

    system("cls");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *     SIGPENTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            MÓDULO ALTERAR COMPRA:                                 ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data da compra (dd/mm/aaa): ");
    scanf("%s", data);
    getchar();
    printf("///            - Horário da compra (hh:mm:ss): ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("///                                                                   ///\n");
    printf("///            EXIBINDO VALORES DE ENTRADA:                           ///\n");
    printf("///                                                                   ///\n");
    printf("///             Data da compra: %s \n", data);
    printf("///             Horário da compra: %s \n", horario);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            COMPRA LOCALIZADA!                                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens comprados       ///\n");
    printf("///            naquele dia e horário, suas quantidades e valores      ///\n");
    printf("///            - Data da compra:                                      ///\n");
    printf("///            - Horário da compra:                                   ///\n");
    printf("///            - Valor da compra:                                     ///\n");   
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de compras para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          - Deseja alterar todos os items da compra (S/N) ");
    scanf("%[NS]", resposta);
    getchar();
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///             Opção escolhida: %s \n", resposta);
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");

}

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

    /* No módulo listar compras, serão exibidos todos os items comprados, separados por 
    data e horário de cadastro. 
    */


}

char menuConsumo(void){
    char opcao;
    
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
    printf("Informe a sua opção : ");
    scanf("%c", &opcao);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return opcao;

}

void telaCadastrarConsumo(void){
    char codBarras[14];
    char item[51];
    int quant;
    
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
    printf(" ***************************************************\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" * * *     SIGPENTRY - Controle de Despensa    * * *\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" ***************************************************\n");
    printf("                                                    \n");
    printf("    = = = = = MÓDULO CADASTRAR CONSUMO: = = = = =   \n");
    printf("                                                    \n");
    printf("     Código de Barras: ");
    scanf("%[0-9]", codBarras);
    getchar();
    printf("     Descrição do Item: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", item);
    getchar();
    printf("     Quantidade: ");
    scanf("%d", &quant);
    getchar();
    
    
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("        Consumo cadastrado com sucesso !            \n");
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("        Código de Barras: %s \n", codBarras);
    printf("       Descrição do Item: %s \n", item);
    printf("              Quantidade: %d \n", quant);
    printf("                    Data: %d/%d/%d \n",vetor[0],vetor[1],vetor[2]);
    printf("                 Horário: %d/%d/%d \n",vetor[3],vetor[4],vetor[5]);
    printf(" ___________________________________________________\n");
    printf("                                                    \n");
    printf("         >>> Tecle <ENTER> para continuar...        \n");
    getchar();


}

void telaPesquisarConsumo(void){
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
    printf("///            MÓDULO PESQUISAR CONSUMO:                              ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
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

void telaExcluirConsumo(void){
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
    printf("///            MÓDULO EXCLUIR CONSUMO:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
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
    printf("///            - Confirmar operação (S/n): S                          ///\n");
    printf("///                                                                   ///\n");
    printf("///            Consumo excluído com sucesso!                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/n): N                          ///\n");
    printf("///                                                                   ///\n");
    printf("///            Operação cancelada!                                    ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void telaAlterarConsumo(void){
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
    printf("///            MÓDULO ALTERAR CONSUMO:                                ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            CONSUMO LOCALIZADO!                                    ///\n");
    printf("///                                                                   ///\n");
    printf("///            Itens: Aqui vai mostrar todos os itens consumidos      ///\n");
    printf("///            naquele dia e horário e suas quantidades               ///\n");
    printf("///            - Data do consumo:                                     ///\n");
    printf("///            - Horário do consumo:                                  ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");  
    printf("///          Não há registro de consumo para o dia e horário          ///\n");    
    printf("///          informado.                                               ///\n");    
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");  
    printf("///                                                                   ///\n");
    printf("///          - Deseja alterar todos os items do consumo (S/n)? S      ///\n");
    printf("///                                                                   ///\n");
    printf("///            NOVA LISTA DE ITENS CONSUMIDOS !                       ///\n");
    printf("///                                                                   ///\n"); 
    printf("///            - Código de barras:                                    ///\n");
    printf("///            - Nova Quantidade:                                     ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///          Deseja adicionar outro item (S/n) ?                      ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///          - Deseja alterar todos os items do consumo (S/n)? N      ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Código de barras:                                    ///\n") ;
    printf("///            - Nova Quantidade:                                     ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/n): S                          ///\n");
    printf("///                                                                   ///\n");
    printf("///            Consumo alterado com sucesso!                          ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///            - Confirmar operação (S/n): N                          ///\n");
    printf("///                                                                   ///\n");
    printf("///            Operação cancelada!                                    ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    /* No módulo alterar consumo, o usuário irá informar a data e horário do consumo à alterar,
    se o consumo existir, ele deverá escolher se vai alterar todos os items da lista ou se irá
    alterar apenas um dos items da lista. Caso o usuário queira alterar todos os items, ele irá 
    cadastrar uma nova lista de items, no entanto, se ele quiser alterar apenas um item, ele deve
    informar o código de barras e então cadastrar seus novos valores.
    */

}

void telaListarConsumos(){
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

void menuSobre(void) {
    system("clear");
    printf("\n");
    printf("BEM VINDO AO MENU SOBRE!\n\n");
    printf("Aqui você encontra informações à respeito do projeto SIG-PANTRY e também sobre a \n");
    printf("sua equipe de desenvolvimento. \n\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                           ///\n");
    printf("///              Universidade Federal do Rio Grande do Norte                  ///\n");
    printf("///                  Centro de Ensino Superior do Seridó                      ///\n");
    printf("///                Departamento de Computação e Tecnologia                    ///\n");
    printf("///                   Disciplina DCT1106 -- Programação                       ///\n");
    printf("///            Projeto Sistema de Controle de Despensa Doméstica              ///\n");
    printf("///               Developed by  @allangbr @joanmdrs - Jan, 2021               ///\n");
    printf("///                                                                           ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                           ///\n");
    printf("///       = = = = = Sistema de Controle de Despensa Doméstica = = = = =       ///\n");
    printf("///                                                                           ///\n");
    printf("///   O controle do estoque de produtos de uma despensa doméstica é uma das   ///\n");
    printf("///   atividades necessárias em praticamente todas as residências, uma vez    ///\n");
    printf("///   que a aquisição de produtos alimentícios, de higiene pessoal e de lim-  ///\n");
    printf("///   peza é rotineira e se faz necessário monitorar quantidades e datas de   ///\n");
    printf("///   validade de tais produtos. Tal atividade pode demandar tempo e esfor-   ///\n");
    printf("///   o, principalmente se for realizado sem a ajuda de um software. O pre-   ///\n");
    printf("///   sente projeto tem como objetivo desenvolver um programa de computador   ///\n");
    printf("///   que realize o registro e o acompanhamento desses produtos em uma resi-  ///\n");
    printf("///   dência, evitando o descontrole causado pela compra excessiva, ou pela   ///\n");
    printf("///   falta ou pelo vencimento dos itens adquiridos.                          ///\n");
    printf("///                                                                           ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                           ///\n");
    printf("///       = = = = = = = = = = Equipe Desenvolvedora = = = = = = = = = =       ///\n");
    printf("///                                                                           ///\n");
    printf("///   A equipe desenvoldedora deste projeto é formada por Allan Gabriel de    ///\n");
    printf("///   Almeida Oliveira e Joan de Azevedo Medeiros. Ambos são graduandos do    ///\n");
    printf("///   curso de SISTEMAS DA INFORMAÇÃO pela Universidade Federal do Rio Gran-  ///\n");
    printf("///   de do Norte - UFRN.                                                     ///\n");
    printf("///                                                                           ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}