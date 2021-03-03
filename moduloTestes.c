#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* A função testeDigito realiza a validação de uma variavel de apenas um digito. */
int testeDigito(char n){
  int cont = 0;
  
  if(isdigit(n)){
      cont++;
  }
  
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

/* A função testeDigitos realiza a validação de uma variavel de um ou mais digitos, somando o contador quando possui um caracter numérico. */

int testeDigitos(char n[]){
  int cont = 0;
  int i;
  int tam;

  tam = strlen(n);
  for(i=0; i<tam; i++){
    if(isdigit(n[i])){
      cont++;
    }
  }
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

/* A função testeDigitosNumericos realiza a validação de uma variavel de um ou mais digitos, somando o contador quando possui um caracter não numérico. */

int testeDigitosNumericos(char n[]){
  int cont = 0;
  int i;
  int tam;

  tam = strlen(n);
  for(i=0; i<tam; i++){
    if(!isdigit(n[i])){
      cont++;
    }
  }
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

/* A função testeDigitosNumericosData realiza a validação de uma variavel de um ou mais digitos, somando o contador quando possui um caracter não numérico e diferente de '/'. */

int testeDigitosNumericosData(char n[]){
  int cont = 0;
  int i;
  int tam;

  tam = strlen(n);
  for(i=0; i<tam; i++){
    if(!isdigit(n[i]) && n[i] != '/' ){
      cont++;
    }
  }
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

/* A função testeDigitosNumericosHora realiza a validação de uma variavel de um ou mais digitos, somando o contador quando possui um caracter não numérico e diferente de ':'. */

int testeDigitosNumericosHora(char n[]){
  int cont = 0;
  int i;
  int tam;

  tam = strlen(n);
  for(i=0; i<tam; i++){
    if(!isdigit(n[i]) && n[i] != ':' ){
      cont++;
    }
  }
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

/* A função testeDigitosNumericosValorFlutuante realiza a validação de uma variavel de um ou mais digitos, somando o contador quando possui um caracter não numérico e diferente de '.'. */

int testeDigitosNumericosValorFlutuante(char n[]){
  int cont = 0;
  int i;
  int tam;

  tam = strlen(n);
  for(i=0; i<tam; i++){
    if(!isdigit(n[i]) && n[i] != '.' ){
      cont++;
    }
  }
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

/* A função converteCharParaInt realiza a conversão de uma variável char para uma variável do tipo int. */

int converteCharParaInt(char n[]){
  int i = 0;
  i = atoi (n);

  return i;
}

/* A função converteCharParaDouble realiza a conversão de uma variável char para uma variável do tipo double. */

double converteCharParaDouble(char n[]){
  double i = 0;
  i = strtod (n, NULL);

  return i;
}