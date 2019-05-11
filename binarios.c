/* 

Thiago Alves | Curso de Engenharia de Software | Faculdade Uniamérica - 2019/2023.

Conversor de numero decimal para binário utilizando a lógica do par ou impar.

Como todos provavelmente devem saber, todo número par é divido por 2, ou seja, caso o
resultado da divisão não tenha restos então o par é verdadeiro "1" caso contrário é falso "0".

Para chegar ao resultado do número binário deve se fazer a divisão do número fornecido pelo 
usuário e verificar se o resto da divisão irá retornar verdadeiro(1) ou falso(0). 
Esse processo será repetido e armazenado em um vetor até que o resultado da ultima divisão 
chegue no valor 1 ou 0 e não dê mais para dividir. Então imprimimos na tela o resultado e voilà.

MELHORIAS
# Menu de opção
# Converte o numero de decimal para binário.
# converte o numero binário para decimal.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void convert_to_binario();
int convert_to_decimal();
void inverter_string();
void digite_numero();
void imprima();


char string[127] = {'0'}; // irá armazenar o número em string
int numero = 0; 
int contador_bits = 0;

int main() {

	int opcao;
	printf("\n=== Escolha com Sabedoria ===\n");
	printf("[1]Converter decimal para binario\n");
	printf("[2]Converter binario para decimal\n");
	printf("[?]Sair\n");
	printf("\nDigite: ");
	scanf("%d", &opcao);

	if (opcao == 1) {	
		digite_numero(opcao);
		convert_to_binario(numero);
		imprima(opcao);
	} else if (opcao == 2){
		//resolução numero decimal para binario
		digite_numero(opcao);
		numero = convert_to_decimal();
		imprima(opcao);
	}

	else
		printf("\nSaindo do aplicativo...");

	return 0;
}

void convert_to_binario(int numeroDecimal) { 

	const int BITLIMIT = 31;  //limitador - configurado para processar até 31^16

	for (int posicao = 0; posicao <= BITLIMIT; posicao++)
	{		
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

		contador_bits = posicao + 1;
		numeroDecimal /= 2; 
	}

	inverter_string();
}

int convert_to_decimal() {
	
	inverter_string();
	int posicao = strlen(string) - 1; //Essencial para a precisão do resultado.

	int Numero_decimal = 0; 

	for(int N_do_expoente = posicao; N_do_expoente >= 0; N_do_expoente--) {

		if (string[N_do_expoente] != '0'){
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", N_do_expoente, aux[string], N_do_expoente);
			int valor_do_bit = pow(2, N_do_expoente);
			Numero_decimal += valor_do_bit;
			//DEBUG printf("\nO resultado e': %d", Numero_decimal);
		}
	}

	contador_bits = strlen(string);
	return Numero_decimal; //retorna o resultado da operacao
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

void digite_numero(int opcao){
	
	printf("\nDigite um numero: ");
	scanf("%d", &numero);

	if (opcao == 2)
		sprintf(string, "%d", numero);

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