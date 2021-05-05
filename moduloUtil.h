#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "moduloValidacoes.h"

void exibeTecleEnter(void);

void exibeErroArquivo(void);

char* preencheCodBarras(void);

char* preencheDataValidade(void);

char* preencheDesc(void);

char* preencheLocal(void);

char* preencheQuantPro(void);

double preenchePrecoItem(void);

char confirmaExclusao(void);

char confirmaAlteracao(void);

int pegaDia(void);

int pegaMes(void);

int pegaAno(void);

char* retornaDiaConvertido(void);

char* retornaMesConvertido(void);

char* retornaAnoConvertido(void);

char* retornaData(void);

char* retornaHoraConvertida(void);

char* retornaMinConvertidos(void);

char* retornaSegConvertidos(void);

char* retornaHora(void);

int itensVencidos(char []);

int itensParaVencer(char []);

char* dataInvertida(char*);

char* dataReinvertida(char*);

char* mesInvertido(char*);

char* preencheMesEAno(void);

char* preencheMesEAnoC(void);

char* recortaMesEAno(char*);

char* preencheAno(void);

char* preencheAnoC(void);

char* recortaAno(char*);

char confirmaEsvaziarLixeira(void);

void telaLixeiraVazia(void);

void telaLixeiraSemAlteracoes(void);