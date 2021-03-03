#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int converteCharParaInt(char n[]){
  int i = 0;
  i = atoi (n);

  return i;
}

double converteCharParaDouble(char n[]){
  double i = 0;
  i = strtod (n, NULL);

  return i;
}