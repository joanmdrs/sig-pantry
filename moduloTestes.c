#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int testeDigitos(char nome[]){
  int cont = 0;
  int i;
  int tam;

  tam = strlen(nome);
  for(i=0; i<tam; i++){
    if(isdigit(nome[i])){
      cont++;
    }
  }
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}

int testeDigito(char nome){
  int cont = 0;
  
  if(isdigit(nome)){
      cont++;
  }
  
  if(cont >= 1){
    return 1;
  }else{
    return 0;
  }
}