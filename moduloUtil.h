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

int itensVencidos(char []);

int itensParaVencer(char []);

char* dataInvertida(char*);

char* mesInvertido(char*);

char* preencheMesEAno(void);

char* recortaMesEAno(char*);

char* preencheAno(void);

char* recortaAno(char*);