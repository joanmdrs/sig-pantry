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

                    switch (opcao5){
                        case '1':
                            do{
                                opcao6 = menuRelatorioProdutos();
                                switch (opcao6){
                                    case '1': 
                                        itensVencidos();
                                        break;

                                    case '2':
                                        itensParaVencer();
                                        break;
                                    
                                    case '3':
                                        itensAbertos();
                                        break;
                                }
                                
                            }while(opcao6 != '0');
                            break;

                        case '2':
                            do{
                                opcao7 = menuRelatorioCompras();
                                switch (opcao7){
                                    case '1': 
                                        comprasDiarias();
                                        break;

                                    case '2':
                                        comprasMensais();
                                        break;
                                    
                                    case '3':
                                        comprasAnuais();
                                        break;
                                }
                                
                            }while(opcao7 != '0');
                            break;

                        case '3':
                           do{
                                opcao8 = menuRelatorioConsumo();
                                switch (opcao8){
                                    case '1': 
                                        consumoDiario();
                                        break;

                                    case '2':
                                        consumoMensal();
                                        break;
                                    
                                    case '3':
                                        consumoAnual();
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
    printf("Fim do programa, obrigado por utilizar nossos serviços!\n");

    return 0;

}



