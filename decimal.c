/* 
Thiago Alves | Software Engineering Course |  Campus Uniamérica - 2019/2023.

Convert from Decimal to Binary.

IMPROVEMENTS
# Allows new operation
# Bits Counter
# Clean Code - Easy maintenance.
# Some comments removed (self-explanatory codes).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void input();
void invert_string();
void convert_to_decimal();

char string[127];
int bitCounter = 0;
int number;

void input(){
	//reset value
	sprintf(string, "0");
	number = 0;
	//DEBUG printf("\nVector: %s\n", string);

	//input stdin	
	printf("\nEnter a binary number: ");
	scanf("%d", &number);
	fflush(stdin);
	sprintf(string, "%d", number);
}

void invert_string() {

	char invert[127] = {'0'}; //auxiliary vector
	int newPosition = 0;
	
	for (int oldPosition = strlen(string); oldPosition >= 0; oldPosition--) 
	{
		if(string[oldPosition] == '0' || string[oldPosition] == '1')
		{
			invert[newPosition] = string[oldPosition];
			newPosition++;
		}
	}

	strcpy(string, invert); 
}

void convert_to_decimal() {

	int decimalNumber = 0;
	int position = strlen(string) - 1; //Essencial para a precisão do resultado.

	for(int numberExponent = position; numberExponent >= 0; numberExponent--) 
	{		
		if (string[numberExponent] != '0')
		{
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", i, reverse[i], i);
			int bitValue = pow(2, numberExponent);
			//DEBUG printf("\nO resultado e': %d", resultado);
			decimalNumber += bitValue;
		}
	}
	bitCounter = strlen(string);
	number = decimalNumber;

	//show result
		printf("\nDecimal value: %d", number);
		printf("\nSize: %d bit", bitCounter);

		if(bitCounter > 1)
			printf("s\n");	// Mere caprice
}

int main () {

	do	{
		
		input();
		//process
		invert_string(); 			
		convert_to_decimal();

		printf("\nTry Again?\n[1] Yes [?] No\n\n");
		printf("$ ");
		
		scanf("%d", &number);
		fflush(stdin);

	} while(number == 1);

	return 0;
	
}