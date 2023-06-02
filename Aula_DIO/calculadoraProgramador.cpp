#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Este programa implementa uma calculadora do tipo programador com as seguintes funções e limitações:
*  Ela irá receber o valor digito em decimal, e mostrará o mesmo valor na forma hexadecimal, octal e binaria
*  O valor digitado pelo usuário terá um limite de 10 digitos.
*  E será possível fezer o perações de soma, subtração, divisão e multiplicação
*/



int Transformacao(char entrada, char valor_digitado[], int tranforma_char_int[]);
void operacao(long int* resultadoOperacao);
void ZerarArray(int tranforma_char_int[], char valor_Digitado[]);


const int TAM_MAXIMO_VALOR_DIGITADO = 10;
int itera = 0;         //Variavel usada para as iterações no laço for
bool flagTrocaPosOperando = false;   //Esta flag troca o local onde o valor digitado pelo usuário vai ser alocado no array "operandos" 
bool sinalInserido = false;         //Marca se o usuário ja tinha inserido um simbolo de operação. true -> sim, false -> não.
bool flagMarcaOperacao = 0;          // 1 - soma, 2 - sbtração, 3 - multiplicação, 4 - divisão

int main() {
    char entrada;                   //Irá receber o dado digitado pelo usuário
    long int resultadoOperacao = 0;
    long int operandos[] = { 0, 0 };            //armazena os dois operandos para fazer a operação desejada
    int tranforma_char_int[] = {0,0,0,0,0,0,0,0,0,0};  //Array usado como auxiliar para transformar os valores de char para int
    char valor_Digitado[] = {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}; //Armazena a entrada

    /*  - O array valor_Digitado[] serve para receber os dados digitados pelo usuário e foi inicializado com '_'.
    *   - Toda vez que o usuário digitar um valor valido, este digito será também armazenado em tranforma_char_int[]
    *   - Depois os digitos seram convertidos no valor real. Por exemplo, caso o usuário digite 4 e depois 5, o digito
    *    4 será armazenado em valor_Digitado[0] e tranforma_char_int[0], e o digito 5 em valor_Digitado[1] 
    *    tranforma_char_int[1], e então será feito operações para que no array operandos[] seja armazenado o long int 45.
    *   
    */
    
    do {
        printf_s("Digite um numero, somente inteiros: ");
        entrada = _getche();
        
        if (entrada >= '0' && entrada <= '9') {      //testa se é um caractere está entre 0 e 9.
 
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
                if (sinalInserido == false) {  // Essa é a primeira vez que o usuário digita um sinal de operação?
                    sinalInserido = true;      //Sim! então marca a flag,
                    flagMarcaOperacao = 1;
                    flagTrocaPosOperando = !flagTrocaPosOperando; //Sim! troca a posição de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //Não!
                    if (valor_Digitado[0] == '_') {      // O usuário já inserio algum valor?
                        break;                           // Não! Ignora o caractere inserido
                    }else{ 
                        operacao(&resultadoOperacao);  // Sim! Chama a função para executar a operação desejada
                        }
                }
                break;
            case '-':
                if (sinalInserido == false) {  // Essa é a primeira vez que o usuário digita um sinal de operação?
                    sinalInserido = true;      //Sim! então marca a flag,
                    flagMarcaOperacao = 2;
                    flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posição de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //Não!
                    if (valor_Digitado[0] == '_') {      // O usuário já inserio algum valor?
                        break;                           // Não! Ignora o caractere inserido
                    }
                    else {
                        operacao(&resultadoOperacao);  // Sim! Chama a função para executar a operação desejada
                    }
                }
                break;
            case '*':
                if (sinalInserido == false) {  // Essa é a primeira vez que o usuário digita um sinal de operação?
                    sinalInserido = true;      //Sim! então marca a flag,
                    flagMarcaOperacao = 3;
                    flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posição de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //Não!
                    if (valor_Digitado[0] == '_') {      // O usuário já inserio algum valor?
                        break;                           // Não! Ignora o caractere inserido
                    }
                    else {
                        operacao(&resultadoOperacao);  // Sim! Chama a função para executar a operação desejada
                    }
                }
                break;
            case '/':
                if (sinalInserido == false) {  // Essa é a primeira vez que o usuário digita um sinal de operação?
                    sinalInserido = true;      //Sim! então marca a flag,
                    flagMarcaOperacao = 4;
                    flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posição de armazenagem dos operandos
                    ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                }
                else {                         //Não!
                    if (valor_Digitado[0] == '_') {      // O usuário já inserio algum valor?
                        break;                           // Não! Ignora o caractere inserido
                    }
                    else {
                        operacao(&resultadoOperacao);  // Sim! Chama a função para executar a operação desejada
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
    /*O valor digitado pelo usuário é do tipo CHAR, logo deve ser transformado em inteiro para realizar as devidas operações.
    * a transformação será feita da seguinte maneira:
    *           - um loop FOR vai verificar quantos digitos ja foram digitados através da verificação da existencia do caractere
    *        "_" ou se o loop tiver chegado ao fim do array.
    *           - após isso, será feito outro loop FOR para multiplicar cada digito conforme a posição em que está no array
    *           - por exemplo: caso o usuário tenha digitado 2 numeros, a variável itera será igual a 1.
    *           - então o segundo FOR irá multiplicar o digito mais a direita por 1, depois multiplicar o segundo digito 
    *        por 10 e somar o resultado com o primeiro.
    *           
    */
    long int numero_transformado = 0;
    long int fator_de_multiplicacao[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
    int aux = 0, contador_do_fator = 9;

    //Adiciona o caracter digitado pelo usuário no array valor_Digitado***********************
    for (int itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {
        if (valor_digitado[itera] == '_') {
            valor_digitado[itera] = entrada;
            //Este switch é usado para converter o valor do tipo CHAR para LONG  INT
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
    //e armazena na variável numero_transformado.
    for (int itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {   //Percorre o array para verificar em qual dezena
        if (valor_digitado[itera] == '_' || itera == 9) {             //foi digitado o ultimo digito
            if (itera == 9) {                       //Verifica se foi digitado todos os 10 digitos                              
                for (aux = itera; aux >= 0; aux--) {
                    numero_transformado += tranforma_char_int[aux] * fator_de_multiplicacao[contador_do_fator];
                    contador_do_fator--;
                } 
                break;
            }
            else {    // Caso não tenha sido digitado 10 digitos, transforma os que foram digitados
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
        printf_s("\nusuário solicitou a operação SOMA\n");
        break;
    case 2:
        printf_s("\nusuário solicitou a operação SUBTRAÇÃO\n");
        break;
    case 3:
        printf_s("\nusuário solicitou a operação DIVISÃO\n");
        break;
    case 4:
        printf_s("\nusuário solicitou a operação MULTIPLICAÇÃO\n");
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