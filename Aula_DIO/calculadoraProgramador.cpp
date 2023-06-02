#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Este programa implementa uma calculadora do tipo programador com as seguintes fun��es e limita��es:
*  Ela ir� receber o valor digito em decimal, e mostrar� o mesmo valor na forma hexadecimal, octal e binaria
*  O valor digitado pelo usu�rio ter� um limite de 10 digitos.
*  E ser� poss�vel fezer o pera��es de soma, subtra��o, divis�o e multiplica��o
*/



int Transformacao(char entrada, char valor_digitado[], int tranforma_char_int[]);
void operacao(long int* resultadoOperacao);
void ZerarArray(int tranforma_char_int[], char valor_Digitado[]);


const int TAM_MAXIMO_VALOR_DIGITADO = 10;
int itera = 0;         //Variavel usada para as itera��es no la�o for
bool flagTrocaPosOperando = false;   //Esta flag troca o local onde o valor digitado pelo usu�rio vai ser alocado no array "operandos" 
bool sinalInserido = false;         //Marca se o usu�rio ja tinha inserido um simbolo de opera��o. true -> sim, false -> n�o.
bool flagMarcaOperacao = 0;          // 1 - soma, 2 - sbtra��o, 3 - multiplica��o, 4 - divis�o

int main() {
    char entrada;                   //Ir� receber o dado digitado pelo usu�rio
    long int resultadoOperacao = 0;
    long int operandos[] = { 0, 0 };            //armazena os dois operandos para fazer a opera��o desejada
    int tranforma_char_int[] = {0,0,0,0,0,0,0,0,0,0};  //Array usado como auxiliar para transformar os valores de char para int
    char valor_Digitado[] = {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}; //Armazena a entrada

    /*  - O array valor_Digitado[] serve para receber os dados digitados pelo usu�rio e foi inicializado com '_'.
    *   - Toda vez que o usu�rio digitar um valor valido, este digito ser� tamb�m armazenado em tranforma_char_int[]
    *   - Depois os digitos seram convertidos no valor real. Por exemplo, caso o usu�rio digite 4 e depois 5, o digito
    *    4 ser� armazenado em valor_Digitado[0] e tranforma_char_int[0], e o digito 5 em valor_Digitado[1] 
    *    tranforma_char_int[1], e ent�o ser� feito opera��es para que no array operandos[] seja armazenado o long int 45.
    *   
    */
    
    do {
        printf_s("Digite um numero, somente inteiros: ");
        entrada = _getche();
        
        if (entrada >= '0' && entrada <= '9') {      //testa se � um caractere est� entre 0 e 9.
 
            operandos[flagTrocaPosOperando] = Transformacao(entrada, valor_Digitado, tranforma_char_int); //Retorna o numero ja em inteiro
            //system("cls");
            printf_s("\nvalor digitado: %ld", operandos[flagTrocaPosOperando]);
            //printf_s("\nvalor flagTrocaPosOperando: %b\n", flagTrocaPosOperando);
            printf_s("\nvalor operandos[0]: %ld", operandos[0]);
            printf_s("\nvalor operandos[1]: %ld\n", operandos[1]);
            
        }else {                 //Testa se foi digitado um operador
            switch (entrada)
            {
            case '+':
                if (sinalInserido == false) {  // Essa � a primeira vez que o usu�rio digita um sinal de opera��o?
                    sinalInserido = true;      //Sim! ent�o marca a flag,
                    flagMarcaOperacao = 1;
                    flagTrocaPosOperando = !flagTrocaPosOperando; //Sim! troca a posi��o de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //N�o!
                    if (valor_Digitado[0] == '_') {      // O usu�rio j� inserio algum valor?
                        break;                           // N�o! Ignora o caractere inserido
                    }else{ 
                        operacao(&resultadoOperacao);  // Sim! Chama a fun��o para executar a opera��o desejada
                        }
                }
                break;
            case '-':
                if (sinalInserido == false) {  // Essa � a primeira vez que o usu�rio digita um sinal de opera��o?
                    sinalInserido = true;      //Sim! ent�o marca a flag,
                    flagMarcaOperacao = 2;
                    flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posi��o de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //N�o!
                    if (valor_Digitado[0] == '_') {      // O usu�rio j� inserio algum valor?
                        break;                           // N�o! Ignora o caractere inserido
                    }
                    else {
                        operacao(&resultadoOperacao);  // Sim! Chama a fun��o para executar a opera��o desejada
                    }
                }
                break;
            case '*':
                if (sinalInserido == false) {  // Essa � a primeira vez que o usu�rio digita um sinal de opera��o?
                    sinalInserido = true;      //Sim! ent�o marca a flag,
                    flagMarcaOperacao = 3;
                    flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posi��o de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //N�o!
                    if (valor_Digitado[0] == '_') {      // O usu�rio j� inserio algum valor?
                        break;                           // N�o! Ignora o caractere inserido
                    }
                    else {
                        operacao(&resultadoOperacao);  // Sim! Chama a fun��o para executar a opera��o desejada
                    }
                }
                break;
            case '/':
                if (sinalInserido == false) {  // Essa � a primeira vez que o usu�rio digita um sinal de opera��o?
                    sinalInserido = true;      //Sim! ent�o marca a flag,
                    flagMarcaOperacao = 4;
                    flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posi��o de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //N�o!
                    if (valor_Digitado[0] == '_') {      // O usu�rio j� inserio algum valor?
                        break;                           // N�o! Ignora o caractere inserido
                    }
                    else {
                        operacao(&resultadoOperacao);  // Sim! Chama a fun��o para executar a opera��o desejada
                    }
                }
                break;
            case '\n':
                operacao(&resultadoOperacao);
                break;
             default:
                 break;
            }
        }
        

    } while (entrada != 'p' && entrada != 'P');
 
    return 0;
}


