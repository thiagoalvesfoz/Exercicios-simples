#define CONVERTER_DECIMAL 1
#define CONVERTER_BINARIO 2
#define INVALIDO 0

char string[127]; // irá armazenar o número em string
int numero = 0; 
int contador_bits = 0;

// INPUT/OUTPUT
int menu_principal(int opcao);
int digite_numero(int opcao);
int validar_binario(int numero, int opcao);
void imprima(int opcao);

// PROCESS
void inverter_string();
void convert_to_binario(int numeroDecimal);
int convert_to_decimal();
void resetarValores();