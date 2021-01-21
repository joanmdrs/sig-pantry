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
#include <wchar.h>;

void menuSobre(void);

int main(void) {
    setlocale(LC_ALL, "");
    menuSobre();
    return 0;

}

void menuSobre(void) {
    wprintf(L"%s", L"\n");
    wprintf(L"%s", L"///////////////////////////////////////////////////////////////////////////////\n");
    wprintf(L"%s", L"///                                                                         ///\n");
    wprintf(L"%s", L"///             Universidade Federal do Rio Grande do Norte                 ///\n");
    wprintf(L"%s", L"///                 Centro de Ensino Superior do Seridó                     ///\n");
    wprintf(L"%s", L"///               Departamento de Computação e Tecnologia                   ///\n");
    wprintf(L"%s", L"///                  Disciplina DCT1106 -- Programação                      ///\n");
    wprintf(L"%s", L"///           Projeto Sistema de Controle de Despensa Doméstica             ///\n");
    wprintf(L"%s", L"///              Developed by  @allangbr @joanmdrs - Jan, 2021              ///\n");
    wprintf(L"%s", L"///                                                                         ///\n");
    wprintf(L"%s", L"///////////////////////////////////////////////////////////////////////////////\n");
    wprintf(L"%s", L"///                                                                         ///\n");
    wprintf(L"%s", L"///      = = = = = Sistema de Controle de Despensa Doméstica = = = = =      ///\n");
    wprintf(L"%s", L"///                                                                         ///\n");
    wprintf(L"%s", L"///  Programa exemplo utilizado na disciplina DCT1106 - Programação, para   ///\n");
    wprintf(L"%s", L"///  fins didáticos de ilustração. O programa contém os principais módulos  ///\n");
    wprintf(L"%s", L"///  e funcionalidades que serão exigidos na avaliação dos projetos a serem ///\n");
    wprintf(L"%s", L"///  desenvolvidos pelos alunos ao longo da disciplina. Serve como um guia  ///\n");
    wprintf(L"%s", L"///  de consulta e referência para o desenvolvidos dos demais projetos.     ///\n");
    wprintf(L"%s", L"///                                                                         ///\n");
    wprintf(L"%s", L"///////////////////////////////////////////////////////////////////////////////\n");
    wprintf(L"%s", L"\n");
}