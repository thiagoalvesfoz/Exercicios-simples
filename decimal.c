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

void invert_string();
int convert_to_decimal();

char string[127];
int bitCounter = 0;
int number;

int main () {

	do	{

		//reset value
		sprintf(string, "0");
		number = 0;
		//DEBUG printf("\nVector: %s\n", string);

		//input stdin	
		printf("\nEnter a binary number: ");
		scanf("%d", &number);
		fflush(stdin);
		sprintf(string, "%d", number);


		//process
		invert_string(); 			
		number = convert_to_decimal();

		//show result
		printf("\nDecimal value: %d", number);
		printf("\nSize: %d bit", bitCounter);

		if(bitCounter > 1)
			printf("s\n");	// Mere caprice

		printf("\nTry Again?\n[1] Yes [?] No\n\n");
		printf("$ ");
		scanf("%d", &number);
		fflush(stdin);

	} while(number == 1);

	return 0;
	
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

int convert_to_decimal() {

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
	return decimalNumber;
}