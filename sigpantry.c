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
#include "moduloPrincipal.h"
#include "moduloProdutos.h"
#include "moduloCompras.h"
#include "moduloSobre.h"
#include "moduloConsumos.h"
#include "moduloRelatorios.h"

int main(void) {

    char opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, opcao8;

    do{
        opcao1 = menuPrincipal();

        switch (opcao1){
            case '1':
                do{                   
                    opcao2 = menuProdutos();

                    switch (opcao2){
                        case '1':
                            cadastrarProduto();
                            break;
                        case '2':
                            pesquisarProduto();
                            break;
                        case '3':
                            excluirProduto();
                            break;
                        case '4':
                            alterarProduto();;
                            break;
                        case '5':
                            listarProdutos();
                            break;
                    }

                }while(opcao2 != '0');
                break;

            case '2':
                do{
                    opcao3 = menuCompras();

                    switch (opcao3){
                        case '1':
                            cadastrarCompra();
                            break;
                        case '2':
                            pesquisarCompra();
                            break;
                        case '3':
                            excluirCompra();
                            break;
                        case '4':
                            alterarCompra();
                            break;
                        case '5':
                            listarCompras();
                            break;
                    }

                } while (opcao3 != '0');
                break;

            case '3':
                do{
                    opcao4 = menuConsumo();

                    switch (opcao4){
                        case '1':
                            cadastrarConsumo();
                            break;
                        case '2':
                            pesquisarConsumo();
                            break;
                        case '3':
                            excluirConsumo();
                            break;
                        case '4':
                            alterarConsumo();
                            break;
                        case '5':
                            listarConsumos();
                            break;
                    }

                } while(opcao4 != '0');
                break;
                
            case '4':
                do{
                    opcao5 = menuRelatorios();
                    Produto* lista;
                    Compra* listaC;
                    Consumo* listaCon;
                    lista = NULL;
                    listaC = NULL;
                    listaCon = NULL;

                    switch (opcao5){
                        case '1':
                            do{
                                opcao6 = menuRelatorioProdutos();
                                switch (opcao6){
                                    case '1': 
                                        relProdVencidos();
                                        break;

                                    case '2':
                                        relProdParaVencer();
                                        break;
                                    
                                    case '3':
                                        relProdOrdenados(&lista);
                                        exibirLista(lista);
                                        break;
                                    case '4':
                                        relProdLocal();
                                        break;
                                }
                                
                            }while(opcao6 != '0');
                            break;

                        case '2':
                            do{
                                opcao7 = menuRelatorioCompras();
                                switch (opcao7){
                                    case '1': 
                                        relComprasDiarias();
                                        break;

                                    case '2':
                                        relComprasMensais();
                                        break;
                                    
                                    case '3':
                                        relComprasAnuais();
                                        break;
                                    
                                    case '4':
                                        relCompOrdemValor(&listaC);
                                        exibirListaOrdemValor(listaC);
                                        break;

                                    case '5':
                                        relCompOrdemCrono(&listaC);
                                        exibirListaOrdemCrono(listaC);
                                        break;
                                }
                                
                            }while(opcao7 != '0');
                            break;

                        case '3':
                           do{
                                opcao8 = menuRelatorioConsumo();
                                switch (opcao8){
                                    case '1': 
                                        relConsumosDiarios();
                                        break;

                                    case '2':
                                        relConsumosMensais();
                                        break;
                                    
                                    case '3':
                                        relConsumosAnuais();
                                        break;

                                    case '4':
                                        relConOrdemValor(&listaCon);
                                        exibirListaOrdemValorC(listaCon);
                                        break;

                                    case '5':
                                        relConOrdemCrono(&listaCon);
                                        exibirListaOrdemCronoC(listaCon);
                                        break;
                                }
                                
                            }while(opcao8 != '0');
                            break;
                    }

                } while(opcao5 != '0');
                break;

            case '5':
                menuSobre();
                break;

        } 

    }while(opcao1 != '0');

    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                     VOCE ENCERROU O PROGRAMA!                     ///\n");
    printf("///                                                                   ///\n");
    printf("///            Agradecemos por utilizar os nossos servicos.           ///\n");
    printf("///            Os dados cadastrados estarão disponiveis no            ///\n");
    printf("///            seu proximo acesso.                                    ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///           Developed by  @allangbr @joanmdrs - Jan, 2021           ///\n");
    printf("///                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////\n\n");

    return 0;

}



