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
#include <locale.h>
#include <wchar.h>

void menuSobre(void);

int main(void) {
    setlocale(LC_ALL, "");
    menuSobre();
    return 0;

}

void menuSobre(void) {
    wprintf(L"\n");
    wprintf(L"BEM VINDO AO MENU SOBRE!\n\n");
    wprintf(L"Aqui você encontra informações à respeito do projeto SIG-PANTRY e também sobre a \n");
    wprintf(L"sua equipe de desenvolvimento. \n\n");
    wprintf(L"/////////////////////////////////////////////////////////////////////////////////\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"///              Universidade Federal do Rio Grande do Norte                  ///\n");
    wprintf(L"///                  Centro de Ensino Superior do Seridó                      ///\n");
    wprintf(L"///                Departamento de Computação e Tecnologia                    ///\n");
    wprintf(L"///                   Disciplina DCT1106 -- Programação                       ///\n");
    wprintf(L"///            Projeto Sistema de Controle de Despensa Doméstica              ///\n");
    wprintf(L"///               Developed by  @allangbr @joanmdrs - Jan, 2021               ///\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"/////////////////////////////////////////////////////////////////////////////////\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"///       = = = = = Sistema de Controle de Despensa Doméstica = = = = =       ///\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"///   O controle do estoque de produtos de uma despensa doméstica é uma das   ///\n");
    wprintf(L"///   atividades necessárias em praticamente todas as residências, uma vez    ///\n");
    wprintf(L"///   que a aquisição de produtos alimentícios, de higiene pessoal e de lim-  ///\n");
    wprintf(L"///   peza é rotineira e se faz necessário monitorar quantidades e datas de   ///\n");
    wprintf(L"///   validade de tais produtos. Tal atividade pode demandar tempo e esfor-   ///\n");
    wprintf(L"///   o, principalmente se for realizado sem a ajuda de um software. O pre-   ///\n");
    wprintf(L"///   sente projeto tem como objetivo desenvolver um programa de computador   ///\n");
    wprintf(L"///   que realize o registro e o acompanhamento desses produtos em uma resi-  ///\n");
    wprintf(L"///   dência, evitando o descontrole causado pela compra excessiva, ou pela   ///\n");
    wprintf(L"///   falta ou pelo vencimento dos itens adquiridos.                          ///\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"/////////////////////////////////////////////////////////////////////////////////\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"///       = = = = = = = = = = Equipe Desenvolvedora = = = = = = = = = =       ///\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"///   A equipe desenvoldedora deste projeto é formada por Allan Gabriel de    ///\n");
    wprintf(L"///   Almeida Oliveira e Joan de Azevedo Medeiros. Ambos são graduandos do    ///\n");
    wprintf(L"///   curso de SISTEMAS DA INFORMAÇÃO pela Universidade Federal do Rio Gran-  ///\n");
    wprintf(L"///   de do Norte - UFRN.                                                     ///\n");
    wprintf(L"///                                                                           ///\n");
    wprintf(L"/////////////////////////////////////////////////////////////////////////////////\n");

    wprintf(L"\n");
}