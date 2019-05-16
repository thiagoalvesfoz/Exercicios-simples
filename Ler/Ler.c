#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ler.h"

void JacktheRiper(int linha){
	int p = 0;
	for(int i=0; i < strlen(lista[linha]); i++){

		if(lista[linha][i] != ';')
		{
			binario1[p] = lista[linha][i];
			p++;
		}
		else{			
			letsgobyparts();
			p = 0;
			// printf("debug: %s tamanho: %d\n", binario1, strlen(binario1));
		}
	}
	letsgobyparts();
	// printf("debug: %s tamanho: %d\n", binario1, strlen(binario1));
}

void letsgobyparts(){
	invert_string();
	convert_to_decimal();
	show();
}

void invert_string() {

	char invert[127] = ""; //auxiliary vector
	int newPosition = 0;
	
	for (int oldPosition = strlen(binario1); oldPosition >= 0; oldPosition--) 
	{
		if(binario1[oldPosition] == '0' || binario1[oldPosition] == '1')
		{
			invert[newPosition] = binario1[oldPosition];
			newPosition++;
		}
	}

	strcpy(binario1, invert); 
}

void convert_to_decimal() {

	int decimalNumber = 0;
	int position = strlen(binario1) - 1; //Essencial para a precisão do resultado.

	for(int numberExponent = position; numberExponent >= 0; numberExponent--) 
	{		
		if (binario1[numberExponent] != '0')
		{
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", i, reverse[i], i);
			int bitValue = pow(2, numberExponent);
			//DEBUG printf("\nO resultado e': %d", resultado);
			decimalNumber += bitValue;
		}
	}
	number = decimalNumber;
}

void readFile(){
	

	FILE *arquivo = fopen("numeros.txt", "r");
	if(arquivo == 0){
		printf("Nenhum arquivo encontrado!\n");
		exit(1);
	}

	for(int i = 0; i < 4; i++){
		fscanf(arquivo, "%s", lista[i]);	
		// JacktheRiper(i); //calcula e mostra o resultado enquanto o arquivo ainda é lido.
	}
	fclose(arquivo);
}

void show(){
	invert_string();
	printf("Binary Value: %s  -->  Decimal value: ", binario1);	
	if(number < 10)	printf("0");	
	printf("%d\n", number);
}


int main(){

	readFile();
	for(int i = 0; i < 4; i++) JacktheRiper(i); //como diria jack o estripador.
	return 0;
}