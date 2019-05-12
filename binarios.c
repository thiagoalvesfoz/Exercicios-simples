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

int menu_principal();
void digite_numero();
void imprima();
void inverter_string();
void convert_to_binario();
int convert_to_decimal();

char string[127]; // irá armazenar o número em string
int numero = 0; 
int contador_bits = 0;

int menu_principal(int opcao){

	//reset value
	sprintf(string, "0");
	opcao = 0;
	//DEBUG printf("\nNa string tem: %s\n", string);

	printf("\n=== Escolha o tipo de conversao ===\n");
	printf("[1]Decimal para binario\n");
	printf("[2]Binario para decimal\n");
	printf("[?]Sair\n");
	printf("\n$ ");
	
	scanf("%d", &opcao);
	fflush(stdin);

	return opcao;//Apenas mostra o menu principal
}

void digite_numero(int opcao){
	
	printf("\nDigite um numero: ");
	scanf("%d", &numero);

	if (opcao == 2) {
		sprintf(string, "%d", numero);
		inverter_string();
	}

	//DEBUG printf("\nInteiro: %d \nString: %s \n", numero, string);
	//Em breve - validação de dados e anti buffer
}

void imprima(int opcao){ //mostra o resultado de acordo com a opção escolhida.
	
	if (opcao == 1) { 
		printf("\nValor em binario: %s", string);
	} else
		printf("\nValor em decimal: %d", numero);

	printf("\nTamanho: %d bit", contador_bits);
	if(contador_bits > 1)
		printf("s\n");	// Mero capricho
}

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

	for(int Numero_expoente = posicao; Numero_expoente >= 0; Numero_expoente--) {

		if (string[Numero_expoente] != '0'){
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", N_do_expoente, aux[string], N_do_expoente);
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

		if (opcao == 1) {	
			digite_numero(opcao);
			convert_to_binario(numero);
			imprima(opcao);
		} else if (opcao == 2){
			//resolução numero decimal para binario
			digite_numero(opcao);
			numero = convert_to_decimal(numero);
			imprima(opcao);
		}

		else
			printf("\nSaindo do aplicativo...");

	} while(opcao == 1 || opcao == 2);

	return 0;
}