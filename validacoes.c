#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validaCodBarras(char codBarras[14]){
 
	float somaPares = 0.0;  // --> variável destinada à receber a soma dos caracteres pares da variável char codBarras[14]
	float somaImpares = 0.0;// --> variável destinada à receber a soma dos caracteres ímpares da variável char codBarras[14]
	float somaTotal = 0.0;  // --> variável destinada à receber a soma dos caracteres pares e ímpares da variável char codBarras[14]
	float resultadoF = 0.0; // --> variável destinada à receber o valor flutuante do valor armazenado na variável (float somaTotal) dividido por 10
	int resultadoI = 0;     // --> variável destinada à receber a parte inteira do valor armazenado na variável (float resultadoF) 
	char aux[1];            // --> variável destinada à auxiliar na conversão do valor char para int.
	float numConv = 0.0;    // --> variável destinada à receber o valor char convertido para int
	int digitoI;            // --> variável destinada à receber o último caractere (dígito verificador) informado pelo usuário da variável char codBarras[14]
	int digitoC;            // --> variável destinada à receber o valor calculado, referente ao dígito verificador do código de barras
	int tamanho = 0;        // --> variável destinada à receber a quantidade de caracteres da variável char codBarras[14]

	tamanho = strlen(codBarras);

	if(tamanho == 13){

		for(int i = 0; i < (tamanho - 1); i ++){

			if (i % 2 == 0){
				aux[0] = codBarras[i];
				numConv = atoi(aux);
				somaPares += numConv ;

			}else{
				aux[0] = codBarras[i];
				numConv = atoi(aux);
				somaImpares += numConv;

			}
		}

		somaTotal = somaPares + (somaImpares * 3);
		resultadoF = somaTotal / 10;
		resultadoI = resultadoF;

		if ((resultadoF - resultadoI) >= 0.5){
			resultadoI += 1;
			aux[0] = codBarras[12];
			digitoI = atoi(aux);
			digitoC = ((resultadoI + 1) * 10) - somaTotal;

			if (digitoI == digitoC){
				printf("Código Válido!\n");
				printf("Soma Pares: %.1f \n", somaPares);
				printf("Soma Impares: %.1f \n", somaImpares);
				printf("Resultado float: %.1f \n", resultadoF);
				printf("Resultado int: %d \n", resultadoI);
				printf("Dígito Verificar inserido: %d\n",digitoI);
				printf("Dígito Verificar calculado: %d\n",digitoC);
				return 1;

			}else{
				printf("Código Inválido!\n");
				return 0;

			}

		}else{
			resultadoI = resultadoI;
			aux[0] = codBarras[12];
			digitoI = atoi(aux);
			digitoC = ((resultadoI + 1) * 10) - somaTotal;

			if (digitoI == digitoC){
				printf("Código Válido!\n");
				printf("Soma Pares: %.1f \n", somaPares);
				printf("Soma Impares: %.1f \n", somaImpares);
				printf("Resultado float: %.1f \n", resultadoF);
				printf("Resultado int: %d \n", resultadoI);
				printf("Dígito Verificar inserido: %d\n",digitoI);
				printf("Dígito Verificar calculado: %d\n",digitoC);
				return 1;

			}else{
				printf("Código Inválido!\n");
				return 0;

			}
		}

	}else{
		return 0;
		
	}

}