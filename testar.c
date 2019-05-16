#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char lista[3][9];
char binario1[5] = "";

int number = 0;

void invert_string();
void convert_to_decimal();
void dividir(int linha);
void calcular();
void show();

void calcular(){
	invert_string();
	convert_to_decimal();
	show();
}

void show(){
	//show result
	invert_string();
	printf("Binary Value: %s ", binario1);
	printf(" -->  Decimal value: %d \n", number);

}

void dividir(int linha){
	int p = 0;
	for(int i=0; i < 9; i++){

		if(lista[0][i] != ';')
		{
			binario1[p] = lista[linha][i];
			p++;
		}
		else{
			calcular();
			// printf("debug: %s tamanho: %d\n", binario1, strlen(binario1));
			p = 0;
		}
	}
	calcular();
	// printf("debug: %s tamanho: %d\n", binario1, strlen(binario1));
}

void invert_string() {

	char invert[127] = {'0'}; //auxiliary vector
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

int main(){


	FILE *arquivo = fopen("numeros.txt", "r");
	if(arquivo == 0){
		printf("Nenhum arquivo encontrado!\n");
		exit(1);
	}


	for(int i = 0; i < 4; i++){		
		fscanf(arquivo, "%s", lista[i]);
		// printf("%s\n", lista[i]); //DEBUG 
		dividir(i);
	}
	
	fclose(arquivo);
	
}