int Transformacao(char entrada, char valor_digitado[], int tranforma_char_int[]) {
    /*O valor digitado pelo usu�rio � do tipo CHAR, logo deve ser transformado em inteiro para realizar as devidas opera��es.
    * a transforma��o ser� feita da seguinte maneira:
    *           - um loop FOR vai verificar quantos digitos ja foram digitados atrav�s da verifica��o da existencia do caractere
    *        "_" ou se o loop tiver chegado ao fim do array.
    *           - ap�s isso, ser� feito outro loop FOR para multiplicar cada digito conforme a posi��o em que est� no array
    *           - por exemplo: caso o usu�rio tenha digitado 2 numeros, a vari�vel itera ser� igual a 1.
    *           - ent�o o segundo FOR ir� multiplicar o digito mais a direita por 1, depois multiplicar o segundo digito 
    *        por 10 e somar o resultado com o primeiro.
    *           
    */
    long int numero_transformado = 0;
    long int fator_de_multiplicacao[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
    int aux = 0, contador_do_fator = 9;

    //Adiciona o caracter digitado pelo usu�rio no array valor_Digitado***********************
    for (int itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {
        if (valor_digitado[itera] == '_') {
            valor_digitado[itera] = entrada;
            //Este switch � usado para converter o valor do tipo CHAR para LONG  INT
            switch (entrada)
            {
            case '0':
                tranforma_char_int[itera] = 0;
                break;
            case '1':
                tranforma_char_int[itera] = 1;
                break;
            case '2':
                tranforma_char_int[itera] = 2;
                break;
            case '3':
                tranforma_char_int[itera] = 3;
                break;
            case '4':
                tranforma_char_int[itera] = 4;
                break;
            case '5':
                tranforma_char_int[itera] = 5;
                break;
            case '6':
                tranforma_char_int[itera] = 6;
                break;
            case '7':
                tranforma_char_int[itera] = 7;
                break;
            case '8':
                tranforma_char_int[itera] = 8;
                break;
            case '9':
                tranforma_char_int[itera] = 9;
                break;
            default:
                break;
            }
            break;
        }
    }
    //****************************************************************************************


    //   Este loop transforma todos os caracteres armazenado no array transforma_char_int em um unico dado no formato LONG INT
    //e armazena na vari�vel numero_transformado.
    for (int itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {   //Percorre o array para verificar em qual dezena
        if (valor_digitado[itera] == '_' || itera == 9) {             //foi digitado o ultimo digito
            if (itera == 9) {                       //Verifica se foi digitado todos os 10 digitos                              
                for (aux = itera; aux >= 0; aux--) {
                    numero_transformado += tranforma_char_int[aux] * fator_de_multiplicacao[contador_do_fator];
                    contador_do_fator--;
                } 
                break;
            }
            else {    // Caso n�o tenha sido digitado 10 digitos, transforma os que foram digitados
                for (aux = itera - 1; aux >= 0; aux--) {
                    numero_transformado += tranforma_char_int[aux] * fator_de_multiplicacao[contador_do_fator];
                    contador_do_fator--;
                }
                break;
            }
        }
    }

    return numero_transformado;
}


void operacao(long int *resultadoOperacao) {

    switch (flagMarcaOperacao)
    {
    case 1:
        printf_s("\nusu�rio solicitou a opera��o SOMA\n");
        break;
    case 2:
        printf_s("\nusu�rio solicitou a opera��o SUBTRA��O\n");
        break;
    case 3:
        printf_s("\nusu�rio solicitou a opera��o DIVIS�O\n");
        break;
    case 4:
        printf_s("\nusu�rio solicitou a opera��o MULTIPLICA��O\n");
        break;
    default:
        break;
    }
    

    return;
}

void ZerarArray(int tranforma_char_int[], char valor_Digitado[]) {

    for (itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {
        tranforma_char_int[itera] = 0;
        valor_Digitado[itera] = '_';
    } 
    return;
}