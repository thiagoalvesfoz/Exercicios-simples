/* 
Thiago Alves | Curso de Engenharia de Software | Faculdade Uniamérica - 2019/2023.

Conversor de Número decimal para binário

MELHORIAS
# Menu de opção
# Converte o numero de decimal para binário.
# converte o numero binário para decimal.
# Contador de Bits
# Limpeza do código - Fácil manutenção.
# Remoção de comentários (linhas de códigos auto-explicativos).
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "conversor.h"

/////////////// user ///////////////

int menu_principal(int opcao){

	opcao = 0;
	//DEBUG printf("\nNa string tem: %s\n", string);

	printf("\n=== Escolha o tipo de conversao ===\n");
	printf("[1]Decimal para binario\n");
	printf("[2]Binario para decimal\n");
	printf("[?]Sair\n");
	printf("\n$ ");
	
	scanf("%d", &opcao);
	fflush(stdin);

	return opcao;
}

int validar_binario(int numero, int opcao){
	
	sprintf(string, "%d", numero);
	//DEBUG printf("\nInteiro: %d \nString: %s \n", numero, string);
	for(int check = 0; check < strlen(string); check++)	{
		if(string[check] != '1' && string[check] != '0'){
			printf("Numero binario invalido...\n");
			fflush(stdin);
			return digite_numero(opcao);
		}
	}

	inverter_string();
}

int digite_numero(int opcao){	
	//DEBUG printf("\n numero %d, opcao %d\n", numero, opcao);	
	printf("\nDigite um numero: ");
	scanf("%d", &numero);

	if(numero == INVALIDO) {
		fflush(stdin);
		printf("Numero invalido... :(\n");
		return digite_numero(opcao);
	}

	if (opcao == CONVERTER_BINARIO) {
		validar_binario(numero, opcao);
	}

}

void imprima(int opcao){ //mostra o resultado de acordo com a opção escolhida.
	
	if (opcao == CONVERTER_DECIMAL) { 
		printf("\nValor em binario: %s", string);
	} else
		printf("\nValor em decimal: %d", numero);

	printf("\nTamanho: %d bit", contador_bits);
	if(contador_bits > 1)
		printf("s\n");	// Mero capricho

	resetarValores();
}

void resetarValores(){
	strcpy(string,"");
	numero = 0;
	//DEBUG printf("\n\nstring:%s\n", string);
}

/////////////// Process ///////////////

void inverter_string() {

	char reverse[127] = {'0'};
	int novaPosicao = 0;
	
	for (int antigaPosicao = strlen(string); antigaPosicao >= 0; antigaPosicao--) 
	{
		if(string[antigaPosicao] == '0' || string[antigaPosicao] == '1')
		{ 
			reverse[novaPosicao] = string[antigaPosicao];
			novaPosicao++;
		}
	}

	strcpy(string, reverse);
}

void convert_to_binario(int numeroDecimal) { 

	const int BITLIMIT = 64;  //limitador

	for (int posicao = 0; posicao <= BITLIMIT; posicao++)
	{		
		contador_bits = posicao + 1;

		if (numeroDecimal == 1)	{ 
			string[posicao] = '1'; 
			break; 
		} 
		else if(numeroDecimal == 0)	{
			string[posicao] = '0'; 
			break;
		}

		else 
		{ 
			int restoDivisao = numeroDecimal % 2;

			if (restoDivisao > 0) 
				string[posicao] = '1'; 	  
		  	else 
				string[posicao] = '0'; 
		}

		numeroDecimal /= 2; 
	}

	inverter_string();
}

int convert_to_decimal() {
	
	int posicao = strlen(string) - 1; //Essencial para a precisão do resultado.
	int Numero_decimal = 0;

	for(int Numero_expoente = 0; Numero_expoente <= posicao; Numero_expoente++) {

		if (string[Numero_expoente] != '0'){
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", N_do_expoente, string[N_do_expoente], N_do_expoente);
			int valor_do_bit = pow(2, Numero_expoente);
			Numero_decimal += valor_do_bit;
			//DEBUG printf("\nO resultado e': %d", Numero_decimal);
		}
	}

	contador_bits = strlen(string);
	return Numero_decimal; //retorna o resultado da operacao
}

int main() {

	int opcao = 0;

	do	{

		opcao = menu_principal(opcao);

		if (opcao == CONVERTER_DECIMAL) {	
			digite_numero(opcao);
			convert_to_binario(numero);
			imprima(opcao);
		} else if (opcao == CONVERTER_BINARIO){
			//resolução numero decimal para binario
			digite_numero(opcao);
			numero = convert_to_decimal(numero);
			imprima(opcao);
		}

		else
			printf("\nSaindo do aplicativo...");

	} while(opcao == CONVERTER_DECIMAL || opcao == CONVERTER_BINARIO);

	return 0;
}
